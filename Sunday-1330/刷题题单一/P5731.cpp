#include <bits/stdc++.h>

using namespace std;

const int maxn = 10 + 5;
int w[maxn][maxn];

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int main()
{
  int n; cin >> n;
  for (int i = 1, x = 1, y = 1, id = 0; i <= n*n; ++i) {
    w[x][y] = i;
    int nx = x+dx[id], ny = y+dy[id];
    if (nx<1 || nx>n || ny<1 || ny>n || w[nx][ny]) {
      id = (id + 1) % 4;
      nx = x+dx[id], ny = y+dy[id];
    }
    x = nx, y = ny;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) printf("%3d", w[i][j]);
    cout << endl;
  }
  return 0;
}
