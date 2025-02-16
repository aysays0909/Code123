#include <bits/stdc++.h>

using namespace std;

const int maxn = 100 + 5;
bool f[maxn][3][3][2], st[maxn];
int w[maxn];

void solve() {
  memset(f, false, sizeof(f));
  for (int i = 1; i <= 100; ++i) cin >> w[i];

  f[1][0][0][0] = f[2][0][0][0] = true;
  for (int i = 3; i <= 102; ++i) {
    for (int j = 0; j < 3; ++j) {  // i
      for (int k = 0; k < 3; ++k) {  // i-1
        for (int l = 0; l < 3; ++l) {  // i-2
          if (j>w[i] || j+k>w[i-1] || j+k+l>w[i-2]) continue;
          for (int t = 0; t < 2; ++t) f[i][j][k][t] |= (f[i-1][k][l][t]&&st[w[i-2]-(j+k+l)]);
          if (j+k+l+2<=w[i-2] && st[w[i-2]-j-k-l-2]) f[i][j][k][1] |= f[i-1][k][l][0];
        }
      }
    }
  }

  cout << (f[102][0][0][1] ? "Yes" : "No") << endl;
}

int main()
{
  for (int i = 0; i < maxn; ++i) st[i] = true;
  st[1] = st[2] = st[5] = false;

  int T; cin >> T;
  while (T -- ) solve();
  return 0;
}
