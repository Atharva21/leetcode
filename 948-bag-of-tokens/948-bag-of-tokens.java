class Solution {    
    public int bagOfTokensScore(int[] tokens, int power) {
        final int n = tokens.length;
        Arrays.sort(tokens);
        int score = 0, low=0, high=n-1;
        while(low <= high) {
            if(power >= tokens[low]) {
                // System.out.println("scored " + tokens[low]);
                power -= tokens[low++];
                ++score;
                continue;
            }
            // power < tokens[low]
            // check if the extra power from high will get us more score?
            if(low != high && (power+tokens[high] >= tokens[low]) && score > 0) {
                // System.out.println("used " + tokens[high]);
                --score;
                power += tokens[high--];
            } else
                break;
        }
        return score;
    }
}