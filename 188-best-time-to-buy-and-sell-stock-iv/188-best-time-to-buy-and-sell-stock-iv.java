class Solution {
    
    private int[] prices;
    private int n;
    
    private int greedy() {
        // buy everyday, and sell if price goes high.
        int lastBuy = Integer.MAX_VALUE;
        int profit = 0;
        for(int price: prices) {
            if(price > lastBuy) profit += price - lastBuy;
            lastBuy = price;
        }
        return profit;
    }
    
    public int maxProfit(int k, int[] prices) {
        this.prices = prices;
        n = prices.length;
        if(n < 2 || k == 0)
            return 0;
        if(k >= n/2) {
            // no cap on how many transactions we can make.
            return greedy();
        }
        int[] buy = new int[k+1];
        int[] sell = new int[k+1];
        Arrays.fill(buy, Integer.MIN_VALUE);
            
        for(int i=0;i<n;++i) {
            for(int j=1;j<=k;++j) {
                buy[j] = Math.max(buy[j], sell[j-1] - prices[i]);
                sell[j] = Math.max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }
}































