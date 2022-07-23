class Solution {
private:
    int n;
    vector<int> result;
    vector<pair<int, int>> arr;
    void merge(int start, int end) {
        const int size = end-start+1;
        const int mid = (start + end) / 2;
        int l = start, r = mid+1, smaller=0;
        vector<pair<int, int>> merged;
        while(l <= mid && r <= end) {
            if(arr[l].first > arr[r].first) {
                ++smaller;
                merged.push_back(arr[r++]);
            } else {
                result[arr[l].second] += smaller;
                merged.push_back(arr[l++]);
            }
        }
        while(l <= mid) {
            result[arr[l].second] += smaller;
            merged.push_back(arr[l++]);
        }
        while(r <= end)
            merged.push_back(arr[r++]);
        int s = start;
        for(int i=0;i<size;++i) {
            arr[s++] = merged[i];
        }
    }
    void mergeSort(int start, int end) {
        if(start >= end) return;
        const int mid = (start + end) / 2;
        mergeSort(start, mid);
        mergeSort(mid+1, end);
        merge(start, end);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        result.resize(n, 0);
        for(int i=0;i<n;++i) arr.push_back({nums[i], i});
        mergeSort(0, n-1);
        return result;
    }
};