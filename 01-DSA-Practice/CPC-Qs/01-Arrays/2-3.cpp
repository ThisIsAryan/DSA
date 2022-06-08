//All Problems of Type Best Time to Buy and Sell Stock Solutions

//Best Time to Buy and Sell Stock
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    // Time Complexity:- O(N)
    // Space Complexity:- O(1)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_buy_cost = prices[0],max_profit = 0;
        for(int i=1;i<n;i++){
            // sell the stock now
            max_profit = max(max_profit,prices[i]-min_buy_cost);
            
            // buy the stock now
            min_buy_cost = min(min_buy_cost,prices[i]);
        }
        return max_profit;
    }
};
//Best Time to Buy and Sell Stock II
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
public:
    // Time Complexity:- O(N)
    // Space Complexity:- O(1)
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i=1;i<prices.size();i++)
            ans += max(prices[i]-prices[i-1],0);
        return ans;
    }
};
//Best Time to Buy and Sell Stock III
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
class Solution {
public:
	// Time Complexity:- O(N)
	// Space Complexity:- O(1)
    int maxProfit(vector<int>& prices) {
        int first_buy = INT_MIN,second_buy = INT_MIN;
        int ans1 = 0,ans2 = 0;
        for(auto num:prices){
            ans2 = max(ans2,second_buy+num);
            second_buy = max(second_buy,ans1-num);
            ans1 = max(ans1,first_buy+num);
            first_buy = max(first_buy,-num);
        }
        return max(ans1,ans2);
    }
};
//Best Time to Buy and Sell Stock IV
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
class Solution {
public:
    // Time Complexity:- O(NK)
    // Space Complexity:- O(K)
    int maxProfit(int k,vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> buy(2,vector<int>(k+1,INT_MIN));
        vector<vector<int>> sell(2,vector<int>(k+1,INT_MIN));
        sell[0][0] = sell[1][0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                // buy this stock now in jth transaction
                if(sell[(i-1)%2][j-1]!=INT_MIN)
                    buy[i%2][j] = max(buy[i%2][j],sell[(i-1)%2][j-1]-prices[i-1]);

                // don't buy this stock in jth transaction
                buy[i%2][j] = max(buy[i%2][j],buy[(i-1)%2][j]);

                // sell this stock in jth transaction
                if(buy[(i-1)%2][j]!=INT_MIN)
                    sell[i%2][j] = max(sell[i%2][j],buy[(i-1)%2][j]+prices[i-1]);

                // don't sell this stock in jth transaction
                sell[i%2][j] = max(sell[i%2][j],sell[(i-1)%2][j]);
            }
        }
        int ans = 0;
        for(int j=0;j<=k;j++)
            ans = max(ans,sell[n%2][j]);
        return ans;
    }
};
//Best Time to Buy and Sell Stock With Cooldown
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
class Solution {
public:
    // Time Complexity:- O(N)
    // Space Complexity:- O(N)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(n,INT_MIN),sell(n,INT_MIN);
        
        // buy[i] = maxm profit by considering first i stocks and buying ith stock now
        // sell[i] = maxm profit by considering first i stocks and selling ith stock now
        
        buy[0] = -prices[0];
        sell[0] = 0;
        for(int i=1;i<n;i++){
            // buy the stock now
            if(i-2>=0)
                buy[i] = max(buy[i],sell[i-2]-prices[i]);
            else
                buy[i] = max(buy[i],-prices[i]);
            // don't buy the stock now
            buy[i] = max(buy[i],buy[i-1]);
            
            // sell the stock now
            sell[i] = max(sell[i],buy[i-1]+prices[i]);
            
            // don't sell the stock now
            sell[i] = max(sell[i],sell[i-1]);
        }
        
        return sell.back();
    }
};
//Best Time to Buy and Sell Stock With Transaction Fee
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
class Solution {
public:
    // Time Complexity:- O(N)
    // Space Complexity:- O(1)
    int maxProfit(vector<int>& prices, int fee)
    {
        int n = prices.size();
        
        if(n<2)
            return 0;
        
        // define two dynamic programming states
        
        //vector<int> buy(n,INT_MIN);
        //vector<int> sell(n,INT_MIN);
        
        // base case
        
        // when the first item is bought
        
        int buy = -prices[0];
        
        // if item can't be sell
        
        int sell = 0;
        for(int i=1;i<n;i++)
        {
            // person do nothing
            // person buys the stock from previous maxm sell status
            
            int new_buy = max(buy,sell-prices[i]);
            
            // person sells the stock or holds the previous stock
            
            int new_sell = max(sell,buy+prices[i]-fee);
         
            buy = new_buy;
            sell = new_sell;
        }
        // answer will be sell[last day]
        return sell;
    }
};