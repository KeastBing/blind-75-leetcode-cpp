// Blind 75 p4

#include<stdio.h>
#include<iostream>
#include<unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> tracking;
    int maxlen = 0;
    int start_ind = 0;

    for(int i = 0 ; i < s.length(); i++){
        if(tracking.find(s[i]) != tracking.end() && tracking[s[i]] >= start_ind){
                start_ind = tracking[s[i]] + 1;
        }
        tracking[s[i]] = i;
        maxlen = max(maxlen, i - start_ind + 1);
    }

    return maxlen;
}



int main(){
    //tests
    string s[9] = {"abcabcbb", " ", "pwwkew", "dvdf", "ckilbkd", "bbbbbbb", "tmmzuxt", "anviaj", "nfpdmpi"};

    for(string &i : s){
        cout<<i<<"\n"<<lengthOfLongestSubstring(i)<<"\n"<<endl;
    }
}