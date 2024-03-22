#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000 + 5;
vector<int> vec[maxn];
int s[maxn], w[maxn], a[maxn];
bool vis[maxn];

void dfs(int u) {
	s[u] = 1;
	for (int i : vec[u]) {
		dfs(i);
		s[u] += s[i];
	}
}

void dfs2(int u, int n) {
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			if (cnt == w[u]) {
				a[u] = i;
				vis[i] = true;
				break;
			}
			++cnt;
		}
	}
	for (int i : vec[u]) {
		dfs2(i, n);
	}
}

int main()
{
	int n, root; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x >> w[i];
		if (x != 0) vec[x].push_back(i);
		else root = i;
	}
	dfs(root);
	for (int i = 1; i <= n; ++i) {
		if (w[i] > s[i]-1) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	dfs2(root, n);
	for (int i = 1; i <= n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
    return 0;
}
