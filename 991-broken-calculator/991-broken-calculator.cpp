class Solution {
public:
    int brokenCalc(int start, int target) {
        int steps = 0;
        while(target > start) {
            if(target % 2) {
                steps += 2;
                target = (target+1) / 2;
            } else {
                ++steps;
                target /= 2;
            }
        }
        steps += (start - target);
        return steps;
    }
};