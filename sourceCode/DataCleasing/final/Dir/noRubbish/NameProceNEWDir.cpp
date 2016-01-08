//NameProceNEWDir.cpp
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
    string addre = "directors.txt";
    
    ifstream fin(addre.c_str());
    getline(fin, templist, '\0');
    fin.close();
    
    int point = 0;
    int pointSurnameS = 0;
    int pointSurnameE = 0;
    int pointGivennameS = 0;
    int pointGivennameE = 0;
    
    int whereEnter = 0;
    
    while(true){
        
        if((char)templist[point] == '@')
            if((char)templist[point + 1] == '@')
                if((char)templist[point + 2] == '@')
                    if((char)templist[point + 3] == '@')
                        break;
        
        while(true){
            if((char)templist[pointSurnameE] == ','){
                break;
            }
            else{
                pointSurnameE++;
            }
        }
        string surname = templist.substr(pointSurnameS, pointSurnameE - pointSurnameS);
        
        pointGivennameS = pointGivennameE = pointSurnameE + 2;
        
        while(true){
            if((char)templist[pointGivennameE] == '\t'){
                break;
            }
            else{
                pointGivennameE++;
            }
        }
        string givenname = templist.substr(pointGivennameS, pointGivennameE - pointGivennameS);
        
        string nameBefore = surname + ", " + givenname;
        string nameAfter = givenname + "_" + surname;
        int lengthBefore = nameBefore.length();
        int lengthAfter = nameAfter.length();
        
        templist.replace(pointSurnameS, lengthBefore, nameAfter);
        pointGivennameE--;
        
        while(true){
            if((char)templist[pointGivennameE] == '\n'){
                pointGivennameE++;
                break;
            }
            else{
                pointGivennameE++;
            }
        }
        
        point = pointSurnameS = pointSurnameE = pointGivennameS = pointGivennameE;
        
        
    }
    
    templist.erase((int)templist.find("@@@@"), 5);
    

    ofstream fout("Director.txt");
    fout << templist;
    fout.close();
    
    return 0;
    
}