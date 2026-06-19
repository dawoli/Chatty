#include<bits/stdc++.h>
using namespace std;

int n, a[10010][4], mem[100][100][200], T;
int f(int apt_a, int apt_b, int left, int fy) { 
	if(apt_a > n/2 || apt_b > n/2 || n - left - apt_a - apt_b > n/2) return -1; 
	if(left <= 0) return fy;
//	if(mem[apt_a][apt_b][left] > fy + a[left][3]) 
//		return mem[apt_a][apt_b][left];
//	int ans = max(0, mem[apt_a][apt_b][left]);
	int ans = 0;
	ans = max(ans, f(apt_a + 1, apt_b, left - 1, fy + a[left][0]));
	ans = max(ans, f(apt_a, apt_b + 1, left - 1, fy + a[left][1]));
	ans = max(ans, f(apt_a, apt_b, left - 1, fy + a[left][2]));

	return ans;
}
void Main() {
	
	cin >> n;
	for(int i = 1; i <= n ; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		a[i][3] = max(a[i][0], max(a[i][1], a[i][2]));
	}
	memset(mem,-1, sizeof(mem));
	cout << f(0, 0, n, 0) << '\n';
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	Main();
	return 0;
} 
//4 4 2 1 3 2 4 5 3 4 3 5 1
