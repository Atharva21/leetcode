class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int k) {
        const int n = v.size();
        vector<bool> place(n, true);
        for(int i=0;i<n;++i) {
            if(v[i]) {
                place[i] = false;
                if(i - 1 >= 0) {
                    place[i-1] = false;
                }
                if(i + 1 < n) {
                    place[i+1] = false;
                }
            }
        }
        for(int i=0;i<n;++i) {
            if(!place[i]) continue;
            if(i+1 < n) {
                if(place[i+1]) {
                    place[i+1] = false;
                }
            }
        }
        int places = 0;
        for(bool p: place) if(p) ++places;
        return k <= places;
    }
};