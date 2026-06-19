#include <bits/stdc++.h>
using namespace std;
struct Node{int score,id;}a[10005];
bool cmp(Node x,Node y){return x.score > y.score;}
int n,m,s,ans1,ans2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++) cin >> a[i].score,a[i].id = i;
	sort(a + 1,a + n * m + 1,cmp);
	for (int i = 1;i <= n * m;i++) if (a[i].id == 1){
		s = i;
		break;
	}
	ans1 = int(ceil(s / (n * 1.0)));
	if (ans1 % 2 == 1) ans2 = s - (ans1 - 1) * n;
	else ans2 = n - (s - (ans1 - 1) * n) + 1;
	cout << ans1 << " " << ans2;
	return 0;
}
