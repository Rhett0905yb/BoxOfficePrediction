//rightStyle.cpp
//@author: Yibo YU, Rhett0905yb@gmail.com

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;


int main(void){
    
    string addre = "Director.txt";
    string data;
    string newdata = "@@@@@\n";
    string beta;
    string fileName;
    
    ifstream fin(addre.c_str());
    getline(fin, data, '\0');
    fin.close();
    
    int line = 0;
    int point = 160000000;
    int fileNum = 1;
    //int breakORnot = 0;
    
    //cout << "Fine Before while." << endl;
    
    while(true){
        int pointSpace = (int)data.find(" ");
        if(pointSpace < 0) break;
        data.replace(pointSpace, 1, "_");
        line++;
        cout << "1. " << line << endl;
    }
    
    while (true) {
        int pointCo2 = (int)data.find("\"");
        if(pointCo2 < 0) break;
        data.erase(pointCo2, 1);
        line++;
        cout << "2. " << line << endl;
    }
    
    while (true) {
        int pointCo1 = (int)data.find("'");
        if(pointCo1 < 0) break;
        data.erase(pointCo1, 1);
        line++;
        cout << "3. " << line << endl;
    }
    
    
    
    
    
    ofstream fout("Director_.txt");
    fout << data;
    fout.close();
    
    return 0;
}


