#include <bits/stdc++.h>
using namespace std;	
const int N = 1e5 + 5;
#define int long long
int n,m,x,y,a[N];

bool cmp(int x,int y){
	if(x > y) return 1;
	return 0;
}

void solve(){
	cin>>n>>m>>y;
	int len = n * m - 1;
	for(int i = 1;i <= len;i++){
		cin>>a[i];
	}
	sort(a + 1,a + len + 1,cmp);
	
	for(int i = 1;i <= len;i++){
		if(a[i] > y && a[i + 1] < y) x = i + 1;
	}
	
	int c = (x - 1) / n + 1;
	int r = x - (c - 1) * n;
	if(c % 2 == 0) r = m + 1 - r;
	 
	cout<<c<<" "<<r;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	
	return 0;
} 

