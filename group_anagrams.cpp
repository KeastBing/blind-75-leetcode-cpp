//49 Group anagrams

#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
    unordered_map<string, vector<string>> tracking;
    vector<vector<string>> res;
    string temp;
    for(string &s: strs){
        temp = s;
        sort(temp.begin(), temp.end());

         tracking[temp].push_back(s);
    }

    for(auto &i : tracking){
        res.push_back(i.second);
    }

    return res;
}


int main(){
    //tests
   vector<vector<string>> strs = {{"act","pots","tops","cat","stop","hat"}, {"eat","tea","tan","ate","nat","bat"}, {""}, {"a"}}; 

   for(vector<string> &str : strs){
        vector<vector<string>> res = groupAnagrams(str);

        for(vector<string> &re : res){
            cout<<"[ ";
            for(string &i: re){
                cout<<i<<", ";
            }
            cout<<"]"<<endl;
        }

        cout<<"------------------------------------------------------------------------------------------"<<endl;
   }
}