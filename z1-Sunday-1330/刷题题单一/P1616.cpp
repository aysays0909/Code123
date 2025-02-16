#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e7 + 5;
long long f[maxn];

int main()
{
  int n, m; cin >> n >> m;
  while (m -- ) {
    int v, c; cin >> v >> c;
    for (int i = v; i <= n; ++i) f[i] = max(f[i], f[i-v] + c);
  }
  cout << f[n] << endl;
  return 0;
}
