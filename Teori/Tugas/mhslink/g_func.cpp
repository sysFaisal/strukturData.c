#include <stdlib.h>
#include <string>
#include <fstream>
#include <stdbool.h>
#include "global_func.h"

using namespace std;

bool openFile(ifstream &File){
    return (File.is_open());
};

bool CekFileAll(int totalFileRead, int totalFileWrite, string readFile[], string writeFile[]){
    int counter = 0;
    for (counter = 0; counter < totalFileRead; counter++){
        ifstream Temp (readFile[counter]);
        if (!openFile(Temp)){
            cout << "nnn" ;
            return false;
        }
        Temp.close();
    };
    for (counter = 0; counter < totalFileWrite; counter++){
        ifstream Temp (writeFile[counter]);
        if (!openFile(Temp)){
            cout << "nnn" ;
            return false;
        };
        Temp.close();
    };
    return true;
};
