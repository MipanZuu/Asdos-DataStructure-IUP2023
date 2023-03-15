/*
 *
 * CHORES.cpp
 * author  : Muhammad Ghifari Taqiuddin
 * created : Thursday, 09 March 2023 at 14:59
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

// first: task priority, second: task name
using pis = pair<int, string>;

int main() {
  // sort in increasing order
  priority_queue<pis, vector<pis>, greater<pis>> pq;

  int e, n;
  cin >> e >> n;

  while (n--) {
    string s;
    int i;

    cin >> i >> s;
    pq.push({i, s});
  }

  bool possible = false;

  while (!pq.empty() && e - pq.top().first >= 0) {
    pis top = pq.top();
    pq.pop();

    e -= top.first;
    cout << top.second << "\n";
    possible = true;
  }

  if (!possible) {
    cout << "Let Pak Aya do the rest\n";
  }

  return 0;
}
