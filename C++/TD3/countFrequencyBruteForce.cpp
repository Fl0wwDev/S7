#include <iostream>
#include <vector>
#include "countFrequencyBruteForce.h"
using namespace std;

void countFrequencyBruteForce(const vector<int>& numbers) {
    vector<int> visited_numbers(numbers.size(), 0);
    
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (visited_numbers[i] == 1) {
            continue;
        }
        
        int count = 1;
        for (size_t j = i + 1; j < numbers.size(); ++j) {
            if (numbers[i] == numbers[j]) {
                count++;
                visited_numbers[j] = 1;
            }
        }
        
        cout << numbers[i] << ": " << count << " times" << endl;
    }
}