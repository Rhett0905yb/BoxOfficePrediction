//MatchFinal.cpp
//@author: Yibo YU, Rhett0905yb@gmail.com

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;


int main(void){
    
    string addDirector1 = "../directors_1.txt";
    string addDirector2 = "../directors_2.txt";
    string addDirector3 = "../directors_3.txt";
    string addDirector4 = "../directors_4.txt";
    string addDirector5 = "../directors_5.txt";
    string addDirector6 = "../directors_6.txt";
    
    //string addNameList = "NameList.txt";
    //string addNameList = "NameListTestOne.txt";
    //string addNameList = "NameList100.txt";
    string addNameList = "../nameProcess/DirectorListFinal2_4.txt";
    
    string namelist;
    string currentName;
    
    string finalData = "@@@@";
    
    ifstream fin(addNameList.c_str());
    getline(fin, namelist, '\0');
    fin.close();
    
    int point = 0;
    string tempData;
    int tempPoint = 0;
    int matchORnot = 0;
    
    int finishNum = 0;
    
    while(true){
        
        point = (int)namelist.find("\n");
        if(point < 0) break;
        
        currentName = namelist.substr(0, point);
        namelist.erase(0, point + 1);
        
        finalData.insert((int)finalData.find("@@@@"), "\n-----------------------------\n");
        finalData.insert((int)finalData.find("@@@@"), currentName);
        finalData.insert((int)finalData.find("@@@@"), ":\n");
        
        ifstream finDirector1(addDirector1.c_str());
        getline(finDirector1, tempData, '\0');
        finDirector1.close();
        
        tempPoint = (int)tempData.find(currentName);
        if(tempPoint >= 0) matchORnot = 1;
        while(tempPoint > 0){
            
            int startP = tempPoint;
            int endP = tempPoint;
            
            if((char)tempData[startP - 1] != '\n'){
                while(true){
                    if((char)tempData[startP] == '\n'){
                        startP++;
                        break;
                    }
                    else
                        startP--;
                }
                while (true) {
                    if((char)tempData[endP] == '\n'){
                        endP++;
                        break;
                    }
                    else
                        endP++;
                }
            }
            else{
                while (true) {
                    if((char)tempData[endP] == '\n'){
                        endP++;
                        if((char)tempData[endP] == '\n'){
                            endP++;
                            break;
                        }
                    }
                    else
                        endP++;
                }
            }
            
            string oneLineData = tempData.substr(startP, endP - startP);
            tempData.erase(startP, endP - startP);
            finalData.insert((int)finalData.find("@@@@"), oneLineData);
            //finalData.insert((int)finalData.find("@@@@"), "\n");
            
            tempPoint = (int)tempData.find(currentName);
        }
        cout << "------------Director1 Finish.---------------" << endl;
        
        
        ifstream finDirector2(addDirector2.c_str());
        getline(finDirector2, tempData, '\0');
        finDirector2.close();
        
        tempPoint = (int)tempData.find(currentName);
        if(tempPoint >= 0) matchORnot = 1;
        while(tempPoint > 0){
            
            int startP = tempPoint;
            int endP = tempPoint;
            
            if((char)tempData[startP - 1] != '\n'){
                while(true){
                    if((char)tempData[startP] == '\n'){
                        startP++;
                        break;
                    }
                    else
                        startP--;
                }
                while (true) {
                    if((char)tempData[endP] == '\n'){
                        endP++;
                        break;
                    }
                    else
                        endP++;
                }
            }
            else{
                while (true) {
                    if((char)tempData[endP] == '\n'){
                        endP++;
                        if((char)tempData[endP] == '\n'){
                            endP++;
                            break;
                        }
                    }
                    else
                        endP++;
                }
            }
            
            string oneLineData = tempData.substr(startP, endP - startP);
            tempData.erase(startP, endP - startP);
            finalData.insert((int)finalData.find("@@@@"), oneLineData);
            //finalData.insert((int)finalData.find("@@@@"), "\n");
            
            tempPoint = (int)tempData.find(currentName);
        }
        cout << "------------Director2 Finish.---------------" << endl;
        
        
        ifstream finDirector3(addDirector3.c_str());
        getline(finDirector3, tempData, '\0');
        finDirector3.close();
        
        tempPoint = (int)tempData.find(currentName);
        if(tempPoint >= 0) matchORnot = 1;
        while(tempPoint > 0){
            
            int startP = tempPoint;
            int endP = tempPoint;
            
            if((char)tempData[startP - 1] != '\n'){
                while(true){
                    if((char)tempData[startP] == '\n'){
                        startP++;
                        break;
                    }
                    else
                        startP--;
                }
                while (true) {
                    if((char)tempData[endP] == '\n'){
                        endP++;
                        break;
                    }
                    else
                        endP++;
                }
            }
            else{
                while (true) {
                    if((char)tempData[endP] == '\n'){
                        endP++;
                        if((char)tempData[endP] == '\n'){
                            endP++;
                            break;
                        }
                    }
                    else
                        endP++;
                }
            }
            
            string oneLineData = tempData.substr(startP, endP - startP);
            tempData.erase(startP, endP - startP);
            finalData.insert((int)finalData.find("@@@@"), oneLineData);
            //finalData.insert((int)finalData.find("@@@@"), "\n");
            
            tempPoint = (int)tempData.find(currentName);
        }
        cout << "------------Director3 Finish.---------------" << endl;
        
        ifstream finDirector4(addDirector4.c_str());
        getline(finDirector4, tempData, '\0');
        finDirector4.close();
        
        tempPoint = (int)tempData.find(currentName);
        if(tempPoint >= 0) matchORnot = 1;
        while(tempPoint > 0){
            
            int startP = tempPoint;
            int endP = tempPoint;
            
            if((char)tempData[startP - 1] != '\n'){
                while(true){
                    if((char)tempData[startP] == '\n'){
                        startP++;
                        break;
                    }
                    else
                        startP--;
                }
                while (true) {
                    if((char)tempData[endP] == '\n'){
                        endP++;
                        break;
                    }
                    else
                        endP++;
                }
            }
            else{
                while (true) {
                    if((char)tempData[endP] == '\n'){
                        endP++;
                        if((char)tempData[endP] == '\n'){
                            endP++;
                            break;
                        }
                    }
                    else
                        endP++;
                }
            }
            
            string oneLineData = tempData.substr(startP, endP - startP);
            tempData.erase(startP, endP - startP);
            finalData.insert((int)finalData.find("@@@@"), oneLineData);
            //finalData.insert((int)finalData.find("@@@@"), "\n");
            
            tempPoint = (int)tempData.find(currentName);
        }
        cout << "------------Director4 Finish.---------------" << endl;
        
        ifstream finDirector5(addDirector5.c_str());
        getline(finDirector5, tempData, '\0');
        finDirector5.close();
        
        tempPoint = (int)tempData.find(currentName);
        if(tempPoint >= 0) matchORnot = 1;
        while(tempPoint > 0){
            
            int startP = tempPoint;
            int endP = tempPoint;
            
            if((char)tempData[startP - 1] != '\n'){
                while(true){
                    if((char)tempData[startP] == '\n'){
                        startP++;
                        break;
                    }
                    else
                        startP--;
                }
                while (true) {
                    if((char)tempData[endP] == '\n'){
                        endP++;
                        break;
                    }
                    else
                        endP++;
                }
            }
            else{
                while (true) {
                    if((char)tempData[endP] == '\n'){
                        endP++;
                        if((char)tempData[endP] == '\n'){
                            endP++;
                            break;
                        }
                    }
                    else
                        endP++;
                }
            }
            
            string oneLineData = tempData.substr(startP, endP - startP);
            tempData.erase(startP, endP - startP);
            finalData.insert((int)finalData.find("@@@@"), oneLineData);
            //finalData.insert((int)finalData.find("@@@@"), "\n");
            
            tempPoint = (int)tempData.find(currentName);
        }
        cout << "------------Director5 Finish.---------------" << endl;
        
        ifstream finDirector6(addDirector6.c_str());
        getline(finDirector6, tempData, '\0');
        finDirector6.close();
        
        tempPoint = (int)tempData.find(currentName);
        if(tempPoint >= 0) matchORnot = 1;
        while(tempPoint > 0){
            
            int startP = tempPoint;
            int endP = tempPoint;
            
            if((char)tempData[startP - 1] != '\n'){
                while(true){
                    if((char)tempData[startP] == '\n'){
                        startP++;
                        break;
                    }
                    else
                        startP--;
                }
                while (true) {
                    if((char)tempData[endP] == '\n'){
                        endP++;
                        break;
                    }
                    else
                        endP++;
                }
            }
            else{
                while (true) {
                    if((char)tempData[endP] == '\n'){
                        endP++;
                        if((char)tempData[endP] == '\n'){
                            endP++;
                            break;
                        }
                    }
                    else
                        endP++;
                }
            }
            
            string oneLineData = tempData.substr(startP, endP - startP);
            tempData.erase(startP, endP - startP);
            finalData.insert((int)finalData.find("@@@@"), oneLineData);
            //finalData.insert((int)finalData.find("@@@@"), "\n");
            
            tempPoint = (int)tempData.find(currentName);
        }
        cout << "------------Director6 Finish.---------------" << endl;
        
        
        
        if(matchORnot == 0)
            finalData.insert((int)finalData.find("@@@@"), "N/A\n");
        matchORnot = 0;
        
        finishNum++;
        cout << "~~~~~~~~~~ " << finishNum << " Finish.~~~~~~~~~~~~~" << endl;
        
        //break;
        //cout << currentName << endl;
        
    }
    
    finalData.erase((int)finalData.find("@@@@"), 4);
    
    
    //cout << finalData << endl;
    
    ofstream fout("MatchDirector4.txt");
    fout << finalData;
    fout.close();
    
    return 0;
    
}