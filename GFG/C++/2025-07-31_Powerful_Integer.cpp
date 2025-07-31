// GFG POTD - Powerful Integer
// Date: 2025-07-31


// ************************ Brute Force ************************
class BruteSolution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        int n = intervals.size();
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++) {
            maxi = max(maxi, intervals[i][1]);
        }

        vector<int> arr(maxi + 1, 0);

        for(int i = 0; i < n; i++) {
            int s = intervals[i][0];
            int e = intervals[i][1];
            for(int j = s; j <= e; j++) {
                arr[j]++;
            }
        }

        vector<int> poss;
        for(int i = 0; i <= maxi; i++) {
            if(arr[i] >= k) {
                poss.push_back(i);
            }
        }

        return poss.empty() ? -1 : poss.back();
    }
};

// ************************ Optimal Approach ************************
class OptimalSolution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        map<int, int> mp;

        for (auto &in : intervals) {
            mp[in[0]]++;
            mp[in[1] + 1]--;
        }

        int temp = 0;
        int res = -1;

        for (auto &it : mp) {
            if (temp >= k && it.second < 0)
                res = it.first - 1;

            temp += it.second;

            if (temp >= k)
                res = it.first;
        }

        return res;
    }
};
