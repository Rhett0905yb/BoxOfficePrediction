//no3enter.cpp
//@author: Yibo YU, Rhett0905yb@gmail.com

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;


int main(void){
    
    //string namelist = "@@@@\n";
    string templist;
    //string FinalNameList = "@@@@\n";
    string addre = "MatchDirector.txt";
    
    ifstream fin(addre.c_str());
    getline(fin, templist, '\0');
    fin.close();
    
    //int pointS = 0;
    //int pointE = 0;
    //int pointM = 0;
    
    int point = 0;
    int i = 0;
    
    while (true) {
        point = (int)templist.find("\n\n\n");
        if(point < 0) break;
        templist.erase(point, 1);
        i++;
        cout << i << endl;
    }
    //namelist.erase((int)namelist.find("@@@@"), 5);
    
    //cout << namelist << endl;

    ofstream fout("MatchDirector_final.txt");
    fout << templist;
    fout.close();
    
    return 0;
    
}