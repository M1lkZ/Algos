#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool flag = false;
    int max_len = -1;
    int start_ind = 0;
    vector<int> indexes {0,0};
    vector<int> flowers(n);
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &flowers[i]);
    }
    for (int i = 0; i < flowers.size(); i++) {
        if((flowers[i] != flowers[i + 1]) && flag) {
            flag = false;
        }
        if ((flowers[i] == flowers[i + 1]) && flag) {
            if (i - start_ind > max_len) {
                indexes[0] = start_ind + 1;
                indexes[1] = i + 1;
                max_len = i - start_ind;
            }
            start_ind = i;
        }
        if(flowers[i] == flowers[i + 1]) flag = true;
        if ((i == n - 1) && (i - start_ind > max_len)) {
            indexes[0] = start_ind + 1;
            indexes[1] = i + 1;
        }
    }
    cout << indexes[0] << " " << indexes[1];
    return 0;
}