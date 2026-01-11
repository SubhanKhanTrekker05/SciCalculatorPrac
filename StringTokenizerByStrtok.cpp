// Part 1
// #include<iostream>
// #include<cstring>
// using namespace std;

// int main(){
//     char str[]="Introduction to Monsters(Fantasy and Non-Fantasy): A Complete Encylcopedia and Guide to Monstrology";
//     char* ptr;
//     ptr = strtok(str," -:");
//     while(ptr!=nullptr){
//         cout<<ptr;
//         ptr=strtok(nullptr, " -:");
//     }


//     return 0;
// }

#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main(){
    char str[]="Introduction to Monsters(Fantasy and Non-Fantasy): A Complete Encylcopedia and Guide to Monstrology";
    char* ptr;
    ptr = strtok(str," -:");
    
    vector<char*> txt;

    while(ptr!=nullptr){
        txt.push_back(ptr);
        ptr=strtok(nullptr, " -:");
    }
    for(auto i: txt){
        cout<<i<<endl;
    }


    return 0;
}
