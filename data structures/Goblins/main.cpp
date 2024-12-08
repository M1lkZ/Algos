#include <deque>
#include <iostream>

using namespace std;

deque<int> first_half, second_half;

void balance_queues() {
    if (first_half.size() > second_half.size() + 1) {
        second_half.push_front(first_half.back());
        first_half.pop_back();
    } else if (first_half.size() < second_half.size()) {
        first_half.push_back(second_half.front());
        second_half.pop_front();
    }
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        char operation;
        cin >> operation;
        if (operation == '-') {
            cout << first_half.front() << endl;
            first_half.pop_front();
        } else {
            int goblin_id;
            cin >> goblin_id;
            if (operation == '+') {
                second_half.push_back(goblin_id);
            } else if (operation == '*') {
                first_half.push_back(goblin_id);
            }
        }
        balance_queues();
    }
    return 0;
}