#include "CanadaWinterGames2022.h"

using namespace std;
//Constructor of empty competitors list
CanadaWinterGames2022:: CanadaWinterGames2022(int referees, int competitors){
    this->competitorsList = new Competitor[competitors];
    for(int i = 0; i < competitors; ++i)
    {
        competitorsList[i].refereesScores = new float[referees];
        competitorsList[i].competitorName = "None";
    }
    this->competitorsAmount = competitors;
    this->competitorsCurrentAmount = 0;
    this->refereesAmount = referees;
    this->MeanArray = new float[referees];
    this->meanFlag = false;
}
//Function to set a new competitor and his grades
void CanadaWinterGames2022::setScore() {
    std::string name;
    int index = 0;
    cin >> name;
    if (name.length() > 18 || name.compare("mean")==0 || name.compare("cov")==0 || name.compare("None")==0) {
        cout << "ERROR: invalid input\n";
        return;
    }
    while (index < this->competitorsAmount) {
        if (this->competitorsList[index].competitorName.compare(name) == 0) {
            break;
        }
        else if(this->competitorsList[index].competitorName.compare("None") == 0){
            break;
        }
        index++;
    }
    string s, data;
    cin >> s;
    if (index == this->competitorsAmount){
        cout << "ERROR: MAX_ATHLETES exceeded\n";
        return;
    }
    for (size_t i=0; i<s.size();i++){
        if (isdigit(s.data()[i])==0 && s.data()[i]!='.' && s.data()[i]!=','){
            cout << "ERROR: invalid input\n";
            return;
        }
    }
    if(this->competitorsList[index].competitorName.compare("None") == 0){
        this->competitorsList[index].competitorName = name;
    }
    float arr[this->refereesAmount];
    int start = 0;
    int end = s.find(",");
    int j = 0;
    while (end != -1) {
        data = s.substr(start, end - start);
        arr[j] = strtof(data.c_str(),NULL);
        start = end + 1;
        end = s.find(",", start);
        j++;
    }
    data = s.substr(start, end - start);
    arr[j] = strtof(data.c_str(),NULL);
    if (j >= this->refereesAmount){
        cout << "ERROR: invalid input\n";
        return;
    }
    for (int i=0; i<j+1;i++) {
        this->competitorsList[index].refereesScores[i] = arr[i];
    }
    this->competitorsCurrentAmount++;
    this->meanFlag = true;
}
//Function to gets the competitor scores by his name
void CanadaWinterGames2022::getScore() const{
    std::string name;
    int index = 0;
    cin >> name;
    while (index < this->competitorsAmount) {
        if (this->competitorsList[index].competitorName.compare(name) == 0) {
            break;
        }
        index++;
    }
    if (index == this->competitorsAmount){
        cout << "ERROR: " << name << " does not exist\n";
        return;
    }
    cout << this->competitorsList[index].competitorName << "=[";
    for (int i=0 ; i<this->refereesAmount; i++){
        cout << roundf((this->competitorsList[index].refereesScores[i])*100)/100;
        if(i<this->refereesAmount-1)
            cout << ",";
    }
    cout << "]\n";
}
//Function to gets competitor's average score
void CanadaWinterGames2022::getAverage() const{
    std::string name;
    int index = 0;
    float sum = 0;
    cin >> name;
    while (index < this->competitorsCurrentAmount) {
        if (this->competitorsList[index].competitorName.compare(name) == 0) {
            break;
        }
        index++;
    }
    if (index == this->competitorsCurrentAmount){
        cout << "ERROR: " << name << " does not exist\n";
        return;
    }
    cout << this->competitorsList[index].competitorName << ", ";
    for (int i=0 ; i<this->refereesAmount; i++){
        sum += this->competitorsList[index].refereesScores[i];
    }
    sum = sum/this->refereesAmount;
    cout << roundf(sum*100)/100 << "\n";
}
//Function to gets all the competitors average scores
void CanadaWinterGames2022::getSummary() const{
    int index = 0;
    float sum = 0;
    while (index < this->competitorsCurrentAmount && this->competitorsList[index].competitorName != "None" ){
        for (int i=0 ; i<this->refereesAmount; i++){
            sum += this->competitorsList[index].refereesScores[i];
        }
        cout << this->competitorsList[index].competitorName << ", ";
        sum = sum / this->refereesAmount;
        cout << roundf(sum*100)/100 << "\n";
        sum = 0;
        index++;
    }
    if (index == 0){
        cout << "ERROR: no records in the system\n";
        return;
    }
}
//Private functions to calculate the mean vector of the competitors scores
void CanadaWinterGames2022::updateMeanArray(){
    float refereeScores[this->refereesAmount][this->competitorsCurrentAmount];
    for (int i=0 ; i<this->refereesAmount; i++){
        for (int j=0 ; j<this->competitorsCurrentAmount; j++){
            refereeScores[i][j] = this->competitorsList[j].refereesScores[i];
        }
    }
    for(int i=0 ; i<this->refereesAmount; i++){
        for (int j=0 ; j<this->competitorsCurrentAmount; j++){
            MeanArray[i] += refereeScores[i][j];
        }
        MeanArray[i] = MeanArray[i] / this->competitorsCurrentAmount;
    }
    this->meanFlag = false;
}
//Functions that prints the mean vector
void CanadaWinterGames2022::getMean(){
    if (this->competitorsList[0].competitorName.compare("None") == 0){
        cout << "ERROR: no records in the system\n";
        return;
    }
    if (this->meanFlag == true){
        updateMeanArray();
    }
    cout << "mean=[";
    for(int i=0 ; i<this->refereesAmount; i++){
        cout << roundf(this->MeanArray[i]*100)/100;
        if(i < this->refereesAmount-1)
            cout << ",";
    }
    cout << "]\n";
}
//Function that calculate and prints the covariance matrix
void CanadaWinterGames2022::getVariance() {
    if (this->competitorsList[0].competitorName.compare("None") == 0){
        cout << "ERROR: no records in the system\n";
        return;
    }
    float covarianceMatrix[this->refereesAmount][this->refereesAmount];
    float sum = 0;
    if (this->meanFlag == true){
        updateMeanArray();
    }
    cout << "cov=[\n";
    for (int i=0; i<this->refereesAmount; i++){
        for (int j=0; j<this->refereesAmount; j++){
            for (int k=0; k<this->competitorsCurrentAmount; k++) {
                sum += ((this->competitorsList[k].refereesScores[i] - this->MeanArray[i])*(this->competitorsList[k].refereesScores[j] - this->MeanArray[j]));
            }
            if(this->competitorsCurrentAmount == 1){
                covarianceMatrix[i][j] = sum;
            }
            else{
                covarianceMatrix[i][j] = sum / (this->competitorsCurrentAmount-1);
            }
            sum = 0;
            cout << roundf(covarianceMatrix[i][j]*100)/100;
            if(j < this->refereesAmount-1)
                cout << ",";
        }
        cout << "\n";
    }
    cout << "]\n";
}
//The main function of the program
int main(int argc, char** argv)
{
    string a = argv[1];
    string b = argv[2];
    for (size_t i=0;i<a.size();i++){
        if(!isdigit(argv[1][i])){
            cout << "ERROR: USAGE " << argv[0] <<" NUM_REFEREES MAX_ATHLETES";
            exit(0);
        }
    }
    for (size_t i=0;i<b.size();i++){
        if(!isdigit(argv[2][i])){
            cout << "ERROR: USAGE " << argv[0] <<" NUM_REFEREES MAX_ATHLETES";
            exit(0);
        }
    }
    CanadaWinterGames2022 x = CanadaWinterGames2022(atoi(argv[1]),atoi(argv[2]));
    int command = -1;
    //cout << "[0]Exit\n[1]Set score to a competitor\n[2]Get score of a competitor\n[3]Get average score of a competitor\n[4]Print a summary of the competitors' scoring averages\n[5]Print the referees scoring mean\n[6]Print the common variance matrix\n";
    while (command != 0){
        cin >> command;
        if (command == 0)
            exit(0);
        else if(command == 1)
            x.setScore();
        else if(command == 2)
            x.getScore();
        else if(command == 3)
            x.getAverage();
        else if(command == 4)
            x.getSummary();
        else if(command ==5)
            x.getMean();
        else if(command == 6)
            x.getVariance();
        else{
            cout << "ERROR: invalid command; type 0 for exit\n";
        }
    }
    return 0;
}
