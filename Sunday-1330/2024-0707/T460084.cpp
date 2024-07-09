#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n; cin >> n;
  string str; cin >> str;
  int cnt = 0;
  for (char i : str) {
    if (i == '1') ++cnt;
  }

  if (cnt&1) { cout << -1 << endl; return; }
  if (cnt==0 || cnt>=4) { cout << cnt/2 << endl; return; }

  if (str=="011" || str=="110") { cout << -1 << endl; return; }
  if (str=="0110") { cout << 3 << endl; return; }
  for (int i = 0; i < (int)str.size()-1; ++i) {
    if (str[i]=='1' && str[i+1]=='1') { cout << 2 << endl; return; }
  }
  cout << 1 << endl;
}

int main()
{
  int T; cin >> T;
  while (T -- ) solve();
  return 0;
}
