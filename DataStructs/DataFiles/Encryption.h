#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include <iostream>
#include <string>
using namespace std;

string encrypt(string s){
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = s[i]+45; //Adding 45 to ASCII code
    }
    return s;
}

string decrypt(string s){
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = s[i]-45; //Changing ASCII code back to normal
    }
    return s;
}

#endif
