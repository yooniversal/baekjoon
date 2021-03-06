#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define MAX 300005
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		if (n % k == 0) {
			cout << 1 << '\n';
			continue;
		}
		if (n > k) k = n + k - n % k;
		int ret = k / n;
		if (k % n != 0) ++ret;
		cout << ret << '\n';
	}

	return 0;
}