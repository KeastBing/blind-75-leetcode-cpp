//271 encode decode strings 

#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

string encode(vector<string>& strs) {
   string ans;

   for(string &str: strs ){
        ans += to_string(str.size()) + "#" + str;
   }

   return ans;
}

vector<string> decode(string s) {

    vector<string> ans;

    if(s.empty()){
        return ans;
    }

    string temp;
    int i = 0;
    int n = s.length();
    
    while(i < n){
        
        while(s[i] != '#')
        {
            temp += s[i];
            i++;
        }
        i++;
        int len = stoi(temp);
        temp.clear();
        temp = s.substr(i, len);
        ans.push_back(temp);
        temp.clear();
        i += len;

        }
    return ans;
}
    


int main(){
    //tests
    vector<vector<string>> tests = {{"we","say",":","yes","!@#$%^&*()"}, {"neet","code","love","you"}, {"we","say",":","yes"}};
    
    for(vector<string> test: tests){
        string tryin = encode(test);
        vector<string> ans;
        ans = decode(tryin);
        for(string &s: ans){
            cout<<s<<" ";
        }

        cout<<endl;
    }
    

   
}