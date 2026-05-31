#ifndef _GetTanggal_H
#define _GetTanggal_H
#include <ios>
#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

inline string saferString(string text, int maxlength){

    if((int)text.length() > maxlength){
        text = text.substr(0,maxlength - 2) + "..";
        return text;
    };
    return text;
};

inline void printColumn(string text, int maxlength){
    if(maxlength > 2){
        cout << left
             << setw(maxlength)
             << saferString(text, maxlength - 1);
    }else{
        cout << left
            << setw(maxlength)
            << text;
    };
};

inline bool isDigit(string text, bool cekPanjang){
    if (text.empty()){
        return false;
    };

    if (cekPanjang && (int)text.length() > 9){
        return false;
    };


    int counter;
    for (counter = 0; counter < (int)text.length(); counter++){

        if (!(text[counter] >= '0' && text[counter] <= '9')){
            return false;
        };

    };
    return true;
};

inline string generateID(){
    srand(time(0));

    int number = rand() % 900000 + 100000;
    return "TRX" + to_string(number);
};


inline string getHours(){
    time_t now = time(0);
    tm *ltm = localtime(&now);

    string jam = to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min);

    return jam;
};

inline string getTanggal(){

    time_t now = time(0);
    tm *ltm = localtime(&now);

    string tanggal =
        to_string(ltm->tm_mday) + "/" +
        to_string(1 + ltm->tm_mon) + "/" +
        to_string(1900 + ltm->tm_year) + "," + getHours();

    return tanggal;
};


#endif
