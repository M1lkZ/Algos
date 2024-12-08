#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, k, prv = -1;
    cin >> a >> b >> c >> d >> k;
    for (size_t i = 0; i < k; i++) {
        a *= b;
        a -= c;
        if (a > d) a = d;
        if (a == prv || a <= 0) break;
        prv = a;
    }
    if (a < 0) a = 0;
    cout << a << endl;
    return 0;
}