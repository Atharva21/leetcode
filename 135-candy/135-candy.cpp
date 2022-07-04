class Solution {
private:
    void printv(vector<int> v) {
        for(auto& num: v) cout << num << " ";
        cout << endl;
    }
public:
    int candy(vector<int>& ratings) {
        const int n = ratings.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for(int i=1;i<n;++i) {
            if(ratings[i] <= ratings[i-1]) continue;
            left[i] = left[i-1] + 1;
        }
        for(int i=n-2;i>=0;--i) {
            if(ratings[i] <= ratings[i+1]) continue;
            right[i] = right[i+1] + 1;
        }
        // printv(left);
        // printv(right);
        int candies = 0;
        for(int i=0;i<n;++i) {
            candies += max(left[i], right[i]) + 1;
        }
        return candies;
    }
};