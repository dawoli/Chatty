#include<bits/stdc++.h>
using namespace std;
int n,m,a[205],seat[15][15],rs,rse,c,r;
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	rs=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) if(a[i]==rs) rse=i;
	r=floor((rse-1)/n)+1;
	if(r%2==1) c=rse%n;
	else c=n-(rse%n)+1;
	if(c==0) c=n;
	cout<<r<<" "<<c;
	return 0;
}
