//1
class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int n = s.length();
        int i = 0;
        int count = 0;
        while(i<n){
            if(!st.empty() && s[i]=='a' && st.top()=='b'){
                st.pop();
                count++;
            }else{
                st.push(s[i]);
            }
            i++;
        }
        return count;
    }
};



//2
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int>rt_a(n,0);
        vector<int>lt_b(n,0);
        int b_cnt = 0;
        for(int i=0;i<n;i++){
            lt_b[i] = b_cnt;
            if(s[i]=='b'){
                b_cnt++;
            }
        }
        int a_cnt = 0;
        for(int i=n-1;i>=0;i--){
            rt_a[i] = a_cnt;
            if(s[i]=='a'){
                a_cnt++;
            }
        }
        int res = INT_MAX;
        for(int i=0;i<n;i++){
            res = min(res,lt_b[i]+rt_a[i]);
        }
        return res;
    }
};


//3 

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int>rt_a(n,0);
        int b_cnt = 0;
        int a_cnt = 0;
        for(int i=n-1;i>=0;i--){
            rt_a[i] = a_cnt;
            if(s[i]=='a'){
                a_cnt++;
            }
        }
        int res = INT_MAX;
        for(int i=0;i<n;i++){
            res = min(res,b_cnt+rt_a[i]);
            if(s[i]=='b'){
                b_cnt++;
            }
        }
        return res;
    }
};


//4
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int b_cnt = 0;
        int a_cnt = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a'){
                a_cnt++;
            }
        }
        int res = INT_MAX;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                a_cnt--;
            }
            res = min(res,b_cnt+a_cnt);
            if(s[i]=='b'){
                b_cnt++;
            }
        }
        return res;
    }
};

