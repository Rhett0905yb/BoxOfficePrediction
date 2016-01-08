//first.cpp
//@author: Yibo YU, Rhett0905yb@gmail.com
//no blank data

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;


int main(void){
    
    
    string data;
    
    string fileName;
    string FinalList = "@@@@\n";
    int num = 0;
    
    while(true){
        
        //fileNum++;
        //ostringstream sss;
        //sss << fileNum;
        //fileName = ss.str() + ".txt";
        fileName = "12333333333.txt";
        
        
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
            
            point = (int)data.find(":\n------");
            if(point < 0) break;
            
            num++;
            pointS = pointE = point;
            
            while(true){
                if((char)data[pointS] == '\n'){
                    pointS--;
                    while(true){
                        if((char)data[pointS] == '\n'){
                            break;
                        }
                        else{
                            pointS--;
                        }
                    }
                    break;
                }
                else{
                    pointS--;
                }
            }
            
            while (true) {
                if((char)data[pointE] == '\n'){
                    break;
                }
                else{
                    pointE++;
                }
            }
            
            cout << data.substr(pointS, pointE - pointS);
            data.erase(pointS, pointE - pointS);
        }
        
        while(true){
            int find_ = data.find("------------------------------");
            if(find_ < 0) break;
            
            int point_S = find_ + 29;
            int point_E = point_S;
            
            while(true){
                if((char)data[point_E] == '\n'){
                    break;
                }
                else{
                    point_E++;
                }
            }
            cout << endl << data.substr(point_S, point_E - point_S) << endl;
            data.erase(point_S, point_E - point_S);
            
        }
        
        
        
        
        
        break;
        
    }
    //FinalList.erase((int)FinalList.find("@@@@"), 5);
    
    ofstream fout("222222222222222.txt");
    fout << data;
    fout.close();
    cout << endl << num << endl;
    
    return 0;
}


