//242 Valid anagram

#include<stdio.h>
#include<iostream>
#include<unordered_map>

using namespace std;

bool isAnagram(string s, string t) {

    if(s.length() != t.length()){
        return false;
    }

    unordered_map<char,int> visited1;

    for(int i = 0; i < s.length(); i++){
        visited1[s[i]] += 1;
        visited1[t[i]] -= 1;
    }

    for(auto &i: visited1){
        if(i.second != 0){
            return false;
        }
    }
    
    return true;
}

int main(){
    //tests
    string s1 = "jar", t1 = "jam";
    string s2 = "racecar", t2 = "carrace";

    cout<<isAnagram(s1,t1);
    cout<<isAnagram(s2,t2);
}