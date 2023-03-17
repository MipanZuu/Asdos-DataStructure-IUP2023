#include <bits/stdc++.h>
using namespace std;

vector<string> dirs{"home", "anton"};

void solve() {
  string cmd;
  cin >> cmd;

  if (cmd == "goto") {
    string dir;
    cin >> dir;
    dirs.push_back(dir);
  } else if (cmd == "goback") {
    if (!dirs.empty()) {
      dirs.pop_back();
    } else {
      cout << "cannot go back\n";
    }
  } else if (cmd == "whereami") {
    if (!dirs.empty()) {
      int size = dirs.size() - 1;
      for (int i = 0; i < size; i++) {
        cout << dirs[i] << "/";
      }
      cout << dirs[size] << "\n";
    } else {
      cout << "i am nowhere\n";
    }
  } else {
    cout << "Query not found\n";
  }
}

int main() {
  int q;
  cin >> q;

  while (q--) {
    solve();
  }
}
