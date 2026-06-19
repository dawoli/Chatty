#include<bits/stdc++.h>
using namespace std;
int n,m,cnt = 0,a,r,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for (int i = 2;i <= n*m;i++){
		int x;
		cin>>x;
		if (x > a) cnt++;
	}
	c = cnt / n + 1;
	if (c%2) r = cnt % n + 1;
	else r = n - (cnt % n);
	cout<<c<<' '<<r<<endl; 
	return 0;
}
