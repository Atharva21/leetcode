class Solution {
public:
    int addDigits(int num) {
        int ans = 0;
        while(num || ans) {
            if(!num) {
                if(ans / 10 == 0) break;
                num = ans;
                ans = 0;
            }
            ans += num%10;
            num /= 10;
        }
        return ans;
    }
};