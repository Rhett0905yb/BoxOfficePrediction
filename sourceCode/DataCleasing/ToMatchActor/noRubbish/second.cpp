//second.cpp
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
    string tempList = "@@@@\n";
    int num = 0;
    
    fileName = "222222222222222.txt";
    
    ifstream fin(fileName.c_str());
    getline(fin, data, '\0');
    fin.close();
    
    int point = 0;
    int pointS = 0;
    int pointE = 0;
    int pointNS = 0;
    int pointNE = 0;
    
    while(true){
        if((char)data[point] == '@')
            if((char)data[point + 1] == '@')
                if((char)data[point + 2] == '@')
                    if((char)data[point + 3] == '@')
                        break;
        
        pointS = pointE = pointNE = pointNS = point;
        if((char)data[point] == '-' && (char)data[point + 1] == '-' && (char)data[point + 2] == '-'){
            pointS = point;
            while(true){
                if((char)data[point] == '\n'){
                    point++;
                    break;
                }
                else{
                    point++;
                }
            }
            pointNS = point;
            
            while(true){
                if((char)data[point] == ':' && (char)data[point + 1] == '\n'){
                    break;
                }
                else{
                    point++;
                }
            }
            pointNE = point;
            string nameTemp = data.substr(pointNS, pointNE - pointNS + 1);
            if((int)tempList.find(nameTemp) < 0){
                tempList.insert((int)tempList.find("@@@@"), nameTemp);
                tempList.insert((int)tempList.find("@@@@"), "\n");
            }
            else{
                num++;
                while(true){
                    if((char)data[point] == '\n' && (char)data[point + 1] == '-' && (char)data[point + 2] == '-'){
                        break;
                    }
                    else{
                        point++;
                    }
                }
                pointE = point;
                cout << "QQQQQQ" << endl << data.substr(pointS, pointE - pointS) << "WWWWWW" << endl;
                data.erase(pointS, pointE - pointS);
                point = pointS;
            }
            
            
            
        }
        else{
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
        
        
        
    }
    
    
    
    
    
    
    
    
    //FinalList.erase((int)FinalList.find("@@@@"), 5);
    
    ofstream fout("3333333333333333.txt");
    fout << data;
    fout.close();
    cout << endl << num << endl;
    
    return 0;
}


