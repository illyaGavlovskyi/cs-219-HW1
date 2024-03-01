//Illya Gavlovskyi
//Programming project 1

#include <stdint.h>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

string stringUp(string operation);

int main(){
    string operation, firstS, secondS;
    uint32_t first, second, third;

    ifstream inputStream("data.txt");
    if(!inputStream.is_open()){
        cout<<"Error opening file!"<<endl;
        return 0;
    }
    while(!inputStream.eof()){
        operation = "";
        firstS = "";
        secondS = "";
        // inputStream>>operation>>firstS>>secondS;
        getline(inputStream, operation, ' ');
        getline(inputStream, firstS, ' ');
        getline(inputStream, secondS);

        cout<<operation<<"  "<<firstS<<"  "<<secondS<<": ";
        // cout<<"Enter operation and hexadecimal numbers:";
        // cin>>operation;
        // cin>>firstS;
        // cin>>secondS;

        first = stoul(firstS, nullptr, 16);
        second = stoul(secondS, nullptr, 16);
        
        if(operation == "ADD"){
            third = first + second;
        }
        else{
            cout<<"Not working"<<endl;
            return 0;
        }

        stringstream stream;
        stream<<hex<< third;
        string hexString = stream.str();

        hexString = stringUp(hexString);
        cout<<"0x";
        for(int i = 0; i < 8 - hexString.length();i++){
            cout<<"0";
        }
        cout<<hexString<<endl;
    }
    inputStream.close();
    return 0;
}

string stringUp(string operation){
    string newstring= "";
    int num = 0;
    for(int i = 0; i < operation.length() + 1; i ++){
        if (islower(operation[i])) {
            operation[i] = toupper(operation[i]);
        }
    }
    return operation;
}