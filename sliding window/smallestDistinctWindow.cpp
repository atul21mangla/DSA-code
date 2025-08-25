#include<bits/stdc++.h>
using namespace std;

int func1Brute(string s){
    int n = s.length();
    
    // Step 1: Find all unique characters in the string
    unordered_set<char> st(s.begin(), s.end());
    int uniqueCount = st.size();  // Total number of unique characters
    
    int minlen = n + 1;  // To store the minimum length of substring
    
    // Step 2: Generate all substrings starting at each index `i`
    for (int i = 0; i < n; i++) {
        unordered_set<char> seen;  // Track unique characters in the current substring
        for (int j = i; j < n; j++) {
            seen.insert(s[j]);  // Add current character to the set
            
            // Step 3: Check if the substring contains all unique characters
            if (seen.size() == uniqueCount) {
                minlen = min(minlen, j - i + 1);  // Update the minimum length
                break;  // No need to expand further once all unique characters are found
            }
        }
    }
    
    return (minlen == n + 1) ? 0 : minlen;  // Return 0 if no valid substring found
}


int func2Optimal(string s){
    int n = s.length();
    
    // Get the number of unique characters in the string
    unordered_set<char> st(s.begin(), s.end());
    int uniqueCount = st.size();  // Total number of unique characters
    
    int minlen = n + 1;  // To store the minimum length of substring
    vector<int> count(256, 0);  // To count frequency of each character
    int left = 0;
    int foundUnique = 0;  // Track how many unique characters we have found
    
    // Sliding window approach
    for (int right = 0; right < n; right++) {
        // Add current character to the window
        if (count[s[right]] == 0) foundUnique++;  // New unique character in the window
        count[s[right]]++;
        
        // When we have all unique characters in the window, try shrinking it
        while (foundUnique == uniqueCount) {
            // Update the minimum length
            minlen = min(minlen, right - left + 1);
            
            // Try to shrink the window from the left
            count[s[left]]--;
            if (count[s[left]] == 0) foundUnique--;  // One unique character is no longer in the window
            left++;
        }
    }
    
    return minlen;
}

int main(){
    string s = "AABBBCBBAC";
    // cout << func1Brute(s) << endl; 
    cout << func2Optimal(s) << endl; 
    return 0;
}