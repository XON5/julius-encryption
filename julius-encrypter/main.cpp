#include <iostream>
#include <fstream>
#include "encrypterclass.h"
using namespace std;

int main(int argc, char* argv[]) {
    
    if(argc < 2) {
        cerr << "Missing arguments! Check if these files exist:" << endl;
        cerr << argv[1] << " and " << argv[2] << endl;
        cerr << "Required: Input file, Output file, Output file 2." << endl;
        return 1;
    }
    
    ifstream inputFile;
    inputFile.open(argv[1]);
    
    if(inputFile.fail()) {
        cerr << "Cannot open input file. Check: " << argv[1] << "." << endl;
        return 2;
    }

    ofstream outputFile;
    outputFile.open(argv[2]);
    
    if(outputFile.fail()) {
        cerr << "Cannot open output file. Check: " << argv[2] << "." << endl;
        return 3;
    }
    
    Caesar myEncrypter(79);
    myEncrypter.shiftCharacters(inputFile, outputFile);
    cout << myEncrypter;
    
    inputFile.close();
    outputFile.close();
    
    return 0;
}