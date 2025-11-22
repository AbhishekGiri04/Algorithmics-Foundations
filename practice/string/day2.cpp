/*
LeetCode Problem 344: Reverse String
Difficulty: Easy
Topic: Two Pointers / String / Array

Problem Statement:
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Example:
Input:  ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st; // Stack to reverse characters
        
        // Push all characters onto the stack
        for(char ch : s){
            st.push(ch);
        }

        int i = 0;
        // Pop from stack and overwrite array
        while(!st.empty()){
            s[i] = st.top();
            st.pop();
            i++;
        }
    }
};

// Example usage (for testing)
int main() {
    Solution sol;
    vector<char> s = {'h','e','l','l','o'};
    
    sol.reverseString(s);

    cout << "Reversed String: ";
    for(char c : s){
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
