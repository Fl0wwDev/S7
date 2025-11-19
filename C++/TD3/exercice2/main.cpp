#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSumBruteForce(const vector<int>& nums, int target){
    for (size_t i = 0; i < nums.size(); ++i) {
        for (size_t j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return {static_cast<int>(i), static_cast<int>(j)};
            }
        }
    }
    return {};
}

vector<int> twoSumOptimal(const vector<int>& nums, int target){
    unordered_map<int, int> numMap;
    
    for (size_t i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], static_cast<int>(i)};
        }
        
        numMap[nums[i]] = i;
    }
    
    return {};
}

int main(int argc, char const *argv[])
{
    /* code */

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> indicesBruteForce = twoSumBruteForce(nums, target);
    cout << "Brute Force Solution: ["
         << indicesBruteForce[0]
         << ", "
         << indicesBruteForce[1]
         << "]"
         << endl;

    vector<int> indicesOptimal = twoSumOptimal(nums, target);
    cout << "Optimal Solution: ["
         << indicesOptimal[0]
         << ","
         << indicesOptimal[1]
         << "]"
         << endl;
    return 0;
}
