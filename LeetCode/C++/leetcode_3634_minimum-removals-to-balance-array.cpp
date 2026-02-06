class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return 0;
        int mx = nums[0];
        int mn = nums[0];
        int l = 1;
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = 0;

        while(j<n){
            mn = nums[i];
            mx = nums[j];
            
            while(i<j and mx>(long long)k*mn){
                i++;
                mn = nums[i];
            }
            l = max(l,j-i+1);
            j++;
        }
        return n-l;
    }
};
