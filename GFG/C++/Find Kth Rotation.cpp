//1
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n =arr.size();
        int minEl = INT_MAX;
        int idx = -1;
        
        for(int i=0;i<n;i++){
            if(minEl>arr[i]){
                minEl = arr[i];
                idx = i;
            }
        }
        return idx;
        
    }
};

//2
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int i = 0;
        int j = n-1;
        
        while(i<j){
            int mid = i + (j-i)/2;
            
            if(arr[mid]<arr[j]){
                j = mid;
            }else{
                i = mid+1;
            }
        }
        return j;
    }
};
