#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main() {
    int numEntries, maxCars, numHistory, carCount = 0;
    cin >> numEntries >> maxCars >> numHistory;

    vector<vector<int>> entryVec(numEntries);
    vector<int> historyVec(numHistory);
    for (int i = 0; i < numHistory; i++) {
        cin >> historyVec[i];
        entryVec[--historyVec[i]].push_back(i);
    }

    map<int, int> carMap;
    priority_queue<pair<int, int>> idQueue;
    for (int i = 0; i < numHistory; i++){
        int current = historyVec[i];
        if (!entryVec[current].empty()) entryVec[current].erase(entryVec[current].begin());

        if (carMap.find(current) == carMap.end()){
            if (carMap.size() >= maxCars) {
                carMap.erase(idQueue.top().second);
                idQueue.pop();
            }
            carCount++;
            carMap[current] = 1;
        }
        if (entryVec[current].empty()) idQueue.push({2147483646, current});
        else idQueue.push({entryVec[current][0], current});
    }
    cout << carCount << endl;
    return 0;
}