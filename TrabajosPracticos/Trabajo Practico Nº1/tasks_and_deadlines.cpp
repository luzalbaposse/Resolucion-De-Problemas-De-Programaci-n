/*https://cses.fi/problemset/task/1630
*/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> tasks(n);
    for(int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second; 
    }
 
    
    sort(tasks.begin(), tasks.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });
 
    long long currentTime = 0;
    long long totalReward = 0;
    
    for(const auto& task : tasks) {
        currentTime += task.first;
        totalReward += task.second - currentTime;
    }
 
    cout << totalReward << endl; 
    return 0;


