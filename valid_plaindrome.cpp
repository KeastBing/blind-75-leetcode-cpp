//125. Valid Palindrome

#include<stdio.h>
#include<iostream>

using namespace std;

bool isPalindrome(string s) {

    if(s.length() == 0){
        return false;
    }

    string str;

    for( char &st: s){

        if(isalnum(st)){
            str += tolower(st);
        }
    }
    
    int i = 0;
    int j =  str.length() - 1;

    while(i<j){
        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int main(){
    //test
    string s = "Was it a car or a cat I saw?";

    cout<<isPalindrome(s);
}