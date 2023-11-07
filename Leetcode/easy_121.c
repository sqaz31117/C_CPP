// 0 <= prices[i] <= 10^4
int maxProfit(int* prices, int pricesSize) {
    int minVal = prices[0];
    int ans = 0;

    for (int i = 0; i < pricesSize; i++) {
        ans = ans > (prices[i] - minVal) ? ans : (prices[i] - minVal);
        minVal = minVal > prices[i] ? prices[i] : minVal;
    }

    return ans;
}