//3DataSet1.cpp
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
    
    string addre = "actors6.txt";
    string dataFile;
    string newdata = "@@@@@\n";
    string beta;
    string fileName;
    
    ifstream fin(addre.c_str());
    getline(fin, dataFile, '\0');
    fin.close();
    
    int line = 0;
    int point = 30000000;
    int fileNum = 1;
    //int breakORnot = 0;
    
    cout << "Fine Before while." << endl;
    
    while(true){
        
        /*point = (int)dataFile.find("\n");
        if(point < 0) break;
        beta = dataFile.substr(0, point);
        dataFile.erase(0, point + 1);
        line++;
        
        newdata.insert((int)newdata.find("@@@@@"), beta);
        
        if(line % 1000 == 0) cout << line << endl;
        
        if(line > 3000000){
            
            fileName = (char)fileNum + ".txt";
            ofstream fout(fileName);
            fout << newdata;
            fout.close();
            
            fileNum++;
            line = 0;
            newdata = "@@@@@";*/
        
        if((int)dataFile.find("\n") < 0) break;
        if(dataFile.length() < point)
            point = dataFile.length();
        while(true){
            if((char)dataFile[point] == '\n')
                break;
            else
                point++;
        }
        
        cout << fileNum << endl;
        
        beta = dataFile.substr(0, point);
        cout << "Copy Finish." << endl;
        dataFile.erase(0, point + 1);
        cout << "Delete Finish." << endl;
        
        newdata.insert((int)newdata.find("@@@@@"), beta);
        cout << "Insert Finish." << endl;
        
        ostringstream ss;
        ss << fileNum;
        //fileName = ss.str();
        fileName = "actors6_" + ss.str() + ".txt";
        ofstream fout(fileName);
        fout << newdata;
        fout.close();
        fileNum++;
        newdata = "@@@@@";
        point = 30000000;
        
            
    }
    
    
    
    
    
    //ofstream fout("actresses.txt");
    //fout << dataFile;
    //fout.close();
    
    return 0;
}


