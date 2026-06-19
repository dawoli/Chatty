#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m;
struct node{ int val,id; }a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].val,a[i].id=i;
	sort(a+1,a+1+n*m,[](node x,node y){ return x.val>y.val; });
	int pos=0;
	for(int i=1;i<=n*m;i++)
		if(a[i].id==1){ pos=i; break; }
	int r=(pos-1)/n+1;
	int c=(pos%n==0?n:pos%n);
	c=(r&1?c:m-c+1);
	cout<<r<<" "<<c;
	return 0;
} 
