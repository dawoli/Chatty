#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],ans[11][11],now = 1,goal;
bool cmp(int a,int b){return a > b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++) cin >> a[i];
	goal = a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i = 1;i <= m;i++){
		if (i % 2 == 1) for (int j = 1;j <= n;j++) ans[j][i] = a[now++];
		else for (int j = n;j >= 1;j--) ans[j][i] = a[now++];
	}
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= m;j++){
			if (ans[i][j] == goal){
				cout << j << ' ' << i;
				return 0;
			}
		}
	}
}
