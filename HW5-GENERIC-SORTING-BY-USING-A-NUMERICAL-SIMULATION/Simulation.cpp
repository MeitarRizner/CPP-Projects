#include "Simulation.h"

//Constructor - reads the file and creates a new Container. Shows an exception if caught.
Simulation::Simulation(int argc, char **argv) {
    double** vectors;
    try{
        vectors = getFiles(argc, argv);
    }
    catch (InputFileError& e){
        cerr << "ERROR: "<< argv[1] << " does not exist or cannot be opened\n";
        exit(1);
    }
    catch (OutputFileError& e){
        cerr << "ERROR: "<< argv[2] << " does not exist or cannot be opened\n";
        exit(1);
    }
    catch (RegularWrongInput& e){
        cerr << "ERROR: simulation definition in " << argv[1] << " is invalid\n";
        exit(1);
    }
    catch (WrongInput& e){
        e.PrintError();
        exit(1);
    }
    this->population = new Container<double>(this->n,this->m,this->populationSize);
    this->population->setVariableVects(vectors);
    this->population = setTargetVectors(this->population,this->populationSize);
}

//This function calculates the targets vectors for each element and sets them in the container
Container<double>* Simulation::setTargetVectors(Container<double>* cont, int numberOfElements) const {
    double** targetVectors = new double*[numberOfElements];
    double* vect = NULL;
    int e = 1;
    for (int i=0; i<numberOfElements; i++){
        targetVectors[i] = new double[this->m];
        vect = cont->getVariableVect(i);
        for (int j=0; j<this->m; j++){
            targetVectors[i][j] = 0;
            for (int k=0; k<this->n; k++){
                targetVectors[i][j] += ((vect[k] - e)*(vect[k] - e));
            }
            e++;
        }
        e = 1;
    }
    cont->setTargetVects(targetVectors);
    return cont;
}

//This function manages all the simulation, executes as required.
void Simulation::startSimulation() {
    Container<double>* cont = new Container<double>(this->n,this->m,2*this->populationSize);
    double** vectors = new double*[2*this->populationSize];
    int timeCounter = 0;
    srand(time(NULL));
    for (int i=0; i<this->populationSize; i++){
        vectors[i] = this->population->getVariableVect(i);
    }
    while (timeCounter < this->timeSteps){
        for (int i=this->populationSize; i<2*this->populationSize; i++){
            vectors[i] = new double [this->n];
            for (int j=0; j<this->n; j++){
                vectors[i][j] = (double)rand() / (double)RAND_MAX;
                vectors[i][j] += vectors[i-this->populationSize][j];
            }
        }
        cont->setVariableVects(vectors);
        cont = setTargetVectors(cont,2*this->populationSize);
        cont->ParetoSorting(cont->getElemPool(),2*this->populationSize);
        timeCounter++;
    }
    for (int i=0; i<this->populationSize; i++){
        this->population->getElemPool()[i] = cont->getElemPool()[i];
    }
    printResults();
}

//This function prints the targets vectors
void Simulation::printResults() const {
    ofstream output(this->outputFile.c_str());
    if (!output) {
        throw OutputFileError();
    }
    Element<double>** eleList = this->population->getElemPool();
    double* targetVect = NULL;
    for (int i=0; i<this->populationSize; i++){
        targetVect = eleList[i]->getTargetVect();
        for(int j=0; j<this->m; j++){
            output << setprecision(6) << targetVect[j];
            if (j != this->m -1)
                output << " ";
        }
        if (i != this->populationSize -1)
            output << "\n";
    }
}

//This function reads the input files, builds and returns the variables vectors array
double** Simulation::getFiles(int argc , char* argv []) {
    ifstream input(argv[1]);
    if (!input) {
        throw InputFileError();
    }
    this->outputFile = argv[2];
    string line, num;
    bool FirstLineFlag = false;
    int j = 0, i = 0;
    int lst[4];
    double **vectors;
    while (getline(input, line)) {
        if (!FirstLineFlag) {
            for (unsigned int n = 0; n < line.size(); n++) {
                if (line[n] != ' ') {
                    if (isdigit(line[n]) != 1)
                        throw RegularWrongInput();
                    num += line[n];
                    if (n == line.size() - 1) {
                        lst[i] = atoi(num.c_str());
                        num = "";
                    }
                } else {
                    lst[i] = atoi(num.c_str());
                    num = "";
                    i++;
                }
            }
            if (i != 3)
                throw RegularWrongInput();
            FirstLineFlag = true;
            i = 0;
            this->populationSize = lst[0];
            this->n = lst[1];
            this->m = lst[2];
            if (this->m > this->n){
                throw RegularWrongInput();
            }
            this->timeSteps = lst[3];
            vectors = new double *[this->populationSize];
            continue;
        } else {
            vectors[i] = new double[this->n];
            for (unsigned int n = 0; n < line.size(); n++) {
                if (line[n] != ' ') {
                    num += line[n];
                    if (n == line.size() - 1) {
                        vectors[i][j] = atof(num.c_str());
                        num = "";
                    }
                }
                else {
                    vectors[i][j] = atof(num.c_str());
                    num = "";
                    j++;
                }
                if (j > this->n-1){
                    throw WrongInput(i+2,argv[1]);
                }
            }
        }
        j = 0;
        i++;
    }
    return vectors;
}
