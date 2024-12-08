#include <iostream>
#include <vector>

using namespace std;

void depth_first_search(int node, vector<pair<vector<int>, int>>& graph, int& cycle_count) {
    graph[node].second = 1;
    for (int next_node : graph[node].first) {
        switch(graph[next_node].second) {
            case 0:
                depth_first_search(next_node, graph, cycle_count);
                break;
            case 1:
                cycle_count++;
                break;
            default:
                break;
        }
    }
    graph[node].second = 2;
}

int main() {
    int n, input_key, cycles = 0;
    cin >> n;
    vector<pair<vector<int>, int>> graph(n);

    for (int i = 0; i < n; i++) {
        cin >> input_key;
        graph[input_key - 1].first.push_back(i);
    }

    for (int i = 0; i < n; i++) {
        if (graph[i].second == 0) {
            depth_first_search(i, graph, cycles);
        }
    }
    cout << cycles << endl;

    return 0;
}