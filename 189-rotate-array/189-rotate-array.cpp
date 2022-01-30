class Solution {
private:
    void rev(int low, int high, vector<int>& v) {
        while(low < high) {
            swap(v[low++], v[high--]);
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        const int n = nums.size();
        k %= n;
        rev(0, n-1, nums);
        rev(0, k-1, nums);
        rev(k, n-1, nums);
    }
};