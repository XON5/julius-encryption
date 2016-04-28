#include "encrypterclass.h"
using namespace std;

Caesar::Caesar() {
    fShiftByValue = 4;
    for(int i = 0; i < 26; i++) {
        fCharacterFrequenciesBefore[i] = 0;
        fCharacterFrequenciesAfter[i] = 0;
    }
}

Caesar::Caesar(int shiftValue) {
    fShiftByValue = shiftValue;
    for(int i = 0; i < 26; i++) {
        fCharacterFrequenciesBefore[i] = 0;
        fCharacterFrequenciesAfter[i] = 0;
    }
}

void Caesar::shiftCharacters(std::ifstream& aInput, std::ofstream& aOutput) {
    char lOldChar = aInput.get();
    char lNewChar;
    
    while(aInput.good()) {
        if(isalpha(lOldChar)) {
            bool lLower = (islower(lOldChar));
            lOldChar = toupper(lOldChar);
            fCharacterFrequenciesBefore[lOldChar - 'A']++;
            lNewChar = 'A' + ((lOldChar - 'A' + fShiftByValue) % 26);
            fCharacterFrequenciesAfter[lNewChar - 'A']++;
            if(lLower) {
                lNewChar = tolower(lNewChar);
            }
            aOutput << lNewChar;
        } else {
            aOutput << lOldChar;
        }
        lOldChar = aInput.get();
    }
}

std::ostream& operator<<(std::ostream& aOStream, const Caesar& aEncrypter) {
    aOStream << "Characters have been shifted by: " << aEncrypter.fShiftByValue << " places. Frequencies below (before, after): " << endl;
    
    //For all letters in the alphabet
    for(int i = 0; i < 26; i++) {
        //List the characters of alphabet (ASCII values - A = 65, B = 66 ...) and the frequencies
        aOStream << (char)(i + 65) << ": " << aEncrypter.fCharacterFrequenciesBefore[i] << ", " << aEncrypter.fCharacterFrequenciesAfter[i] << endl;
    }
    
    return aOStream;
}