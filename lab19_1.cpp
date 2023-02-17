#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>
#include<cctype>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename, vector<int> &names, vector<int> &scores, vector<int> &grades){
    string s;
    ifstream fin(filename);
    while(getline(fin,s))
    {
        char x[] = s;
        char format[] = "%[^:]: %f %f %f";
        char name[100];
        int a,b,c;
        sscanf(x,format,name,&a,&b,&c);
        names.push_back(name);
        scores.push_back(a+b);
        grades.push_back(score2grade(a+b));

    }
}

void getCommand(string command,string key){
    cout << "Please input your command: "
    cin >> key;
    char text[] = key;
    char format[] = "%s %s";
    char com[100];
    char norg[100];
    sscanf(text,format,com,norg);
    command = com;
    key = norg;
}

void searchName(vector<int> &names, vector<int> &scores, vector<int> &grades, string key){
    int number,k;
    for(int i=0; i<names.size(); i++)
    {
        if(key == toUpperStr(names[i]))
        {
            k=0;
            number = i;
            break;
        }else{
            k=1;
        }
    }
    if(k == 0)
    {
        cout << "---------------------------------" << endl;
        cout << names[number] << "'s score " << scores[number] << endl << names[number] << "'s grade " << grades[number];
        cout << "---------------------------------" << endl;
    }else{
        cout << "---------------------------------" << endl;
        cout << "Cannot found.";
        cout << "---------------------------------" << endl;
    }
}

void searchGrade(vector<int> &names, vector<int> &scores, vector<int> &grades, string key){
    for(int i=0; i<grades.size(); i++){
        
    }
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
