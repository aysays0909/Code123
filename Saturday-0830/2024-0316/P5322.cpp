#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 5, M = 20000 + 5;
vector<int> vec[N];
int f[M];

int main()
{
  int s, n, m; cin >> s >> n >> m;
  for (int i = 1; i <= s; ++i) {
    for (int j = 1; j <= n; ++j) {
      int x; cin >> x; vec[j].push_back(x);
    }
  }
  for (int i = 1; i <= n; ++i) {
    vec[i].push_back(0);
    sort(vec[i].begin(), vec[i].end());
    for (int k = m; k >= 0; --k) {
      for (int j = 1; j <= s; ++j) {
        int t = 2*vec[i][j] + 1;
        if (k < t) continue;
        f[k] = max(f[k], f[k-t] + j*i);
      }
    }
  }
  cout << f[m] << endl;
  return 0;
}
