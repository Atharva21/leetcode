class Solution {
public:
    int searchInsert(vector<int>& v, int target) {
        const int n = v.size();
        int lo=0, hi=n-1, mid;
        while(lo <= hi) {
            mid = (lo+hi)/2;
            if(target > v[mid]) {
                lo = mid+1;
            } else if(target < v[mid]) {
                hi = mid-1;
            } else {
                return mid;
            }
        }
        // cout << mid << endl;
        if(target > v[mid]) {
            return mid+1;
        }
        return mid;
    }
};