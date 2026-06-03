#include <bits/stdc++.h>
using namespace std;

// ============================================================
// SOLUTION 1: Corrected Version (Hash Map - Increment/Decrement)
// ============================================================
// Time: O(n), Space: O(1) - at most 26 lowercase English letters
class Solution1 {
public:
    bool isAnagram(string s, string t) {
        // Different lengths can't be anagrams
        if(s.size() != t.size()) return false;
        
        unordered_map<char, int> mpp;
        
        // Increment count for s, decrement for t
        for(int i = 0; i < s.size(); i++){
            mpp[s[i]]++;
            mpp[t[i]]--;
        }
        
        // All frequencies should be 0
        for(auto it : mpp){
            if(it.second != 0)
                return false;
        }
        return true;
    }
};

// ============================================================
// SOLUTION 2: Optimal (Frequency Array)
// ============================================================
// Time: O(n), Space: O(1) - fixed array of 26 characters
// MOST EFFICIENT: Only lowercase English letters
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        // Fixed array for 26 lowercase English letters
        int freq[26] = {0};
        
        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        
        // Check if all frequencies are 0
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0) return false;
        }
        return true;
    }
};

// ============================================================
// SOLUTION 3: Sorting Approach
// ============================================================
// Time: O(n log n), Space: O(1)
class Solution3 {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }
};

// ============================================================
// SOLUTION 4: Hash Map (Frequency Comparison)
// ============================================================
// Time: O(n), Space: O(1)
class Solution4 {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        unordered_map<char, int> freq;
        
        // Count frequencies in s
        for(char c : s){
            freq[c]++;
        }
        
        // Subtract frequencies from t
        for(char c : t){
            freq[c]--;
            if(freq[c] < 0) return false;  // t has more of this char than s
        }
        
        // All frequencies should be 0
        for(auto p : freq){
            if(p.second != 0) return false;
        }
        return true;
    }
};

int main(){
    Solution2 sol;
    
    // Test cases
    cout << sol.isAnagram("anagram", "nagaram") << endl;    // 1 (true)
    cout << sol.isAnagram("rat", "car") << endl;             // 0 (false)
    cout << sol.isAnagram("a", "a") << endl;                 // 1 (true)
    cout << sol.isAnagram("ab", "ba") << endl;               // 1 (true)
    
    return 0;
}
