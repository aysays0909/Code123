#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 5;
int w[maxn];

bool dfs(int pos, int m, int mid, int n) {
  // 使用 m 次操作, 把 w[pos] 这个数变成 mid, 数组一共有 n 个数
  if (m < 0) return false;
  if (w[pos] >= mid) return true;
  if (pos == n) return false;

  // w[pos] 要加多少次? -> d
  int d = mid - w[pos];
  if (dfs(pos+1, m-d, mid-1, n)) return true;
  return false;
}

bool check(int n, int m, int mid) {
  for (int i = 1; i <= n; ++i) {
    if (dfs(i, m, mid, n)) return true;
  }
  return false;
}

void solve() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> w[i];

  int l = 1, r = 2e8;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(n, m, mid)) l = mid+1;
    else r = mid-1;
  }

  cout << r << endl;
}

int main()
{
  int T; cin >> T;
  while (T -- ) { solve(); }
  return 0;
}
