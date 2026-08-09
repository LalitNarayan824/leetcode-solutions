class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), [](int a , int b){
            return a>b;
        });
    sort(discounts.begin(), discounts.end(),  [](int a , int b){
            return a>b;
        });

    int d = discounts.size();
    int n = prices.size();
    vector<double> ans(n);

    int index = 0;
    for (int i=0;i<d & i<n;i++) {
        ans[index] = prices[index] * (100.0 - discounts[i]) / 100.0;
        index++;
    }

    for (int i = index; i<n; i++) {
        ans[i] = prices[i];
    }

    double temp = 0.0;
    for (auto it : ans) temp += it;

    return temp;
        
    }
};