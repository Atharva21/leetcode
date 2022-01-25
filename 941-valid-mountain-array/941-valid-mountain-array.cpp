class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        const int n = arr.size();
        if(n < 2 || arr[1] < arr[0]) return false;
        bool inc = true;
        for(int i=0;i+1<n;++i) {
            if(inc) {
                if(arr[i+1] == arr[i]) return false;
                if(arr[i+1] < arr[i]) {
                    inc = false;
                }
            } else {
                if(arr[i+1] >= arr[i]) return false;
            }
        }
        if(inc) return false;
        return true;
    }
};