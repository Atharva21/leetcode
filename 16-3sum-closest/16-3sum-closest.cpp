class Solution {
public:
    int threeSumClosest(vector<int>& v, int target) {
        const int n = v.size();
        sort(v.begin(), v.end());
        int ans = v[0]+v[1]+v[2];
        for(int i=0;i<n-2;++i) {
            if(i > 0 && v[i-1] == v[i]) continue;
            int l = i+1, r = n-1;
            while(l < r) {
                int cur = v[i]+v[l]+v[r];
                if(cur == target) {return cur;}
                if(abs(target-cur) < abs(target-ans)) {
                    ans = cur;
                }
                if(cur > target)
                    --r;
                else
                    ++l;
            }
        }
        return ans;
    }
};