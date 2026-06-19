#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct File {
	int a, c;
};
bool compare(const File& x, const File& y) {
	return (long long)y.c * x.a < (long long)x.c * y.a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<File> files(n);
	for (int i = 0; i < n; ++i) {
		cin >> files[i].a >> files[i].c;
	}
	sort(files.begin(), files.end(), compare);
	long long total = 0;
	long long prefix = 0;
	for (const auto& file : files) {
		prefix += file.a;
		total += prefix * file.c;
	}
	cout << total;
	return 0;
}
