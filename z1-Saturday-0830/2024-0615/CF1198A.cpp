#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 4e5 + 5;
int w[maxn];

void solve() {
  int n, I; cin >> n >> I;
  for (int i = 1; i <= n; ++i) cin >> w[i];
  I = (I*8) / n;
  if (I >= 20) { cout << 0 << endl; return; }

  sort(w+1, w+n+1);

  int limit = (1<<I), res = 0;
  map<int, int> mp;
  for (int l=1, r=0; l <= n; ++l) {
    r = max(r, l-1);
    while (r+1<=n && ((int)mp.size()<limit || mp.count(w[r+1]))) {
      mp[w[r+1]]++;
      ++r;
    }
    res = max(res, r-l+1);
    mp[w[l]]--;
    if (mp[w[l]] == 0) mp.erase(w[l]);
  }

  cout << n-res << endl;
}

int main()
{
  int T = 1;
  while (T -- ) solve();
  return 0;
}
