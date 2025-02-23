#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b, c; cin >> a >> b >> c;
  a += (c+1)/2, b += c/2;
  if (a > b) cout << "First" << endl;
  else cout << "Second" << endl;
}

int main()
{
  int T; cin >> T;
  while (T -- ) solve();
  return 0;
}
