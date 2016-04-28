#pragma once
#include <iostream>
#include <fstream>

class Caesar {
private:
    int fCharacterFrequenciesBefore[26];
    int fCharacterFrequenciesAfter[26];
    int fShiftByValue;
    
public:
    Caesar(); //Default Shifter (+4)
    Caesar(int shiftValue); //Custom Shifter (+n)
    void shiftCharacters(std::ifstream& aInput, std::ofstream& aOuput);
    friend std::ostream& operator<<(std::ostream& aOStream, const Caesar& aEncrypter);
    
};