#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 1e5 + 5;
int w[maxn];
LL pSum[maxn], f[maxn][2];

LL calc(int pos) { return f[pos][0] - pSum[pos]; }

int main()
{
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> w[i]; pSum[i] = pSum[i-1] + w[i];
  }

  deque<int> q; q.push_back(0);
  for (int i = 1; i <= n; ++i) {
    while (!q.empty() && q.front()<i-k) q.pop_front();
    f[i][0] = max(f[i-1][0], f[i-1][1]);
    f[i][1] = calc(q.front()) + pSum[i];
    while (!q.empty() && calc(i)>=calc(q.back())) q.pop_back();
    q.push_back(i);
  }
  cout << max(f[n][0], f[n][1]) << endl;
  return 0;
}
