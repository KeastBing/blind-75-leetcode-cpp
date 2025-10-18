//blind 75 p7
#include<stdio.h>
#include<iostream>

using namespace std;

bool is_plaindrome(string s){
    int i = 0;
    int j = s.length()-1;

    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

string get_substr(int left, int right, string s){
    string temp="";

    for(int i = left; i <= right; i++){
        temp += s[i];
    }
    return temp;
}

string longestPalindrome(string s) {
    int right = 0 ;
    int left = 0;
    int start = 0;
    int end = 0;
    int n = s.length();
    if(is_plaindrome(s)){  
        return s;
    }

    for(int i = 0 ; i < n; i++){
        left = i;
        right = i+1;
        while(left >= 0 && right < n){
            if(s[left] == s[right]){
                if(end-start < right - left){
                    end = right;
                    start = left;
                }
                right++;
                left--;
            }
            else{
                break;
            }
        }

        left = i;
        right = i;
        while(left >= 0 && right < n){
            if(s[left] == s[right]){
                if(end-start < right - left){
                    end = right;
                    start = left;
                }
                right++;
                left--;
            }
            else{
                break;
            }
        }

    }

    return get_substr(start,end,s);
}

int main(){

    string s[] = {"babaddtattarrattatddetartrateedredividerb", "babad", "cbbd"}; // test cases
    
    for(string &i: s){
        cout<<longestPalindrome(i)<<endl;
    }
}