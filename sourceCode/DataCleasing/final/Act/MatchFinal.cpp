//MatchFinal.cpp
//@author: Yibo YU, Rhett0905yb@gmail.com

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;


int main(void){
    
    string addActor1 = "../matchHowMuch/actors_1.txt";
    string addActor2 = "../matchHowMuch/actors_2.txt";
    string addActor3 = "../matchHowMuch/actors_3.txt";
    string addActor4 = "../matchHowMuch/actors_4.txt";
    string addActor5 = "../matchHowMuch/actors_5.txt";
    string addActor6 = "../matchHowMuch/actors_6.txt";
    string addActor7 = "../matchHowMuch/actors_7.txt";
    string addActresses1 = "../matchHowMuch/actresses_1.txt";
    string addActresses2 = "../matchHowMuch/actresses_2.txt";
    string addActresses3 = "../matchHowMuch/actresses_3.txt";
    string addActresses4 = "../matchHowMuch/actresses_4.txt";
    string addActresses5 = "../matchHowMuch/actresses_5.txt";
    string addActresses6 = "../matchHowMuch/actresses_6.txt";
    string addActresses7 = "../matchHowMuch/actresses_7.txt";
    string addActresses8 = "../matchHowMuch/actresses_8.txt";
    
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
    
    int finishNum = 0;
    
    while(true){
        
        point = (int)namelist.find("\n");
        if(point < 0) break;
        
        currentName = namelist.substr(0, point);
        namelist.erase(0, point + 1);
        
        finalData.insert((int)finalData.find("@@@@"), "\n-----------------------------\n");
        finalData.insert((int)finalData.find("@@@@"), currentName);
        finalData.insert((int)finalData.find("@@@@"), ":\n");
        
        ifstream finActor1(addActor1.c_str());
        getline(finActor1, tempData, '\0');
        finActor1.close();
        
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
        cout << "------------Actor1 Finish.---------------" << endl;
        
        
        ifstream finActor2(addActor2.c_str());
        getline(finActor2, tempData, '\0');
        finActor2.close();
        
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
        cout << "------------Actor2 Finish.---------------" << endl;
        
        
        ifstream finActor3(addActor3.c_str());
        getline(finActor3, tempData, '\0');
        finActor3.close();
        
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
        cout << "------------Actor3 Finish.---------------" << endl;
        
        ifstream finActor4(addActor4.c_str());
        getline(finActor4, tempData, '\0');
        finActor4.close();
        
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
        cout << "------------Actor4 Finish.---------------" << endl;
        
        ifstream finActor5(addActor5.c_str());
        getline(finActor5, tempData, '\0');
        finActor5.close();
        
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
        cout << "------------Actor5 Finish.---------------" << endl;
        
        ifstream finActor6(addActor6.c_str());
        getline(finActor6, tempData, '\0');
        finActor6.close();
        
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
        cout << "------------Actor6 Finish.---------------" << endl;
        
        
        ifstream finActor7(addActor7.c_str());
        getline(finActor7, tempData, '\0');
        finActor7.close();
        
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
        cout << "------------Actor7 Finish.---------------" << endl;
        
        
        
        ifstream finActresses1(addActresses1.c_str());
        getline(finActresses1, tempData, '\0');
        finActresses1.close();
        
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
        cout << "------------Actresses1 Finish.---------------" << endl;
        
        
        ifstream finActresses2(addActresses2.c_str());
        getline(finActresses2, tempData, '\0');
        finActresses2.close();
        
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
        cout << "------------Actresses2 Finish.---------------" << endl;
        
        
        ifstream finActresses3(addActresses3.c_str());
        getline(finActresses3, tempData, '\0');
        finActresses3.close();
        
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
        cout << "------------Actresses3 Finish.---------------" << endl;
        
        
        
        ifstream finActresses4(addActresses4.c_str());
        getline(finActresses4, tempData, '\0');
        finActresses4.close();
        
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
        cout << "------------Actresses4 Finish.---------------" << endl;
        
        
        
        ifstream finActresses5(addActresses5.c_str());
        getline(finActresses5, tempData, '\0');
        finActresses5.close();
        
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
        cout << "------------Actresses5 Finish.---------------" << endl;
        
        
        
        ifstream finActresses6(addActresses6.c_str());
        getline(finActresses6, tempData, '\0');
        finActresses6.close();
        
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
        cout << "------------Actresses6 Finish.---------------" << endl;
        
        
        
        
        ifstream finActresses7(addActresses7.c_str());
        getline(finActresses7, tempData, '\0');
        finActresses7.close();
        
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
        cout << "------------Actresses7 Finish.---------------" << endl;
        
        
        
        
        ifstream finActresses8(addActresses8.c_str());
        getline(finActresses8, tempData, '\0');
        finActresses8.close();
        
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
        cout << "------------Actresses8 Finish.---------------" << endl;
        
        
        
        
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
    
    ofstream fout("MatchActor1.txt");
    fout << finalData;
    fout.close();
    
    return 0;
    
}