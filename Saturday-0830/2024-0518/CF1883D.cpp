#include <bits/stdc++.h>

using namespace std;

int main() {
  int T; cin >> T;
  multiset<int> sL, sR;
  while (T -- ) {
    char op[2];
    int l, r;
    cin >> op >> l >> r;
    if (op[0] == '+') {
      sL.insert(l); sR.insert(r);
    } else {
      sL.erase(sL.find(l)); sR.erase(sR.find(r));
    }

    if (!sL.empty() && *sL.rbegin()>*sR.begin()) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
