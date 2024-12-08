#include <iostream>
#include <unordered_map>
#include <stack>
#include <list>

using namespace std;

list<string> create_list() {
    list<string> list;
    return list;
}

int main() {
    unordered_map<string, stack<int>> hsh;
    stack<list<string>> changes;
    changes.push(create_list());
    string cur_string;
    string variable;
    string value;
    while (cin >> cur_string) {
        size_t eq_index = cur_string.find('=');
        if (eq_index != string::npos) {
            variable = cur_string.substr(0, eq_index);
            value = cur_string.substr(eq_index+1);
        }
        if (cur_string == "{") {
            changes.push(create_list());
        } else if (cur_string == "}") {
            for (const string& change:changes.top()) {
                hsh[change].pop();
            }
            changes.pop();
        } else {
            if (!hsh.contains(variable)) {
                hsh[variable].push(0);
            }
            if (value[0] == '-' || isdigit(value[0])) {
                if (hsh[variable].top() != stoi(value)) {
                    changes.top().push_back(variable);
                    hsh[variable].push(stoi(value));
                }
            } else {
                if (!hsh.contains(value)) {
                    hsh[value].push(0);
                }
                if (hsh[variable].top() != hsh[value].top()) {
                    changes.top().push_back(variable);
                    hsh[variable].push(hsh[value].top());
                }
                cout << hsh[variable].top() << endl;
            }
        }
    }
    return 0;
}