#include <iostream>

using namespace std;

int w[15][15];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

bool check(int x, int y, int k, int n) {
  int nx = x + dx[k], ny = y + dy[k];
  if (nx < 1 || nx > n || ny < 1 || ny > n || w[nx][ny]) return false;
  return true;
}

int main()
{
  int n; cin >> n;
  for (int i = 1, j = 1, k = 0, t = 1; t <= n * n; ++t) {
    w[i][j] = t;
    if (!check(i, j, k, n)) k = (k + 1) % 4;
    i += dx[k], j += dy[k];
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) printf("%3d", w[i][j]);
    cout << endl;
  }
  return 0;
}
