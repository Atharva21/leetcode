class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();
        int start=0, total=0, current=0;
        for(int i=0;i<n;++i) {
            int diff = gas[i] - cost[i];
            total += diff;
            current += diff;
            if(current < 0) {
                current = 0;
                start = i+1;
            }
        }
        return total < 0 ? -1 : start;
    }
};