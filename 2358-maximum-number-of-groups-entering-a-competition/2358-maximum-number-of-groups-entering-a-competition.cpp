class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        const int n = grades.size();
        sort(grades.begin(), grades.end());
        int ans = 0;
        int sum=0, grpsize=0, lastsum=INT_MIN, lastgrpsize=0;
        for(int i=0;i<n;++i) {
            sum += grades[i];
            ++grpsize;
            if(sum > lastsum && grpsize > lastgrpsize) {
                ++ans;
                lastsum = sum;
                lastgrpsize = grpsize;
                sum = 0;
                grpsize = 0;
            }
        }
        return ans;
    }
};