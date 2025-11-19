#include <iostream>
#include <queue>
#include <stack>
#include <cctype>

using namespace std;

bool isPalindrome(const string& input) {
    int left = 0;
    int right = input.length() - 1;
    
    while (left < right) {
        if (input[left] != input[right]) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}


int main(int argc, char const *argv[])
{
    string test1 = "radar";
    string test2 = "salut";
    string test3 = "kayak";
    string test4 = "jadore le c++";
    string test5 = "ab";
    
    cout << "\"" << test1 << "\" est un palindrome ? " 
         << (isPalindrome(test1) ? "true" : "false") << endl;
    
    cout << "\"" << test2 << "\" est un palindrome ? " 
         << (isPalindrome(test2) ? "true" : "false") << endl;
    
    cout << "\"" << test3 << "\" est un palindrome ? " 
         << (isPalindrome(test3) ? "true" : "false") << endl;
    
    cout << "\"" << test4 << "\" est un palindrome ? " 
         << (isPalindrome(test4) ? "true" : "false") << endl;
    
    cout << "\"" << test5 << "\" est un palindrome ? " 
         << (isPalindrome(test5) ? "true" : "false") << endl;
    
    return 0;
}
