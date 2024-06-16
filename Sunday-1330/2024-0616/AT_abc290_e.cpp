#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2e5 + 5;
int w[maxn];
vector<int> vec[maxn];

LL calc(int n, vector<int> vv) {
  LL res = 0;
  int len = vv.size();
  for (int i = 0, j = len-1; i < j; ) {
    int x = vv[i], y = vv[j];
    int lDis = x, rDis = n-y+1;
    if (lDis <= rDis) res += (LL)lDis * (j-i), ++i;
    else res += (LL)rDis * (j-i), --j;
  }
  return res;
}

int main()
{
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
    vec[w[i]].push_back(i);
  }

  LL res = 0;
  for (int i = 2; i <= n; ++i) res += ((LL)n-i+1) * (i/2);

  for (int i = 1; i <= n; ++i) res -= calc(n, vec[i]);

  cout << res << endl;
  return 0;
}
