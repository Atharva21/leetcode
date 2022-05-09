class Solution {
private:
    vector<string> ans;
    unordered_map<char, string> letters;
    string digits;
    int n;
    void dfs(int i=0, string cur="") {
        if(i == n) {
            ans.push_back(cur);
            return;
        }
        for(auto& letter: letters[digits[i]]) {
            dfs(i+1, cur+letter);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        n = digits.size();
        if(n == 0) return {};
        letters['2'] = "abc";
        letters['3'] = "def";
        letters['4'] = "ghi";
        letters['5'] = "jkl";
        letters['6'] = "mno";
        letters['7'] = "pqrs";
        letters['8'] = "tuv";
        letters['9'] = "wxyz";
        dfs();
        return ans;
    }
};