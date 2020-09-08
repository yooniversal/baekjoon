//15664

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

bool chk[9];
int n, m, cur;
vi tmp, ret;

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << ret[i] << " ";
		cout << '\n';
		return;
	}

	int prev = 0; //같은 자리에 오는 숫자 중복 제거
	for (int i = 0; i < n; i++) {
		if (chk[i] || prev == tmp[i] || cur > tmp[i]) continue;
		cur = tmp[i];
		prev = tmp[i];
		chk[i] = true;
		ret.push_back(tmp[i]);
		dfs(cnt+1);
		ret.pop_back();
		cur = 0;
		chk[i] = false;
	}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	tmp.resize(n);
	for (int i = 0; i < n; i++) cin >> tmp[i];
	sort(tmp.begin(), tmp.end());

	dfs(0);

	return 0;
}