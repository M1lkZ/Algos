#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;
    int coords[n];
    for (int i = 0; i < n; i++) std::cin >> coords[i];
    int left = 0;
    int right = coords[n-1];
    while (right > left) {
        int guess = (right + left) / 2;
        int fit = 1;
        int last = coords[0];
        for (int i = 0; i < n; i++) {
            if (coords[i] - last > guess) {
                fit++;
                last = coords[i];
            }
        }
        if (fit >= k) {
            left = guess + 1;
        } else {
            right = guess;
        }
    }
    std::cout << left << std::endl;
    return 0;
}