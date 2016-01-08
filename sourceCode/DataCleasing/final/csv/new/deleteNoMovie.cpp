//deleteNoMovie.cpp
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
    
    //string addre = "actorRowNoEnter.txt";
    //string newdata = "@@@@\n";
    string data;
    //string fileName;
    
    int lineNum = 0;
    int haveMovie = 0;
    int NotHaveMovie = 0;
    
    string fileName = "Directors.csv";
    string FinalList = "@@@@\n";
    string oneLineData;
    string moviePath = "Movie.csv";
    string movieData;
    int people = 0;
    
    ifstream fin(fileName.c_str());
    getline(fin, data, '\0');
    fin.close();
    
    ifstream finm(moviePath.c_str());
    getline(finm, movieData, '\0');
    finm.close();
    
    int point = 0;
    int pointS = 0;
    int pointE = 0;
    
    while(true){
        
        int getOneline = (int)data.find("\n");
        if(getOneline < 0) break;
        
        oneLineData = data.substr(0, getOneline + 1);
        data.erase(0, getOneline + 1);
        
        int whereEnter = (int)oneLineData.find("\n");
        point = pointE = pointS = whereEnter;
        
        //cout<< oneLineData;
        
        while(true){
            if((char)oneLineData[point] == '\"'){
                pointE = point;
                point--;
                break;
            }
            else{
                point--;
            }
        }
        
        
        
        while (true) {
            if((char)oneLineData[point] == '\"' && (char)oneLineData[point - 1] == ','){
                pointS = point + 1;
                break;
            }
            else{
                point--;
            }
        }
        
        //if(pointE < pointS)
        //    cout << pointS << "\t" << pointE << endl;
        string thisName = oneLineData.substr(pointS, pointE - pointS);
        if((int)movieData.find(thisName) >= 0){
            FinalList.insert((int)FinalList.find("@@@@"), oneLineData);
            haveMovie++;
        }
        else{
            NotHaveMovie++;
        }
        //cout << oneLineData.substr(pointS, pointE - pointS) << endl;
        point = pointE = pointS = 0;
    }
    
    
        
    FinalList.erase((int)FinalList.find("@@@@"), 5);
    
    //cout << FinalList << endl;
    cout << "Y: " << haveMovie << "\tN: " << NotHaveMovie << endl;
    
    ofstream fout("Directors_.txt");
    fout << FinalList;
    fout.close();
    
    
    return 0;
}


