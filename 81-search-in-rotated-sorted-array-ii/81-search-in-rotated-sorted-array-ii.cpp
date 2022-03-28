class Solution {
public:
    bool search(vector<int>& v, int target) {
        for(auto& e: v) if(e == target) return true;
        return false;
    }
};