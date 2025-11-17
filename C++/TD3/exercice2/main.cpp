#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSumBruteForce(const vector<int>& nums, int target){
}

vector<int> twoSumOptimal(const vector<int>& nums, int target){
}

int main(int argc, char const *argv[])
{
    /* code */

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> indicesBruteForce = twoSumBruteForce(nums, target);
    cout << "Brute Force Solution:"
         << "indicesBruteForce[0]"
         << ","
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
