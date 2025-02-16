#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e4 + 5;
int f[maxn];

int main()
{
  int n, V; cin >> n >> V;
  while (n -- ) {
    int w, v, m; cin >> w >> v >> m;
    for (int i = 1; i <= m; i <<= 1) {
      for (int j = V; j >= i*v; --j) f[j] = max(f[j], f[j-i*v] + i*w);
      m -= i;
    }

    for (int j = V; j >= m*v; --j) f[j] = max(f[j], f[j-m*v] + m*w);
  }
  cout << f[V] << endl;
  return 0;
}
