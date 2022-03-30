class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        const int m = v.size();
        const int n = v[0].size();
        int lo = 0;
        int hi = m-1;
        while(lo < hi) {
            // cout << lo << " " << hi << endl;
            int mid = (lo+hi)/2;
            if(v[mid][0] == target) return true;
            if(v[mid][0] < target)
                lo = mid+1;
            else
                hi = mid-1;
        }
        int row = lo;
        if(row != 0 && target < v[row][0]) --row;
        // cout << lo << " " << hi << endl;
        lo=0;hi=n-1;
        while(lo <= hi) {
            int mid = (lo+hi)/2;
            if(v[row][mid] == target) return true;
            if(v[row][mid] < target) lo = mid+1;
            else hi = mid-1;
        }
        return false;
    }
};