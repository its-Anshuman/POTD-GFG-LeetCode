class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int res = 0;
        int elSum = 0;
        int temp = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            temp += i*arr[i];
            elSum += arr[i];
        }
        res = temp;
        for(int i=1;i<n;i++){
            temp = temp - elSum + arr[i-1]*n;
            res = max(res,temp);
        }
        return res;
    }
};
