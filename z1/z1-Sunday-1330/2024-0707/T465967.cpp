#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2e5 + 5;
LL value[maxn], p[maxn];
bool st[maxn];
vector<int> vec[maxn];

LL sum(int l, int r) { return p[r] - p[l-1]; }

int main()
{
  int n, m, cnt = 0; cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int x; cin >> x;
    st[x] = !st[x];

    if (st[x]) ++cnt;
    else --cnt;

    p[i] = cnt;
    vec[x].push_back(i);
  }

  for (int i = 1; i <= m; ++i) p[i] += p[i-1];

  for (int i = 1; i <= n; ++i) {
    int len = vec[i].size();
    if (len & 1) { vec[i].push_back(m+1); ++len; }

    LL res = 0;
    for (int j = 0; j < len; j += 2) res += sum(vec[i][j], vec[i][j+1]-1);
    cout << res << " ";
  }
  cout << endl;
  return 0;
}
