//13548

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
#define INF 1000000001
#define MAX 100001
#define MAXV 100001
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> ii;

int sqrtN;
int A[MAX];
int cnt[MAXV];
int cnt2[MAXV];
int ret[MAX];

struct QueryNode {
	int s, e, n;
	QueryNode() : QueryNode(0, 0, -1) {}
	QueryNode(int s1, int e1, int n1) : s(s1), e(e1), n(n1) {}
	bool operator<(const QueryNode& O) const {
		if (s / sqrtN != O.s / sqrtN) return (s / sqrtN < O.s / sqrtN);
		return (e < O.e);
	}
};

QueryNode Q[MAX];

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	sqrtN = sqrt(n);
	for (int i = 0; i < n; i++) cin >> A[i];

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int l, r; cin >> l >> r;
		Q[i] = QueryNode(l-1, r-1, i);
	}
	sort(Q, Q + m);

	int cur = 0;
	int s = Q[0].s, e = Q[0].e;
	for (int i = s; i <= e; i++) {
		if (cnt[A[i]]) {
			cnt2[cnt[A[i]]]--;
		}
		cnt[A[i]]++;
		cnt2[cnt[A[i]]]++;
		if (cnt2[cur + 1] > 0) cur++;
	}
	ret[Q[0].n] = cur;

	for (int i = 1; i < m; i++) {
		while (Q[i].s < s) {
			cnt2[cnt[A[--s]]]--;
			cnt[A[s]]++;
			cnt2[cnt[A[s]]]++;
			if (cnt2[cur + 1] > 0) cur++;
		}
		while (e < Q[i].e) {
			cnt2[cnt[A[++e]]]--;
			cnt[A[e]]++;
			cnt2[cnt[A[e]]]++;
			if (cnt2[cur + 1] > 0) cur++;
		}
		while (Q[i].s > s) {
			cnt2[cnt[A[s]]]--;
			cnt2[cnt[A[s]]-1]++;
			cnt[A[s++]]--;
			if (cnt2[cur] <= 0) cur--;
		}
		while (e > Q[i].e) {
			cnt2[cnt[A[e]]]--;
			cnt2[cnt[A[e]]-1]++;
			cnt[A[e--]]--;
			if (cnt2[cur] <= 0) cur--;
		}
		ret[Q[i].n] = cur;
	}

	for (int i = 0; i < m; i++)
		cout << ret[i] << '\n';

	return 0;
}