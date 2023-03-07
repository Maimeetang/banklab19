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

void importDataFromFile(string filename, vector<string> &names, vector<int> &scores, vector<char> &grades){
    string text;
    ifstream source(filename.c_str());
    while(getline(source,text))
    {
        char format[] = "%[^:]: %d %d %d";
        char name[100];
        int a,b,c;
        sscanf(text.c_str(),format,name,&a,&b,&c);
        names.push_back(name);
        scores.push_back(a+b+c);
        grades.push_back(score2grade(a+b+c));

    }
}

void getCommand(string &command,string &key){
    string h;
    cout << "Please input your command: ";
    getline(cin,h);

    int start = 0;
    int end = h.find_first_of(" ");

    command = h.substr(start,end-start);
    start = end + 1 ;
    end = h.find_first_of(" ",start);
    key = h.substr(start);
}

void searchName(vector<string> &names, vector<int> &scores, vector<char> &grades, string key){
    int number,k;
    for(unsigned int i=0; i<names.size(); i++)
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
        cout << names[number] << "'s score = " << scores[number] << endl << names[number] << "'s grade = " << grades[number] << endl;
        cout << "---------------------------------" << endl;
    }else{
        cout << "---------------------------------" << endl;
        cout << "Cannot found.\n";
        cout << "---------------------------------" << endl;
    }
}

void searchGrade(vector<string> &names, vector<int> &scores, vector<char> &grades, string key){
    string g;
    cout << "---------------------------------" << endl;
    for(unsigned int i=0; i<grades.size(); i++){
        g = grades[i];
        if(key.c_str() == g){
            cout << names[i] << " (" << scores[i] << ")" << endl;
        }
    }
    cout << "---------------------------------" << endl;
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
