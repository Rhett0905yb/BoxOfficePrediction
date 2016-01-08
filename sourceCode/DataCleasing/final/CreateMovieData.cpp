//CreateMovieData.cpp
//@author: Yibo YU, Rhett0905yb@gmail.com

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;



string replaceBlank(string data){
    int breakNum = 0;
    
    while (breakNum == 0) {
        if((int)data.find(" ") < 1)
            breakNum = 1;
        else
            data.replace(data.find(" "), 1, "_");
    }
    return data;
}

string replaceComma(string data){
    int commaNum = 0;
    
    while (commaNum == 0) {
        if((int)data.find(",") < 1)
            commaNum = 1;
        else
            data.replace(data.find(","), 1, "\t\t\t");
    }
    return data;
}

int main(void){
    
    string FinalDirectorList = "@@@@\n";
    string FinalNameList = "@@@@\n";
    string FinalData = "@@@@\n";
    string Moviedata;
    string addreMovie = "movieRow.txt";
    
    int DirectorNum = 0;
    int DirectorRNum = 0;
    int ActorNum = 0;
    int ActorRNum = 0;
    int point = 0;
    string oneLineData;
    
    ifstream finMovie(addreMovie.c_str());
    getline(finMovie, Moviedata, '\0');
    finMovie.close();
    
    Moviedata = replaceBlank(Moviedata);
    //Moviedata = replaceComma(Moviedata);
    
    string currentMovieName;
    
    while(true){
        
        point = (int)Moviedata.find("\n");
        if(point < 0) break;
        oneLineData = Moviedata.substr(0, point + 1);
        Moviedata.erase(0, point + 1);
        
        int haveCom = 0;
        int whereEnter = 0;
        int elementNum = 0;
        
        string tempName;
        
        while (true) {
            haveCom = (int)oneLineData.find(',');
            if(haveCom > 0){
                FinalData.insert((int)FinalData.find("@@@@"), oneLineData.substr(0, haveCom));
                FinalData.insert((int)FinalData.find("@@@@"), "\t\t\t");
                elementNum++;
                if(elementNum == 2)
                    currentMovieName = oneLineData.substr(0, haveCom);
                if(elementNum == 3){
                    tempName = oneLineData.substr(0, haveCom);
                    if((int)FinalDirectorList.find(tempName) < 0){
                        FinalDirectorList.insert((int)FinalDirectorList.find("@@@@"), oneLineData.substr(0, haveCom));
                        FinalDirectorList.insert((int)FinalDirectorList.find("@@@@"), "\n");
                        DirectorNum++;
                    }
                    else
                        DirectorRNum++;
                }
                if(elementNum > 5 && elementNum < 10){
                    tempName = oneLineData.substr(0, haveCom);
                    if((int)FinalNameList.find(tempName) < 0){
                        FinalNameList.insert((int)FinalNameList.find("@@@@"), oneLineData.substr(0, haveCom));
                        FinalNameList.insert((int)FinalNameList.find("@@@@"), "\n");
                        ActorNum++;
                    }
                    else
                        ActorRNum++;
                }
                oneLineData.erase(0, haveCom + 1);
                //cout << endl << haveCom << endl;
            }
            else{
                //cout << endl << "13123123123123123123" << endl;
                whereEnter =(int)oneLineData.find('\n');
                FinalData.insert((int)FinalData.find("@@@@"), oneLineData.substr(0, whereEnter + 1));
                oneLineData.erase(0, whereEnter + 1);
                elementNum = 0;
                break;
            }
        }
        
        //cout << endl << locationInGross << endl << pointInGross << endl;
        
        //cout << endl << currentMovieName << endl;
        
    }
    
    
    int LineNum = 0;
    while (LineNum == 0) {
        if((int)FinalData.find("|") < 1)
            LineNum = 1;
        else
            FinalData.replace(FinalData.find("|"), 1, ",");
    }
    
    cout << "Have Dir: " << DirectorNum << " and R: " << DirectorRNum << "." << endl;
    cout << "Have Act: " << ActorNum << " and R: " << ActorRNum << "." << endl;
    
    FinalData.erase((int)FinalData.find("@@@@"), 5);
    FinalNameList.erase((int)FinalNameList.find("@@@@"), 5);
    FinalDirectorList.erase((int)FinalDirectorList.find("@@@@"), 5);
    
    ofstream foutMovie("Movie.txt");
    foutMovie << FinalData;
    foutMovie.close();
    
    ofstream foutNameList("NameList.txt");
    foutNameList << FinalNameList;
    foutNameList.close();
    
    ofstream foutDirectorList("DirectorList.txt");
    foutDirectorList << FinalDirectorList;
    foutDirectorList.close();
    
    
    return 0;
    
}