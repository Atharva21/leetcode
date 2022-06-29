class Solution {
private:
    struct less_than_key {
        inline bool operator() (const vector<int>& v1, const vector<int>& v2) {
            return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] > v2[0];
        }
    };
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), less_than_key());
        vector<vector<int>> res;
        for (auto p : people) {
            // cout << p[0] << " " << p[1] << endl;
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }
};