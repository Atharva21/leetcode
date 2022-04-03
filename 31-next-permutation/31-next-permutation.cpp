class Solution {
public:
    void nextPermutation(vector<int>& v) {
        const int n = v.size();
        int firstDecreasing = -1;
        for(int i=n-2;i>=0;--i) {
            if(v[i] < v[i+1]) {
                firstDecreasing = i;
                break;
            }
        }
        if(firstDecreasing == -1) {
            reverse(v.begin(), v.end());
            return;
        }
        int justLarger = -1;
        int diff = INT_MAX;
        for(int i=n-1;i>firstDecreasing;--i) {
            int d = v[i] - v[firstDecreasing];
            if(d == 1) {
                justLarger = i;
                break;
            }
            if(d < diff && d > 0) {
                diff = d;
                justLarger = i;
            }
        }
        // cout << firstDecreasing << " " << justLarger;
        swap(v[firstDecreasing], v[justLarger]);
        reverse(v.begin()+firstDecreasing+1, v.end());
    }
};