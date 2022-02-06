class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        const int n = v.size();
        if(!n) return 0;
        int last = 0;
        for(int i=0;i<n;++i) {
            v[last++] = v[i];
            if(i+1 < n && v[i+1] == v[i]) {
                v[last++] = v[++i];
                while(i+1 < n && v[i+1] == v[i]) ++i;
            }
        }
        return last;
    }
};