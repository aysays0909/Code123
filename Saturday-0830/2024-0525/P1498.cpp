#include <bits/stdc++.h>

using namespace std;

const int N = 13;
char w[1<<N][1<<N];

void dfs(int u, int x1, int y1, int x2, int y2) {
  if (u == 1) {
    w[x1][y1+1] = w[x1+1][y1] = '/';
    w[x1][y1+2] = w[x1+1][y1+3] = '\\';
    w[x1+1][y1+1] = w[x1+1][y1+2] = '_';
    return;
  }
  int dx = x2 - x1 + 1, dy = y2 - y1 + 1;
  dfs(u-1, x1, y1+dy/4, x2-dx/2, y2-dy/4);
  dfs(u-1, x1+dx/2, y1, x2, y2-dy/2);
  dfs(u-1, x1+dx/2, y1+dy/2, x2, y2);
}

int main()
{
  int n; cin >> n;
  for (int i = 1; i <= (1<<n); ++i) {
    for (int j = 1; j <= (1<<(n+1)); ++j) w[i][j] = ' ';
  }

  dfs(n, 1, 1, 1<<n, 1<<(n+1));

  for (int i = 1; i <= (1<<n); ++i) {
    for (int j = 1; j <= (1<<(n+1)); ++j) cout << w[i][j];
    cout << endl;
  }
  return 0;
}
