class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // code here.
        int n = a.size();
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        
        int i = 0;
        int j = 0;
        int k = 0;
        int ans = INT_MAX;
        
        vector<int>res(3,0);
        
        while(i<n and j<n and k<n){
            int mn = INT_MAX;
            int mx = INT_MIN;
            
            int a1 = a[i];
            int b1 = b[j];
            int c1 = c[k];
            
            mn = min(mn,min(a1,b1));
            mn = min(mn,c1);
            mx = max(mx, max(a1,b1));
            mx = max(mx,c1);
            
            int f = ans;
            ans = min(ans,mx-mn);
            if(f != ans){
                res[0] = a1;
                res[1] = b1;
                res[2] = c1;
            }
            if(mn==a1){
                i++;
            }else if(mn == b1){
                j++;
            }else{
                k++;
            }
        }
        sort(res.begin(),res.end(),greater<int>());
        return res;;
    }
};
