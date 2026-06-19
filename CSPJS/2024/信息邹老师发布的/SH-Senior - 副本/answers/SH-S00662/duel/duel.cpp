//AC
//O(n+nlog(n))
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;

const int N = 1e5 + 10;
int r[N], n, tong[N];

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++ ){
		cin >> r[i];
		tong[r[i]] ++ ;
	}
	std::sort(tong, tong + N, std::greater<int>());
	cout << tong[0] << std::endl;
	return 0;
}
