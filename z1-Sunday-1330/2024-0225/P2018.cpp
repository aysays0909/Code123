#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 5;
vector<int> vec[maxn];
int f[maxn], ans[maxn];

void dfs(int u, int fa) {
  f[u] = 1;
  vector<int> vv;
  for (int i : vec[u]) {
    if (i == fa) continue;
    dfs(i, u);
    vv.push_back(f[i]);
  }
  sort(vv.begin(), vv.end());
  reverse(vv.begin(), vv.end());
  int id = 0;
  for (int i : vv) {
    ++id;
    f[u] = max(f[u], i + id);
  }
}

int main()
{
  int n; cin >> n;
  for (int i = 2; i <= n; ++i) {
    int x; cin >> x;
    vec[i].push_back(x), vec[x].push_back(i);
  }

  int res = n+5;
  for (int i = 1; i <= n; ++i) {
    memset(f, 0x3f, sizeof(f));
    dfs(i, -1);
    ans[i] = f[i];
    res = min(res, ans[i]);
  }

  cout << res << endl;
  vector<int> vv;
  for (int i = 1; i <= n; ++i) {
    if (ans[i] == res) cout << i << " ";
  }
  cout << endl;
  return 0;
}
