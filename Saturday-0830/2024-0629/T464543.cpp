#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int maxn = 3000 + 5;
PII w[maxn];
int f[maxn];

int fFind(int x) {
    if (f[x] != x) f[x] = fFind(f[x]);
    return f[x];
}

void fMerge(int x, int y) {
    int p = fFind(x), q = fFind(y);
    if (p != q) f[p] = q;
}

bool check(double mid, int n, int row, int line) {
    for (int i = 1; i <= n + 2; ++i) f[i] = i;
    for (int i = 1; i <= n; ++i) {
        if (w[i].x - mid < 1 || w[i].y + mid > line) fMerge(i, n+1);
        if (w[i].x + mid > row || w[i].y - mid < 1) fMerge(i, n+2);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int a = w[i].x - w[j].x, b = w[i].y - w[j].y;
            double d = sqrt(a*a + b*b);
            if (d < 2*mid) fMerge(i, j);
        }
    }
    if (fFind(n + 1) == fFind(n + 2)) return false;
    return true;
}

int main()
{
    int n, row, line; cin >> n >> row >> line;
    for (int i = 1; i <= n; ++i) cin >> w[i].x >> w[i].y;

    double l = 0, r = row + line;
    while (r - l > 1e-4) {
        double mid = (l + r) / 2;
        if (check(mid, n, row, line)) l = mid;
        else r = mid;
    }
    printf("%.2f\n", l);
    return 0;
}
