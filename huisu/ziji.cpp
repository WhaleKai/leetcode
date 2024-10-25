#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> result;
vector<int> path;

void backTracking(vector<int>& nums, int index){
    result.push_back(path);

    for (int i = index; i < nums.size(); i++){
        path.push_back(nums[i]);
        backTracking(nums, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums){
    backTracking(nums, 0);
    return result;
}

int main(){
    // input
    vector<int> nums = {1, 2, 3};
    // process
    vector<vector<int>> output = subsets(nums);
    // output
    cout << "[";
    for (int i = 0; i < output.size(); i++){
        cout << "[";
        for (int j = 0; j < output[i].size(); j++){
            cout << output[i][j] << ", ";
        }
        if(!output[i].empty())
            cout << "\b\b";
        cout << "], ";
    }
    cout << "\b\b] " << endl;

    return 0;
}