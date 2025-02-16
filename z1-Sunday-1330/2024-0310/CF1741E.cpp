#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
int w[maxn];
bool f[maxn];

void solve() {
  int n; cin >> n;
  for (int i = 0; i <= n+2; ++i) w[i] = 0, f[i] = false;

  f[0] = true;
  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
    if (i-w[i]-1 >= 0) f[i] |= f[i-w[i]-1];
    if (i+w[i] <= n) f[i+w[i]] |= f[i-1];
  }
  if (f[n]) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main()
{
  int T; cin >> T;
  while (T -- ) { solve(); }
  return 0;
}
