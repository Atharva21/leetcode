class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        auto power = log2(n) / log2(4);
        return floor(power) == ceil(power);
    }
};