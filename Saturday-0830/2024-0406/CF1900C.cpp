#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;
const int inf = 0x3f3f3f3f;
int tr[maxn][2], f[maxn];
char s[maxn];

void dfs(int u) {
  int l = tr[u][0], r = tr[u][1];
  if (!l && !r) return;

  f[u] = inf;
  if (l) {
    dfs(l);
    f[u] = f[l] + (s[u] != 'L');
  }
  if (r) {
    dfs(r);
    f[u] = min(f[u], f[r] + (s[u] != 'R'));
  }
}

void solve() {
  int n; cin >> n;
  for (int i = 0; i <= n+2; ++i) f[i] = 0;

  cin >> (s+1);
  for (int i = 1; i <= n; ++i) cin >> tr[i][0] >> tr[i][1];
  dfs(1);

  cout << f[1] << endl;
}

int main()
{
  int T; cin >> T;
  while (T -- ) solve();
  return 0;
}
