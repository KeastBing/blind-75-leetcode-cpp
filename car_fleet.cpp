//853. Car Fleet

#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) {

    if(position.size() == 0){
        return 0;
    }

    vector<pair<int,int>> cars;
    int fleets = 1;
    int n = position.size();

    for(int i = 0 ; i < position.size(); i++){
        cars.push_back({position[i], speed[i]});
    }
    sort(cars.rbegin(), cars.rend());

    float prev_time = (float)(target  - cars[0].first)/cars[0].second;

    for(int i = 1 ; i < n ; i++){
        
        float dist = target - cars[i].first;
        float time = dist/cars[i].second;

        if(prev_time <  time){
            fleets++;
            prev_time = time;
        }
    }

    return fleets;

}

int main(){
    //test
    int target  = 10;
    vector<int> pos = {4,1,0,7};
    vector<int> speed = {2,2,1,1};


    int ans = carFleet(target, pos, speed);
    cout<<ans;
}