#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 5e5 + 5;
int a[maxn], b[maxn];

bool check(int n, int mid) {
  LL sum = b[mid];
  for (int i = 1; i <= n; ++i) {
    if (i == mid) continue;
    if (b[i] < sum) sum += b[i];
    else return false;
  }
  return true;
}

int main()
{
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  memcpy(b, a, sizeof(b));
  sort(b+1, b+n+1);
  int l = 1, r = n;
  while (l <= r) {
    int mid = (l+r) / 2;
    if (check(n, mid)) r = mid-1;
    else l = mid+1;
  }

  for (int i = 1; i <= n; ++i) {
    if (l<=n && a[i]>=b[l]) cout << "T";
    else cout << "N";
  }
  cout << endl;
  return 0;
}
