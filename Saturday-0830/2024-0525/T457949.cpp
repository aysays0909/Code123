#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e7 + 5;
int w[maxn];

int main()
{
    int n, k; scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; ++i) scanf("%d",&w[i]);
    nth_element(w+1, w+n-k+1, w+n+1);
    printf("%d\n", w[n-k+1]);
    return 0;
}
