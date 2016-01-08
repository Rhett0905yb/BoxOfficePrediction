//getRowNoEnter.cpp
//@author: Yibo YU, Rhett0905yb@gmail.com

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
using namespace std;


int main(void){
    
    string FinalData = "@@@@\n";
    string path = "actorRow.txt";
    string data;
    string name;
    int line = 0;
    
    ifstream fin(path.c_str());
    getline(fin, data, '\0');
    fin.close();
    
    //cout << data << endl;
    
    int point = 0;
    
    while(true){
        
        //cout << "1" << endl;
        if((char)data[point] == '@')
            if((char)data[point + 1] == '@')
                if((char)data[point + 2] == '@')
                    if((char)data[point + 3] == '@'){
                        //cout << "2" << endl;
                        break;
                    }
        
        
        if((char)data[point] == '\n' && (char)data[point + 1] == '\n'){
            data.erase(point, 1);
            line++;
            cout << line << endl;
        }
        //cout << (char)data[point] << endl;
        point++;
        
    }
    
    
    //FinalData.erase((int)FinalData.find("@@@@"), 5);
    
    ofstream fout("actorRowNoEnter.txt");
    fout << data;
    fout.close();
    
    return 0;
    
}