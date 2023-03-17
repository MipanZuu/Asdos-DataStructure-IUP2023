/*
 *
 * by Muhammad Ghifari Taqiuddin
 * created on Tue, 31 May 2022
 *
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(NULL)->sync_with_stdio(false);

  int m, n;
  cin >> m >> n;

  deque<int> X, Y, Res;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    X.push_back(x);
  }

  for (int i = 0; i < n; i++) {
    int y;
    cin >> y;
    Y.push_back(y);
  }

  // fill the remaining empty with 0
  // so we can have same length
  if (m > n) {
    while (Y.size() != m) {
      Y.push_front(0);
    }
  } else {
    while (X.size() != n) {
      X.push_front(0);
    }
  }

  // save the result into vector first
  for (int i = 0; i < Y.size(); i++) {
    Res.push_back(X[i] + Y[i]);
  }

  // then process from back
  for (int i = Res.size() - 1; i >= 1; i--) {
    // add 1 (carry) to next val before back
    // if current is >= 10
    if (Res[i] >= 10) {
      Res[i] %= 10;
      Res[i - 1] += 1;
    }
  }

  cout << '[';
  for (int i = 0; i < Res.size(); i++) {
    cout << Res[i];
  }
  cout << "]\n";
}
