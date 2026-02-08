class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n = arr.size();
        int res = INT_MIN;
        int prefix_pd = 1;
        int suffix_pd = 1;
        for(int i=0;i<n;i++){
            if(prefix_pd==0)prefix_pd = 1;
            if(suffix_pd==0)suffix_pd = 1;
            prefix_pd *= arr[i];
            suffix_pd *= arr[n-i-1];
            
            res = max(res,max(prefix_pd,suffix_pd));
        }
        return res;
    }
};
