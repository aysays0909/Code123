#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;
vector<int> vec[maxn];
int w[maxn], f[maxn];

void dfs(int u) {
  if (vec[u].empty()) {
    f[u] = 1;
    return ;
  }
  int minn = 1e9, sum = 0;
  for (int i : vec[u]) {
    dfs(i);
    minn = min(minn, f[i]);
    sum += f[i];
  }
  if (w[u]) f[u] = minn;
  else f[u] = sum;
}

int main()
{
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) cin >> w[i];
  for (int i = 2; i <= n; ++i) {
    int x; cin >> x; vec[x].push_back(i);
  }

  int m = 0;
  for (int i = 1; i <= n; ++i) {
    if (vec[i].empty()) ++m;
  }
  dfs(1);
  cout << m - f[1] + 1 << endl;
  return 0;
}