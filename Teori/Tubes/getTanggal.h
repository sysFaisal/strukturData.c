#ifndef _StackHistory_H
#define _StackHistory_H
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

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