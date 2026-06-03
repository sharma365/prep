#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int max_area = 0;

        while (left < right) {
            int height = min(heights[left], heights[right]);
            int width = right - left;
            max_area = max(max_area, height * width);

            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};
