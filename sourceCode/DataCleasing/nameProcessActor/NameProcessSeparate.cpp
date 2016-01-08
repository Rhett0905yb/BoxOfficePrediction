//NameProcessSeparate.cpp
//@author: Yibo YU, Rhett0905yb@gmail.com

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;


int main(void){
    
    string namelist;
    string oneName;
    string FinalNameList;
    string addre = "NameListFinal2.txt";
    
    int actorNum = 0;
    int fileNum = 0;
    string fileName;
    int point = 0;
    
    ifstream fin(addre.c_str());
    getline(fin, namelist, '\0');
    fin.close();
    
    FinalNameList = "@@@@\n";
    
    while(true){
        
        point = (int)namelist.find("\n");
        if(point < 0) break;
        oneName = namelist.substr(0, point);
        namelist.erase(0, point + 1);
        actorNum++;
        
        FinalNameList.insert((int)FinalNameList.find("@@@@"), oneName);
        FinalNameList.insert((int)FinalNameList.find("@@@@"), "\n");
        
        if(actorNum > 200){
            actorNum = 0;
            fileNum++;
            
            FinalNameList.erase((int)FinalNameList.find("@@@@"), 5);
            
            ostringstream ss;
            ss << fileNum;
            fileName = "NameListFinal2_" + ss.str() + ".txt";
            
            ofstream fout(fileName);
            fout << FinalNameList;
            fout.close();
            
            FinalNameList = "@@@@\n";
        }
        
    }
    
    fileNum++;
    
    FinalNameList.erase((int)FinalNameList.find("@@@@"), 5);
    
    ostringstream ss;
    ss << fileNum;
    fileName = "NameListFinal2_" + ss.str() + ".txt";
    
    ofstream fout(fileName);
    fout << FinalNameList;
    fout.close();
    
    //ofstream fout("NameList.txt");
    //fout << FinalNameList;
    //fout.close();
    
    return 0;
    
}