#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int maxi = 0;
vector<int> v[10001];
int pos[10001];
bool visited[10001] = { false, };
vector<int> arr;

void dfs(int n) {
	pos[n]++;
	if (pos[n] > maxi)maxi = pos[n];
	visited[n] = true;

	for (int i = 0; i < v[n].size(); i++) {
		if (visited[v[n][i]] == false) {
			dfs(v[n][i]);
		}
	}

}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a - 1].push_back(b - 1);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[j] = false;
		}
		dfs(i);
	}
	for (int i = 0; i < n; i++) {
		if (pos[i] == maxi)cout << i + 1 << " ";
	}

	return 0;
}