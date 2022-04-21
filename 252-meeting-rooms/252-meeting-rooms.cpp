class Solution {
private:
    struct less_than_key {
        inline bool operator() (const vector<int>& v1, const vector<int>& v2) {
            return v1[1] < v2[1];
        }
    };
    // bool compare(vector<int> v1, vector<int> v2) {
    //     return v1[1] < v2[1];
    // }
public:
    bool canAttendMeetings(vector<vector<int>>& v) {
        const int n = v.size();
        if(!n) return true;
        sort(v.begin(), v.end(), less_than_key());
        // cout << v[0][0] << ":" << v[0][1] << " ";
        for(int i=1;i<n;++i) {
            // cout << v[i][0] << ":" << v[i][1] << " ";
            if(v[i-1][1] > v[i][0]) return false;
        }
        return true;
    }
};