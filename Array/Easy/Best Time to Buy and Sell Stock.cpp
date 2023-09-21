/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
*/

/*Approach
To solve this problem, I employed a straightforward approach that iterates through the array of stock prices. 
At each step, I kept track of the minimum stock price seen so far (min_price) and calculated the potential 
profit that could be obtained by selling at the current price (prices[i] - min_price). 
I updated the maxprof (maximum profit) variable with the maximum of its current value and the 
calculated profit. Additionally, I updated the min_price to be the minimum of the current stock price and the 
previously seen minimum.

Complexity
Time complexity: O(n)O(n)O(n)
The algorithm iterates through the array of stock prices once, performing constant-time operations at each step. Therefore, the time complexity is linear in the size of the input array.

Space complexity: O(1)O(1)O(1)
The algorithm uses a constant amount of extra space to store variables like min_price and maxprof. The space complexity remains constant regardless of the size of the input array.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int maxprof = 0;

        for(int i=1;i<prices.size();i++){
            maxprof = max(maxprof,prices[i]-min_price);
            min_price = min(prices[i],min_price);
        }

        return maxprof;
    }
};