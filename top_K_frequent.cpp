//347 Top K Frequent Elements

#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
      
    unordered_map<int,int> tracking;
    int len = nums.size();
    vector<int> freq(len,0);
    vector<int> ans;

    for(int &num: nums){

        tracking[num]++;
    }

    for(auto &i: tracking){
        freq[i.second] = i.first;
    }

    for(int i = nums.size(); i > 0; i--){
        if(freq[i] > 0){
            ans.push_back(freq[i]);
        }
    }

    if(ans.empty()){
        for(int i = 0; i < k; i++){
            ans.push_back(0);
        }
    }

    return ans;
}

int main(){
    //tests
    vector<vector<int>> tests = {{1,1,1,2,2,3},{1,2,3,4,5,2,3},{},{1}};

    for(vector<int> test : tests){
        vector<int> ans = topKFrequent(test,2);

        for(int &i: ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
}