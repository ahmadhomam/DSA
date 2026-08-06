class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0 ;
        int profit = 0  ;
        int minprice = prices[0] ;

        for(int i=0;i<prices.size();i++){
            profit  = prices[i] - minprice  ;
            maxprofit = max(maxprofit,profit) ;

            minprice = min(minprice,prices[i]) ;
        }
        return maxprofit  ;
    }
};