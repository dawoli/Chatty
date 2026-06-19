#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	vector<int> a(n*m);
	for(int i=0;i<n*m;i++) cin>>a[i];
	int x=a[0];
	sort(a.begin(),a.end(),greater<int>());
	for(int i=0;i<n*m;i++)
		if(a[i]==x)
			x=i+1;
	int rx=ceil(1.0*x/m),ry=rx*m-x+1;
	if(rx%2==0) cout<<rx<<' '<<ry<<"\n";
	else cout<<rx<<' '<<n-ry+1<<"\n";
	return 0;
}
