#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[109],rk;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])rk++;
	}
	int q=rk/n,r=rk%n;
	cout<<q+1<<" ";
	if(q%2)cout<<n-r;
	else cout<<r+1;
	return 0;
}
