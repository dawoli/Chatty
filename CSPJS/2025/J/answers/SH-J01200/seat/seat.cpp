#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e2 + 2;
int n,m,p,a[N];
//1 <= p <= 100
int x = 1,y = 1;
int score,rnk;
bool cmp(int x,int y){
	return x > y;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);//Don't forget freopen(stdin)!
	freopen("seat.out","w",stdout);//Don't forgrt freopen(stdout)!
	cin >> n >> m;
	p = n * m;
	for(int i = 1;i <= p;i++) cin >> a[i];
	score = a[1];
	sort(a + 1,a + p + 1,cmp);
	for(int i = 1;i <= p;i++){
		if(a[i] == score){
			rnk = i;
			break;
		}
	}
	x = (rnk - 1) / n + 1;
	y = rnk % n;
	if(!y) y = n;
	if(!(x & 1)) y = n + 1 - y;
	cout << x << " " << y;
	return 0;
}

