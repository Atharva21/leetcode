class Solution {
private:
    static bool comparator(const vector<int>& a, const vector<int>& b) {
        if(a[0] != b[0])
            return a[0] < b[0];
        return a[1] > b[1];
    }
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), comparator);
        const int n = properties.size();
        int ans = 0;
        // for(auto& p: properties)
        //     cout << p[0] << " " << p[1] << endl;
        int maxDefense = INT_MIN;
        for(int i=n-1;i>=0;--i) {
            if(properties[i][1] < maxDefense)
                ++ans;
            maxDefense = max(maxDefense, properties[i][1]);
        }
        return ans;
    }
};