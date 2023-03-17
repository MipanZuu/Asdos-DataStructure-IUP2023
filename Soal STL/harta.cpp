#include <bits/stdc++.h>
using namespace std;

/*
 * Just scan from the back of the list
 * get the number there (n), do n loops to see whether the element count
 * is the same as n, and if it is, pop the list n times
 *
 */

void scan(vector<int> &V) {
  int back = V.back();
  int cnt = 1;
  for (int i = V.size() - 1; i > 0; i--) {
    if (V[i - 1] == back) {
      cnt++;
    } else {
      break;
    }
  }

  if (cnt == back) {
    while (cnt--) {
      V.pop_back();
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> V;

  while (n--) {
    int b;
    cin >> b;
    V.push_back(b);

    scan(V);
    cout << V.size() << '\n';
  }
}
