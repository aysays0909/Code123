#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;
vector<int> vec[maxn];
int w[maxn], f[maxn];

void dfs(int u, int sum, int root, vector<int>& vv) {
  f[u] = w[u];
  for (int i : vec[u]) {
    dfs(i, sum, root, vv);
    f[u] += f[i];
  }
  if (f[u] == sum && u != root) {
    vv.push_back(u);
    f[u] = 0;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, sum = 0; cin >> n;
  for (int i = 1; i <= n; ++i) {
    int fa; cin >> fa >> w[i];
    vec[fa].push_back(i);
    sum += w[i];
  }

  if (sum % 3) { cout << -1 << endl; return 0; }
  int root = vec[0][0];
  vector<int> vv;
  dfs(root, sum / 3, root, vv);
  if (vv.size() >= 2) {
    cout << vv[0] << " " << vv[1] << endl;
  } else cout << -1 << endl;
  return 0;
}
