#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for (size_t i = 0; i < nums.size(); ++i) {
            mpp[nums[i]]++;
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            if (mpp[nums[i]] > 1) return true;
        }
        return false;
    }
};

/*
bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int x : nums) {
            if (!seen.insert(x).second) return true; // already present
        }
        return false;
    }*/