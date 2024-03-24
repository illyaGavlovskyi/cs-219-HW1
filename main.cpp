//Illya Gavlovskyi
//Programming project 2

#include <stdint.h>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

string stringUp(string operation);
void flags(int32_t num);

int main(){
    string operation, firstS, secondS;
    

    ifstream inputStream("data.txt");
    if(!inputStream.is_open()){
        cout<<"Error opening file!"<<endl;
        return 0;
    }
    while(!inputStream.eof()){
        operation = "";
        firstS = "";
        secondS = "";

        getline(inputStream, operation, ' ');
        if(operation == "ADD" || operation == "AND" || operation == "ORR" || operation == "SUB" || operation == "XOR"){
            uint32_t first, second, third;
            getline(inputStream, firstS, ' ');
            getline(inputStream, secondS);
            // cout<<"Enter operation and hexadecimal numbers:";
            // cin>>operation;
            // cin>>firstS;
            // cin>>secondS;
            cout<<operation<<"  "<<firstS<<"  "<<secondS<<": ";
            first = stoul(firstS, nullptr, 16);
            second = stoul(secondS, nullptr, 16);
            
            if(operation == "ADD"){
                third = first + second;
            }
            else if(operation == "AND"){
                third = first & second;
            }
            else if(operation == "ORR"){
                third = first | second;
            }
            else if(operation == "SUB"){
                third = first - second;
            }
            else if(operation == "XOR"){
                third = first ^ second;
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
        
        else if(operation == "ASR"){
            int second;
            int32_t first, third;
            getline(inputStream, firstS, ' ');
            getline(inputStream, secondS);
            
            cout<<operation<<"  "<<firstS<<"  "<<secondS<<": ";
            first = stoul(firstS, nullptr, 16);
            second = stoi(secondS);

            if(operation == "ASR"){
                third = first >> second;
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

        else if(operation == "LSR" || operation == "LSL"){
            int second;
            uint32_t first, third;
            getline(inputStream, firstS, ' ');
            getline(inputStream, secondS);
            
            cout<<operation<<"  "<<firstS<<"  "<<secondS<<": ";
            first = stoul(firstS, nullptr, 16);
            second = stoi(secondS);

            if(operation == "LSR"){
                third = first >> second;
            }
            else if(operation == "LSL"){
                third = first << second;
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

        else if(operation == "NOT"){
            uint32_t first, third;
            getline(inputStream, firstS);
            cout<<operation<<"  "<<firstS<<": ";
            first = stoul(firstS, nullptr, 16);    

            if(operation == "NOT"){
                third = ~first;
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
        
        /////////////////////////////////////////

        if(operation == "ADDS" || operation == "ANDS" || operation == "ORRS" || operation == "SUBS" || operation == "XORS"){
            int32_t first, second, third;
            getline(inputStream, firstS, ' ');
            getline(inputStream, secondS);
            // cout<<"Enter operation and hexadecimal numbers:";
            // cin>>operation;
            // cin>>firstS;
            // cin>>secondS;
            cout<<operation<<"  "<<firstS<<"  "<<secondS<<": ";
            first = stoul(firstS, nullptr, 16);
            second = stoul(secondS, nullptr, 16);
            
            if(operation == "ADDS"){
                third = first + second;
            }
            else if(operation == "ANDS"){
                third = first & second;
            }
            else if(operation == "ORRS"){
                third = first | second;
            }
            else if(operation == "SUBS"){
                third = first - second;
            }
            else if(operation == "XORS"){
                third = first ^ second;
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
            flags(third);
            
        }
        
        else if(operation == "ASRS"){
            int second;
            int32_t first, third;
            getline(inputStream, firstS, ' ');
            getline(inputStream, secondS);
            
            cout<<operation<<"  "<<firstS<<"  "<<secondS<<": ";
            first = stoul(firstS, nullptr, 16);
            second = stoi(secondS);

            if(operation == "ASRS"){
                third = first >> second;
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
            flags(third);
        }

        else if(operation == "LSRS" || operation == "LSLS"){
            int second;
            int32_t first, third;
            getline(inputStream, firstS, ' ');
            getline(inputStream, secondS);
            
            cout<<operation<<"  "<<firstS<<"  "<<secondS<<": ";
            first = stoul(firstS, nullptr, 16);
            second = stoi(secondS);

            if(operation == "LSRS"){
                third = first >> second;
            }
            else if(operation == "LSLS"){
                third = first << second;
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
            flags(third);
        }

        else if(operation == "NOTS"){
            int32_t first, third;
            getline(inputStream, firstS);
            cout<<operation<<"  "<<firstS<<": ";
            first = stoul(firstS, nullptr, 16);    

            if(operation == "NOTS"){
                third = ~first;
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
            flags(third);
        }
        
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

void flags(int32_t num){
    if(num < 0){
        cout<<"N:1 ";
    }
    else{
        cout<<"N:0 ";
    }
    if(num == 0){
        cout<<"Z:1 "<<endl;
    }
    else{
        cout<<"Z:0 "<<endl;
    }
}