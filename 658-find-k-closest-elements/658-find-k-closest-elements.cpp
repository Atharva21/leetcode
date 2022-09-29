class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int n = arr.size();
        deque<int> dq;
        if(!n || k > n)
            return {};
        const auto& lb = lower_bound(arr.begin(), arr.end(), x);
        int lo;
        if(lb == arr.end())
            lo = n-1;
        else {
            if(lb == arr.begin()) {
                lo = 0;
            } else {
                const auto& p = prev(lb);
                if(abs(*p - x) <= abs(*lb - x)) {
                    lo = (int)(p - arr.begin());
                } else {
                    lo = (int)(lb - arr.begin());
                }
            }            
        }
        int hi = lo+1;
        
        // cout << lo << " " << hi;
        
        while((lo >= 0 || hi < n) && k--) {
            if(lo < 0) {
                dq.push_back(arr[hi++]);
            } else if (hi >= n) {
                dq.push_front(arr[lo--]);
            } else {
                int ldiff = abs(x-arr[lo]);
                int rdiff = abs(x-arr[hi]);
                if(rdiff < ldiff) {
                    dq.push_back(arr[hi++]);
                } else {
                    dq.push_front(arr[lo--]);
                }
            }
        }
        
        vector<int> ans;
        while(!dq.empty()) {
            ans.push_back(dq.front());
            dq.pop_front();
        }
        return ans;
    }
};





