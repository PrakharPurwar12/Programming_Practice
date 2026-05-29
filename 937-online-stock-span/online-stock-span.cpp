class StockSpanner {
    stack<pair<int, int>> S;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while (!S.empty() && S.top().first <= price) {
            span += S.top().second;
            S.pop();
        }
        S.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */