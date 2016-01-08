//deleteMore.cpp
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
    
    string addre = "directorsRowNoEnter.txt";
    string newdata = "@@@@\n";
    string data;
    //string fileName;
    
    ifstream fin(addre.c_str());
    getline(fin, data, '\0');
    fin.close();
    
    int p = 0;
    int isname = 0;
    int lineNum = 0;
    int fileNum = 0;
    //ostringstream ss;
    string fileName;
    
    while(true){
        
        p = (int)data.find("\n");
        if(p < 0) break;
        if((char)data[0] == '-'){
            newdata.insert((int)newdata.find("@@@@"), data.substr(0, p + 1));
            isname = 1;
            data.erase(0, p + 1);
        }
        else if((char)data[0] == '\t'){
            newdata.insert((int)newdata.find("@@@@"), data.substr(0, p + 1));
            isname = 0;
            data.erase(0, p + 1);
        }
        else if(isname == 1){
            newdata.insert((int)newdata.find("@@@@"), data.substr(0, p + 1));
            isname = 0;
            data.erase(0, p + 1);
        }
        else{
            isname = 0;
            data.erase(0, p + 1);
        }
        
        lineNum++;
        if(lineNum % 500 == 0)
            cout << lineNum << endl;
        if(lineNum % 10000 == 0){
            fileNum++;
            ostringstream ss;
            ss << fileNum;
            fileName = "./noRubbish/" + ss.str() + ".txt";
            newdata.erase((int)newdata.find("@@@@"), 5);
            ofstream fout(fileName);
            fout << newdata;
            fout.close();
            newdata = "@@@@\n";
        }
        
        //if(lineNum > 10000) break;
        
    }
    fileNum++;
    ostringstream ss;
    ss << fileNum;
    fileName = "./noRubbish/" + ss.str() + ".txt";
    newdata.erase((int)newdata.find("@@@@"), 5);
    ofstream fout(fileName);
    fout << newdata;
    fout.close();
    
    
    
    
    
    return 0;
}


