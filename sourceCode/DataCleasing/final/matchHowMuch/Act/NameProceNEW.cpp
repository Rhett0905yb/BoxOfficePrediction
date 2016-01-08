//NameProceNEW.cpp
//@author: Yibo YU, Rhett0905yb@gmail.com

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;


int main(void){
    
    string namelist = "@@@@\n";
    string templist;
    string FinalNameList = "@@@@\n";
    string addre = "../../Namelist.txt";
    
    ifstream fin(addre.c_str());
    getline(fin, templist, '\0');
    fin.close();
    
    int pointS = 0;
    int pointE = 0;
    int pointM = 0;
    
    int point = 0;
    
    while (true) {
        point = (int)templist.find("\n");
        if(point < 0) break;
        string oneName = templist.substr(0, point + 1);
        if((int)oneName.find("_") > 0){
            namelist.insert((int)namelist.find("@@@@"), "$");
            namelist.insert((int)namelist.find("@@@@"), oneName);
        }
        templist.erase(0, point + 1);
    }
    namelist.erase((int)namelist.find("@@@@"), 5);
    
    //cout << namelist << endl;
    
    while(true){
        
        pointE = (int)namelist.find("\n");
        //cout << pointE << endl;
        if(pointE < 0) break;
        
        pointS = pointE;
        //cout << pointS << " " << pointM << " " << pointE << endl;
        while(true){
            if((char)namelist[pointS] == '_'){
                pointS++;
                break;
            }
            else{
                pointS--;
            }
        }
        string tempdata = namelist.substr(pointS, pointE - pointS);
        //if((int)tempdata.find("\n") > 0){
        //    tempdata.erase((int)tempdata.find("\n"), 1);
        //}
        FinalNameList.insert((int)FinalNameList.find("@@@@"), tempdata);
        FinalNameList.insert((int)FinalNameList.find("@@@@"), ", ");
        
        //cout << pointS << " " << pointM << " " << pointE << endl;
        
        pointM = pointS;
        //cout << pointS << " " << pointM << " " << pointE << endl;
        while(true){
            if((char)namelist[pointS] == '\n'){
                pointS++;
                break;
            }
            else if((char)namelist[pointS] == '$'){
                //pointS++;
                break;
            }
            else{
                pointS--;
            }
        }
        //cout << pointS << " " << pointM << " " << pointE << endl;
        string tempdata2 = namelist.substr(pointS + 1, pointM - pointS - 2);
        //if((int)tempdata2.find("\n") > 0){
        //    tempdata2.erase((int)tempdata2.find("\n"), 1);
        //}
        FinalNameList.insert((int)FinalNameList.find("@@@@"), tempdata2);
        FinalNameList.insert((int)FinalNameList.find("@@@@"), "\n");
        
        //cout << tempdata2 << endl;
        cout << pointS << " " << pointM << " " << pointE << endl;
        namelist.erase(pointS, pointE - pointS + 1);
        //cout << pointS << " " << pointM << " " << pointE << endl;
        //if(pointS > pointM) break;
    }
    
    while(true){
        int find_ = (int)FinalNameList.find("_");
        if(find_ < 0) break;
        else{
            FinalNameList.replace(find_, 1, " ");
        }
    }
    
    FinalNameList.erase((int)FinalNameList.find("@@@@"), 5);
    

    ofstream fout("NameListFinal.txt");
    fout << FinalNameList;
    fout.close();
    
    return 0;
    
}