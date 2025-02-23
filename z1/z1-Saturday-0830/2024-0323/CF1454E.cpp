#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 2e5 + 5;
vector<int> vec[maxn];
int deg[maxn];
bool vis[maxn];

void topSort(int n) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for (int i : vec[u]) {
            if (--deg[i] == 1) q.push(i);
        }
    }
}

int dfs(int u, int fa) {
    int res = 1;
    for (int i : vec[u]) {
        if (!vis[i] && i != fa) res += dfs(i, u);
    }
    return res;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n + 2; ++i) {
        vec[i].clear();
        deg[i] = 0;
        vis[i] = true;
    }

    for (int i = 1; i <= n; ++i) {
        int u, v; cin >> u >> v;
        vec[u].push_back(v); vec[v].push_back(u);
        ++deg[u]; ++deg[v];
    }
    topSort(n);

    LL res = (LL)n * (n - 1);
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) {
            int t = dfs(i, -1);
            res -= (LL)t * (t - 1) / 2;
        }
    }
    cout << res << endl;
}

int main()
{
    int T; cin >> T;
    while (T -- ) {
        solve();
    }
    return 0;
}