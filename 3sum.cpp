//15. 3 sum

#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    
    if(nums.size() <= 0 ){
        return {};
    }

    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++){

        int l = i+1;
        int r = n-1;

        if(nums[i] > 0){
            break;
        }
        
        if(i > 0 && nums[i] == nums[i-1]){
            continue;
        }

        while(l < r){

            int sum = nums[i] + nums[l] + nums[r];
            
             if(sum > 0){
                r--;
            }
            else if(sum < 0){
                l++;
            }

            else if(sum == 0){
                ans.push_back({nums[i], nums[l], nums[r]});
                l++;
                r--;

                while(l<r && nums[l] == nums[l-1]){
                    l++;
                }
                while(l<r && nums[r] == nums[r+1]){
                    r--;
                }
            }

           
        }
    }

    return ans;
}

int main(){

    //tests
    vector<vector<int>> tests = {{2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10},{-1,0,1,2,-1,-4}};

    for(vector<int> test: tests){
    vector<vector<int>> res = threeSum(test);

        for(vector<int> &re: res){
            for(int &r: re){
                cout<<r<<" ";
            }
            cout<<" || ";
        }
        cout<<endl;
    }
}