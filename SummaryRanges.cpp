/*
228. Summary Ranges
Given a sorted integer array without duplicates, return the summary of its ranges.
Example 1:
Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
Example 2:
Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.

From <https://leetcode.com/problems/summary-ranges/description/>


*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;

        for(int i = 0; i < nums.size(); i++) {
            int current = nums[i];
            bool flag = false;
            while(nums[i] == nums[i+1]-1) {
                flag = true;
                i++;
            }
            if(flag) {
                result.push_back(to_string(current)+"->"+to_string(nums[i]));
            } else {
                result.push_back(to_string(nums[i]));
            }
        }

        return result;
    }
};

