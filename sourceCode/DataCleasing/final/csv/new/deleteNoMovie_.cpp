//deleteNoMovie_.cpp
//@author: Yibo YU, Rhett0905yb@gmail.com

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;


int main(void){
    
    string finalData = "@@@@\n";
    string path = "Director.txt";
    string data;
    string tempData;
    string tempData2;
    int whereOneLineEnter = 0;
    int LineNum = 0;
    int fileNum = 0;
    
    ifstream fin(path.c_str());
    getline(fin, data, '\0');
    fin.close();
    
    while(true){
        int whereEnter = (int)data.find("\n");
        if(whereEnter < 0) break;
        
        tempData = data.substr(0, whereEnter + 1);
        //cout << tempData << endl;
        data.erase(0, whereEnter + 1);
        
        finalData.insert((int)finalData.find("@@@@"), "\"");
        while(true){
            int whereTab = (int)tempData.find("\t\t");
            if(whereTab < 0) break;
            
            tempData2 = tempData.substr(0, whereTab);
            //cout << tempData2 << endl;
            //cout << tempData.substr(0, whereTab + 3) << endl << "-----" << endl;
            tempData.erase(0, whereTab + 3);
            finalData.insert((int)finalData.find("@@@@"), tempData2);
            finalData.insert((int)finalData.find("@@@@"), "\",\"");
        }
        
        whereOneLineEnter = (int)tempData.find("\n");
        finalData.insert((int)finalData.find("@@@@"), tempData.substr(0, whereOneLineEnter - 1));
        finalData.insert((int)finalData.find("@@@@"), "\"\n");
        LineNum++;
        if(LineNum % 500 == 0)
            cout << LineNum << endl;
        if(LineNum % 5000 == 0){
            fileNum++;
            
            finalData.erase((int)finalData.find("@@@@"), 5);
            
            ostringstream ss;
            ss << fileNum;
            string fileName = "ActorCSV_" + ss.str() + ".txt";
            
            ofstream foutNAList(fileName);
            foutNAList << finalData;
            foutNAList.close();
            
            finalData = "@@@@\n";
        }
        
    }
    
    
    
    finalData.erase((int)finalData.find("@@@@"), 5);
    
    ofstream foutNAList("Director_.txt");
    foutNAList << finalData;
    foutNAList.close();
    
    return 0;
    
}