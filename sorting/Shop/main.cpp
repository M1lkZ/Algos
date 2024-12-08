#include <iostream>
#include <algorithm>

int main(){
    int n, k;
    int ans = 0;
    std::cin >> n >> k;
    int prices[n];
    for (int i = 0; i < n; i++) std::cin >> prices[i];
    std::sort(prices, prices + n, std::greater<int>());
    for (int i = 0; i < n; i++) {
        if ((i + 1) % k != 0) ans += prices[i];
    }
    std::cout << ans << std::endl;
}