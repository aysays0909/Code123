#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 6;
int w[maxn];

void solve_min(int n, int m) {
	deque<int> q;
	for (int i = 1; i <= n; ++i) {
		while (!q.empty() && i-q.front()>=m) q.pop_front();
		while (!q.empty() && w[i]<=w[q.back()]) q.pop_back();
		q.push_back(i);
		if (i >= m) cout << w[q.front()] << " ";
	}
	cout << endl;
}

void solve_max(int n, int m) {
	deque<int> q;
	for (int i = 1; i <= n; ++i) {
		while (!q.empty() && i-q.front()>=m) q.pop_front();
		while (!q.empty() && w[i]>=w[q.back()]) q.pop_back();
		q.push_back(i);
		if (i >= m) cout << w[q.front()] << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> w[i];
	solve_min(n, m); solve_max(n, m);
	return 0;
}
