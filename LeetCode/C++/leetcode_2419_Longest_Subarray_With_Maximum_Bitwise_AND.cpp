# LeetCode POTD - 2419_Longest Subarray With Maximum Bitwise AND
# Date: 2025-07-30

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int res = 1;
        int currLen = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==maxi){
                currLen++;
            }else{
                res = max(res,currLen);
                currLen = 0;
            }

        }
        res = max(res,currLen);
        return res;
    }
};
