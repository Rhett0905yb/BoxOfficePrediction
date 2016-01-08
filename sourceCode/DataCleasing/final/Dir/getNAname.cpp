//getNAname.cpp
//@author: Yibo YU, Rhett0905yb@gmail.com

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;


int main(void){
    
    string NAList = "@@@@\n";
    string path = "MatchDirector_final.txt";
    string data;
    
    ifstream fin(path.c_str());
    getline(fin, data, '\0');
    fin.close();
    
    int pointStart = 0;
    int pointEnd = 0;
    int pointMiddle = 0;
    
    int sumNum = 0;
    
    while(true){
        
        pointStart = (int)data.find("N/A");
        if(pointStart < 0) break;
        pointEnd = pointStart;
        pointMiddle = pointStart;
        
        //cout << pointStart << " " << pointMiddle << " " << pointEnd << endl;
        
        while(true){
            if((char)data[pointStart] == '-'){
                //cout << "111" << endl;
                pointStart++;
                break;
            }
            else{
                pointStart--;
            }
                
        }
        while(true){
            if((char)data[pointEnd] == '-'){
                break;
            }
            else{
                pointEnd++;
            }
        }
        while(true){
            if((char)data[pointMiddle] == ':'){
                pointMiddle--;
                break;
            }
            else{
                pointMiddle--;
            }
        }
        
        cout << pointStart << " " << pointMiddle << " " << pointEnd << endl;
        string oneNA = data.substr(pointStart, pointMiddle - pointStart);
        data.erase(pointStart, pointEnd - pointStart);
        NAList.insert((int)NAList.find("@@@@"), oneNA);
        //NAList.insert((int)NAList.find("@@@@"), "\n");
        
        sumNum++;
        cout << "Got " << sumNum << " X." << endl;
        
    }
    
    NAList.erase((int)NAList.find("@@@@"), 5);
    
    ofstream foutActorRow("directorsRow.txt");
    foutActorRow << data;
    foutActorRow.close();
    
    ofstream foutNAList("NAListDirectors.txt");
    foutNAList << NAList;
    foutNAList.close();
    
    return 0;
    
}