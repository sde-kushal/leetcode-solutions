#include <vector>
using namespace std;

class StockSpanner {
private:
    vector<pair<int,int>> prices;

public:
    StockSpanner() {    
    }
    
    int next(int price) {
        if(prices.size() == 0) {
            prices.push_back({ price, 1 });
            return 1;
        }

        int span = 1;
        
        if(prices[prices.size()-1].first == price)
            span += prices[prices.size()-1].second;
        else if(prices[prices.size()-1].first < price) {
            int i = prices.size()-1;
            while(i>=0 && prices[i].first <= price) {
                span += prices[i].second;
                i = i-prices[i].second;
            }
        }

        prices.push_back({ price, span });
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */