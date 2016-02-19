// Source : https://leetcode.com/problems/container-with-most-water/
// Author : Elvis Kwok
// Date   : 2015-12-02

/********************************************************************************** 
 * 
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at 
 * coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i 
 * is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a 
 * container, such that the container contains the most water.
 * 
 * Note: You may not slant the container.
 *               
 **********************************************************************************/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // soulmachine solution: greedy algorithm
    // two pointers scant from two sides to middle, abandon the small side
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int maxArea = 0;
        while (start < end) {
            int area = min(height[end], height[start]) * (end-start);
            maxArea = max(maxArea, area);
            // cause unnecessary 'area' caclulation
            //height[start] < height[end] ? start++ : right-- ;
            if (height[start] < height[end]) {
                do {
                    start++;
                } while (start < end && height[start-1] >= height[start]);
            } else {
                do {
                    end--;
                } while (start < end && height[end+1] >= height[end]);
            }
        }
        return maxArea;
    }
};

int main(int argc, char **argv)
{
    Solution s;

    if (argc < 2)
        return 0;

    return 0;
}
