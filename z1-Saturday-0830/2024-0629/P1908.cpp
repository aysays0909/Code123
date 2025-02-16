#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 5e5 + 5;
int w[maxn];
LL res = 0;

void mergeSort(int l, int r) {
	if (l >= r) return ;
	int mid = (l + r) / 2;
	mergeSort(l, mid); mergeSort(mid+1, r);
	// w[l]~w[mid], w[mid+1]~w[r]
	
	vector<int> vec;
	int i = l, j = mid+1;
	while (i<=mid && j<=r) {
		if (w[i] <= w[j]) vec.push_back(w[i]), ++i;
		else vec.push_back(w[j]), res += mid-i+1, ++j;
	}
	
	while (i<=mid) vec.push_back(w[i]), ++i;
	while (j<=r) vec.push_back(w[j]), ++j;
	
	for (int i = 0, j = l; i < (int)vec.size(); ++i, ++j) w[j] = vec[i];
}

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	mergeSort(1, n);
	cout << res << endl;
    return 0;
}
