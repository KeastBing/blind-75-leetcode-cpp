#include<stdio.h>
#include<iostream>
#include<vector>


using namespace std;

int trap(vector<int>& height) {

    if(height.size() <= 0){
        return {};
    }
    
    int l = 0, r = height.size() - 1;
    int max_left = height[l], max_right = height[r];
    int trapped_water = 0;

    while(l < r){
        
        if(max_left < max_right){
            l++;
            max_left = max(max_left, height[l]);
            cout<<max_left<<"____"<<height[l]<<endl;;
            trapped_water += max_left - height[l];
        }
        else{
            r--;
            max_right = max(max_right, height[r]);
            cout<<max_right<<"____"<<height[r]<<endl;;
            trapped_water += max_right - height[r];
        }

        cout<<trapped_water<<endl;
    }
    return trapped_water;
}

int main(){

    vector<int> test = {0,2,0,3,1,0,1,3,2,1};

    int ans = trap(test);
    cout<<ans;
}