//sureNOrubbish.cpp
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
    
    int p = 0;
    int isname = 0;
    int lineNum = 0;
    int fileNum = 0;
    //ostringstream ss;
    string fileName;
    string FinalList = "@@@@\n";
    int people = 0;
    
    while(true){
        
        fileNum++;
        ostringstream sss;
        sss << fileNum;
        //fileName = ss.str() + ".txt";
        fileName = "1_Final.txt";
        
        ifstream fin(fileName.c_str());
        getline(fin, data, '\0');
        fin.close();
        
        int point = 0;
        int pointS = 0;
        int pointE = 0;
        string FinalData = "@@@@\n";
        string actor;
        string tempMovie = "~~~~";
        
        while(true){
            
            if((char)data[point] == '@')
                if((char)data[point + 1] == '@')
                    if((char)data[point + 2] == '@')
                        if((char)data[point + 3] == '@')
                            break;
            
            if((char)data[point] == '-'){
                while(true){
                    if((char)data[point] == '\n'){
                        point++;
                        break;
                    }
                    else{
                        point++;
                    }
                }
            }
            else if((char)data[point] == '\t'){
                //string tempPlace = "~~~~";
                pointE = pointS = point + 3;
                while(true){
                    if((char)data[pointE] == '('){
                        pointE--;
                        break;
                    }
                    else{
                        pointE++;
                    }
                }
                string oneData = data.substr(pointS, pointE - pointS);
                if((int)tempMovie.find(oneData) < 0){
                    tempMovie.insert((int)tempMovie.find("~~~~"), oneData);
                    tempMovie.insert((int)tempMovie.find("~~~~"), " ");
                    //cout << actor << "\t" << oneData << endl;
                    FinalList.insert((int)FinalList.find("@@@@"), actor);
                    FinalList.insert((int)FinalList.find("@@@@"), "\t\t\t");
                    FinalList.insert((int)FinalList.find("@@@@"), oneData);
                    FinalList.insert((int)FinalList.find("@@@@"), "\n");
                }
                
                while(true){
                    if((char)data[pointE] == '\n'){
                        pointE++;
                        point = pointE;
                        break;
                    }
                    else{
                        pointE++;
                    }
                }
            }
            else{
                pointE = pointS = point;
                while(true){
                    if((char)data[pointE] == ':'){
                        pointE--;
                        break;
                    }
                    else{
                        //cout << "1" << endl;
                        pointE++;
                    }
                }
                actor = data.substr(pointS, pointE - pointS + 1);
                //cout << actor << "\t";
                cout << actor << " " << ++people << endl;
                point = pointE + 3;
                tempMovie = "~~~~";
            }
            
            
        }
        
        break;
        
    }
    FinalList.erase((int)FinalList.find("@@@@"), 5);
    
    ofstream fout("actors.txt");
    fout << FinalList;
    fout.close();
    
    
    return 0;
}


