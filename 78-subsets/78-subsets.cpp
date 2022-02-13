class Solution {
private:
    vector<int> v;
    int n;
    set<vector<int>> s;
    void helper(int i, vector<int> cur) {
        if(i == n) {
            s.insert(cur);
            return;
        }
        helper(i+1, cur);
        cur.push_back(v[i]);
        helper(i+1, cur);
        cur.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        v = nums;
        n = v.size();
        helper(0, {});
        vector<vector<int>> ans;
        for(auto x: s) ans.push_back(x);
        return ans;
    }
};