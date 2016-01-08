//MatchFinal.cpp
//@author: Yibo YU, Rhett0905yb@gmail.com

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;


int main(void){
    
    string addActor1 = "../actors.list";
    string addActor2 = "../actresses.list";
    
    //string addNameList = "NameList.txt";
    //string addNameList = "NameListTestOne.txt";
    //string addNameList = "NameList100.txt";
    string addNameList = "NameListFinal2.txt";
    
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
    int matchYes = 0;
    int matchNo = 0;
    
    int finishNum = 0;
    
    ifstream finActor1(addActor1.c_str());
    getline(finActor1, tempData, '\0');
    finActor1.close();
    
    ifstream finActor2(addActor2.c_str());
    getline(finActor2, tempData, '\0');
    finActor2.close();
    
    while(true){
        
        point = (int)namelist.find("\n");
        if(point < 0) break;
        
        currentName = namelist.substr(0, point);
        namelist.erase(0, point + 1);
        
        //finalData.insert((int)finalData.find("@@@@"), "\n-----------------------------\n");
        //finalData.insert((int)finalData.find("@@@@"), currentName);
        //finalData.insert((int)finalData.find("@@@@"), ":\n");
        
        
        
        tempPoint = (int)tempData.find(currentName);
        if(tempPoint >= 0) matchORnot = 1;
        
        //cout << "------------Actor Finish.---------------" << endl;
        
        
        
        
        tempPoint = (int)tempData.find(currentName);
        if(tempPoint >= 0) matchORnot = 1;
        
        if(matchORnot == 0)
            matchNo++;
        else
            matchYes++;
        
        
        
        matchORnot = 0;
        
        finishNum++;
        cout << "~~~~~~~~~~ " << finishNum << " Finish.~~~~~~~~~~~~~" << endl;
        
        //break;
        //cout << currentName << endl;
        
    }
    
    finalData.erase((int)finalData.find("@@@@"), 4);
    
    cout << "Y: " << matchYes << "\t\t\tN: " << matchNo << endl;
    
    //cout << finalData << endl;
    
    //ofstream fout("MatchActor1.txt");
    //fout << finalData;
    //fout.close();
    
    return 0;
    
}