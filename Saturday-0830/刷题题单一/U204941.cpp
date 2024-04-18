#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 11;
LL f[N+5][1<<N];
vector<int> vec[1<<N];

bool check(int x, int n) {
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if ((x>>i) & 1) {
      if (cnt&1) return false;
      cnt = 0;
    } else ++cnt;
  }
  if (cnt&1) return false;
  return true;
}

void init(int n) {
  for (int i = 0; i < (1<<n); ++i) {
    vec[i].clear();
    for (int j = 0; j < (1<<n); ++j) {
      if (i & j) continue;
      if (!check(i|j, n)) continue;
      vec[i].push_back(j);
    }
  }
}

int main()
{
  int n, m;
  while (cin >> n >> m) {
    if (!n && !m) break;
    init(n);
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
      for (int j = 0; j < (1<<n); ++j) {
        for (int k : vec[j]) f[i][j] += f[i-1][k];
      }
    }
    cout << f[m][0] << endl;
  }
  return 0;
}
