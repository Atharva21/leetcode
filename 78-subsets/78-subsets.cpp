class Solution {
private:
    vector<int> v;
    int n;
    vector<vector<int>> ans;
    void helper(int i, vector<int> cur) {
        if(i == n) {
            ans.push_back(cur);
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
        return ans;
    }
};