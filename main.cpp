#include <stdint.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    uint32_t first, second, third;
    first = 0xAAA;
    second = 0x123;
    third = first + second;

    cout<<third<<endl;

    std::stringstream stream;
    stream<<std::hex<< third;
    string hexString = stream.str();
    cout<<hexString<<endl;
    // int arrnum[100];
    // while(third > 0){
    //     int cnt = 0;
    //     arrnum[cnt] =
        
         
    // }
}