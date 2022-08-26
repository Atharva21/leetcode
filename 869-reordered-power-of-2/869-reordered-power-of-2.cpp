class Solution {    
public:
    bool reorderedPowerOf2(int n) {
        vector<vector<int>> powerDigitCount;
        powerDigitCount.resize(32, vector<int>(10, 0));
        
        for(int i=0;i<31;++i) {
            int powerOfTwo = (int)pow(2, i);
            while(powerOfTwo) {
                int digit = powerOfTwo % 10;
                ++powerDigitCount[i][digit];
                powerOfTwo /= 10;
            }
        }
        
        vector<int> inputDigitCount(10, 0);
        while(n) {
            int digit = n % 10;
            ++inputDigitCount[digit];
            n /= 10;
        }
        
        for(int i=0;i<31;++i) {
            if(inputDigitCount == powerDigitCount[i])
                return true;
        }
        
        return false;
    }
};