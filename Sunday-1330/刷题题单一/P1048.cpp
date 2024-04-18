#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 5;
int f[maxn];

int main()
{
  int n, m; cin >> n >> m;
  while (m -- ) {
    int v, c; cin >> v >> c;
    for (int i = n; i >= v; --i) f[i] = max(f[i], f[i-v]+c);
  }
  cout << f[n] << endl;
  return 0;
}
