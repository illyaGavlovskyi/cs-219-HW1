//Illya Gavlovskyi
//Programming project 2

#include <stdint.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

string stringUp(string operation);
void flags(int32_t num, bool* flags);
bool isRegister(string selection);
uint32_t getVolueFromRegister(string selection, uint32_t* registers);
void setVolueToRegister (string selection, uint32_t* registers, uint32_t val);

void numToString(uint32_t num);

int main(){
    uint32_t Registers[8] ={0, 0, 0, 0, 0, 0, 0, 0};
    bool flagsArr[4] = {0, 0, 0, 0};
    
    string operation, storageReg, firstS, secondS;

    ifstream inputStream("data.txt");
    if(!inputStream.is_open()){
        cout<<"Error opening file!"<<endl;
        return 0;
    }
    while(!inputStream.eof()){
        operation = "";
        storageReg = "";
        firstS = "";
        secondS = "";

        getline(inputStream, operation, ' ');
        operation = stringUp(operation);
        
        if(operation == "ADD" || operation == "AND" || operation == "ORR" || operation == "SUB" || operation == "XOR"){
            uint32_t first, second, third;
            getline(inputStream, storageReg, ' ');
            storageReg = stringUp(storageReg);
            
            getline(inputStream, firstS, ' ');
            firstS = stringUp(firstS);
            getline(inputStream, secondS);
            secondS = stringUp(secondS);
            // cout<<"Enter operation and hexadecimal numbers:";
            // cin>>operation;
            // cin>>firstS;
            // cin>>secondS;
            // cout<<operation<<"  "<<firstS<<"  "<<secondS<<": ";
            /////////////////////////////////////////////////////////////////////////

            if(isRegister(firstS)){
                first = getVolueFromRegister(firstS, Registers);
            }
            else{
                first = stoul(firstS, nullptr, 16);
            }
            if(isRegister(secondS)){
                second = getVolueFromRegister(secondS, Registers);;
            }
            else{
                second = stoul(secondS, nullptr, 16);
            }

            /////////////////////////////////////////////////////////////////////////
            // first = stoul(firstS, nullptr, 16);
            // second = stoul(secondS, nullptr, 16);
            
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
            setVolueToRegister (storageReg, Registers, third);
            // stringstream stream;
            // stream<<hex<< third;
            // string hexString = stream.str();

            // hexString = stringUp(hexString);
            // cout<<"0x";
            // for(int i = 0; i < 8 - hexString.length();i++){
            //     cout<<"0";
            // }
            // cout<<hexString<<endl;
        }
        
        else if(operation == "ASR"){
            int second;
            int32_t first, third;
            getline(inputStream, storageReg, ' ');
            storageReg = stringUp(storageReg);
            getline(inputStream, firstS, ' ');
            firstS = stringUp(firstS);
            getline(inputStream, secondS);
            secondS = stringUp(secondS);
            
            // cout<<operation<<"  "<<firstS<<"  "<<secondS<<": ";

            if(isRegister(firstS)){
                first = getVolueFromRegister(firstS, Registers);;
            }
            else{
                first = stoul(firstS, nullptr, 16);
            }
            if(isRegister(secondS)){
                second = getVolueFromRegister(secondS, Registers);;
            }
            else{
                second = stoul(secondS, nullptr, 16);
            }

            // first = stoul(firstS, nullptr, 16);
            // second = stoi(secondS);

            if(operation == "ASR"){
                third = first >> second;
            }
            else{
                cout<<"Not working"<<endl;
                return 0;
            }

            setVolueToRegister (storageReg, Registers, third);

            // stringstream stream;
            // stream<<hex<< third;
            // string hexString = stream.str();

            // hexString = stringUp(hexString);

            // cout<<"0x";
            // for(int i = 0; i < 8 - hexString.length();i++){
            //     cout<<"0";
            // }
            // cout<<hexString<<endl;
        }

        else if(operation == "LSR" || operation == "LSL"){
            int second;
            uint32_t first, third;
            getline(inputStream, storageReg, ' ');
            storageReg = stringUp(storageReg);
            getline(inputStream, firstS, ' ');
            firstS = stringUp(firstS);
            getline(inputStream, secondS);
            secondS = stringUp(secondS);
            
            // cout<<operation<<"  "<<firstS<<"  "<<secondS<<": ";
            if(isRegister(firstS)){
                first = getVolueFromRegister(firstS, Registers);;
            }
            else{
                first = stoul(firstS, nullptr, 16);
            }
            if(isRegister(secondS)){
                second = getVolueFromRegister(secondS, Registers);;
            }
            else{
                second = stoul(secondS, nullptr, 16);
            }


            // first = stoul(firstS, nullptr, 16);
            // second = stoi(secondS);

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
            setVolueToRegister (storageReg, Registers, third);


            // stringstream stream;
            // stream<<hex<< third;
            // string hexString = stream.str();

            // hexString = stringUp(hexString);


            // cout<<"0x";
            // for(int i = 0; i < 8 - hexString.length();i++){
            //     cout<<"0";
            // }
            // cout<<hexString<<endl;

        }

        else if(operation == "NOT"){
            uint32_t first, third;
            getline(inputStream, storageReg, ' ');
            storageReg = stringUp(storageReg);
            getline(inputStream, firstS);
            firstS = stringUp(firstS);
            // cout<<operation<<"  "<<firstS<<": ";
            // first = stoul(firstS, nullptr, 16);   
            if(isRegister(firstS)){
                first = getVolueFromRegister(firstS, Registers);;
            }
            else{
                first = stoul(firstS, nullptr, 16);
            } 

            if(operation == "NOT"){
                third = ~first;
            }
            else{
                cout<<"Not working"<<endl;
                return 0;
            }
            setVolueToRegister (storageReg, Registers, third);


            // stringstream stream;
            // stream<<hex<< third;
            // string hexString = stream.str();

            // hexString = stringUp(hexString);


            // cout<<"0x";
            // for(int i = 0; i < 8 - hexString.length();i++){
            //     cout<<"0";
            // }
            // cout<<hexString<<endl;
        }
        
        /////////////////////////////////////////

        if(operation == "ADDS" || operation == "ANDS" || operation == "ORRS" || operation == "SUBS" || operation == "XORS"){
            
            int32_t first, second, third;
            getline(inputStream, storageReg, ' ');
            storageReg = stringUp(storageReg);
            getline(inputStream, firstS, ' ');
            firstS = stringUp(firstS);
            getline(inputStream, secondS);
            secondS = stringUp(secondS);
            // cout<<"Enter operation and hexadecimal numbers:";
            // cin>>operation;
            // cin>>firstS;
            // cin>>secondS;

            // cout<<operation<<"  "<<firstS<<"  "<<secondS<<": ";
            // first = stoul(firstS, nullptr, 16);
            // second = stoul(secondS, nullptr, 16);
            
            if(isRegister(firstS)){
                first = getVolueFromRegister(firstS, Registers);
            }
            else{
                first = stoul(firstS, nullptr, 16);
            }
            if(isRegister(secondS)){
                second = getVolueFromRegister(secondS, Registers);;
            }
            else{
                second = stoul(secondS, nullptr, 16);
            }

            
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
            setVolueToRegister (storageReg, Registers, third);


            // stringstream stream;
            // stream<<hex<< third;
            // string hexString = stream.str();

            // hexString = stringUp(hexString);



            // cout<<"0x";
            // for(int i = 0; i < 8 - hexString.length();i++){
            //     cout<<"0";
            // }
            // cout<<hexString<<endl;
            flags(third, flagsArr);
            
        }
        
        else if(operation == "ASRS"){
            int second;
            int32_t first, third;
            getline(inputStream, storageReg, ' ');
            storageReg = stringUp(storageReg);
            getline(inputStream, firstS, ' ');
            firstS = stringUp(firstS);
            getline(inputStream, secondS);
            secondS = stringUp(secondS);
            
            // cout<<operation<<"  "<<firstS<<"  "<<secondS<<": ";
            // first = stoul(firstS, nullptr, 16);
            // second = stoi(secondS);
            if(isRegister(firstS)){
                first = getVolueFromRegister(firstS, Registers);
            }
            else{
                first = stoul(firstS, nullptr, 16);
            }
            if(isRegister(secondS)){
                second = getVolueFromRegister(secondS, Registers);;
            }
            else{
                second = stoul(secondS, nullptr, 16);
            }



            if(operation == "ASRS"){
                third = first >> second;
            }
            else{
                cout<<"Not working"<<endl;
                return 0;
            }
            setVolueToRegister (storageReg, Registers, third);


            // stringstream stream;
            // stream<<hex<< third;
            // string hexString = stream.str();

            // hexString = stringUp(hexString);



            // cout<<"0x";
            // for(int i = 0; i < 8 - hexString.length();i++){
            //     cout<<"0";
            // }
            // cout<<hexString<<endl;
            flags(third, flagsArr);
        }

        else if(operation == "LSRS" || operation == "LSLS"){
            int second;
            int32_t first, third;
            getline(inputStream, storageReg, ' ');
            storageReg = stringUp(storageReg);
            
            getline(inputStream, firstS, ' ');
            firstS = stringUp(firstS);
            getline(inputStream, secondS, '#');
            getline(inputStream, secondS);
            secondS = stringUp(secondS);
            
            // cout<<operation<<"  "<<firstS<<"  "<<secondS<<": ";
            // first = stoul(firstS, nullptr, 16);
            // second = stoi(secondS);
            if(isRegister(firstS)){
                first = getVolueFromRegister(firstS, Registers);
            }
            else{
                first = stoul(firstS, nullptr, 16);
            }
            if(isRegister(secondS)){
                second = getVolueFromRegister(secondS, Registers);;
            }
            else{
                second = stoul(secondS, nullptr, 16);
            }


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
            setVolueToRegister (storageReg, Registers, third);


            // stringstream stream;
            // stream<<hex<< third;
            // string hexString = stream.str();

            // hexString = stringUp(hexString);



            // cout<<"0x";
            // for(int i = 0; i < 8 - hexString.length();i++){
            //     cout<<"0";
            // }
            // cout<<hexString<<endl;
            flags(third, flagsArr);
        }

        else if(operation == "NOTS"){
            int32_t first, third;
            getline(inputStream, storageReg, ' ');
            storageReg = stringUp(storageReg);
            getline(inputStream, firstS);
            firstS = stringUp(firstS);
            // cout<<operation<<"  "<<firstS<<": ";
            // first = stoul(firstS, nullptr, 16);    
            if(isRegister(firstS)){
                first = getVolueFromRegister(firstS, Registers);
            }
            else{
                first = stoul(firstS, nullptr, 16);
            }


            if(operation == "NOTS"){
                third = ~first;
            }
            else{
                cout<<"Not working"<<endl;
                return 0;
            }
            setVolueToRegister (storageReg, Registers, third);    


            // stringstream stream;
            // stream<<hex<< third;
            // string hexString = stream.str();

            // hexString = stringUp(hexString);



            // cout<<"0x";
            // for(int i = 0; i < 8 - hexString.length();i++){
            //     cout<<"0";
            // }
            // cout<<hexString<<endl;
            flags(third, flagsArr);
        }
        // cout<<storageReg<<endl;
        else if(operation == "MOV"){
            int32_t first, third;
            getline(inputStream, storageReg, ' ');
            storageReg = stringUp(storageReg);
            getline(inputStream, firstS, '#');
            getline(inputStream, firstS);
            firstS = stringUp(firstS);
            // cout<<firstS<<"worked"<<endl;
            
            if(isRegister(firstS)){
                first = getVolueFromRegister(firstS, Registers);
            }
            else{
                // cout<<firstS<<"worked"<<endl;
                first = stoul(firstS, nullptr, 16);
               
            }
            
            setVolueToRegister (storageReg, Registers, first); 
            
        }
        cout<<operation<<" "<<storageReg<<" "<<firstS<<" ";
        if(secondS != ""){
            cout<<secondS;
        }

        cout<<endl;
        cout<<"R0:";
        numToString(Registers[0]);
        cout<<"     ";
        cout<<"R1:";
        numToString(Registers[1]);
        cout<<"     ";
        cout<<"R2:";
        numToString(Registers[2]);
        cout<<"     ";
        cout<<"R3:";
        numToString(Registers[3]);
        cout<<"     ";
        cout<<"R4:";
        numToString(Registers[4]);
        cout<<"     ";
        cout<<"R5:";
        numToString(Registers[5]);
        cout<<"     ";
        cout<<"R6:";
        numToString(Registers[6]);
        cout<<"     ";
        cout<<"R7:";
        numToString(Registers[7]);
        cout<<endl;
        cout<<"N = ";
        cout<<flagsArr[0];
        cout<<" Z = ";
        cout<<flagsArr[1];
        cout<<" C = ";
        cout<<flagsArr[2];
        cout<<" V = ";
        cout<<flagsArr[3];
        cout<<endl;
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

void flags(int32_t num, bool* flags){
    if(num < 0){
        flags[0] = 1;
        // cout<<"N:1 ";
    }
    else{
        flags[0] = 0;
        // cout<<"N:0 ";
    }
    if(num == 0){
        flags[1] = 1;
        // cout<<"Z:1 "<<endl;
    }
    else{
        flags[1] = 0;
        // cout<<"Z:0 "<<endl;
    }
}

uint32_t getVolueFromRegister(string selection, uint32_t* registers){
    if(selection == "R0" || selection == "R0,"){
        return registers[0];
    }
    else if(selection == "R1" || selection == "R1,"){
        return registers[1];
    }
    else if(selection == "R2" || selection == "R2,"){
        return registers[2];
    }
    else if(selection == "R3" || selection == "R3,"){
        return registers[3];
    }
    else if(selection == "R4" || selection == "R4,"){
        return registers[4];
    }
    else if(selection == "R5" || selection == "R5,"){
        return registers[5];
    }
    else if(selection == "R6" || selection == "R6,"){
        return registers[6];
    }
    else if(selection == "R7" || selection == "R7,"){
        return registers[7];
    }
    else{
        throw "error";
    }
}

void setVolueToRegister (string selection, uint32_t* registers, uint32_t val){
    if(selection == "R0" || selection == "R0,"){
        registers[0] = val;
    }
    else if(selection == "R1" || selection == "R1,"){
        registers[1] = val;
    }
    else if(selection == "R2" || selection == "R2,"){
        registers[2] = val;
    }
    else if(selection == "R3" || selection == "R3,"){
        registers[3] = val;
    }
    else if(selection == "R4" || selection == "R4,"){
        registers[4] = val;
    }
    else if(selection == "R5" || selection == "R5,"){
        registers[5] = val;
    }
    else if(selection == "R6" || selection == "R6,"){
        registers[6] = val;
    }
    else if(selection == "R7" || selection == "R7,"){
        registers[7] = val;
    }
    else{
        throw "error";
    }
}

bool isRegister(string selection){
    if(selection == "R0" || selection == "R0,"){
        return true;
    }
    else if(selection == "R1" || selection == "R1,"){
        return true;
    }
    else if(selection == "R2" || selection == "R2,"){
        return true;
    }
    else if(selection == "R3" || selection == "R3,"){
        return true;
    }
    else if(selection == "R4" || selection == "R4,"){
        return true;
    }
    else if(selection == "R5" || selection == "R5,"){
        return true;
    }
    else if(selection == "R6" || selection == "R6,"){
        return true;
    }
    else if(selection == "R7" || selection == "R7,"){
        return true;
    }
    else{
        return false;
    }
}

void numToString(uint32_t num){
    stringstream stream;
    stream<<hex<< num;
    string hexString = stream.str();
    hexString = stringUp(hexString);
    cout<<"0x";
    for(int i = 0; i < 8 - hexString.length();i++){
        cout<<"0";
    }
    cout<<hexString;
}