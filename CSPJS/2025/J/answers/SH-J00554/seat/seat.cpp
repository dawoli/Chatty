#include <bits/stdc++.h>
using namespace std;
int n,m,kk,p,q;
struct F{
	int w,k;
} a[110];
bool cmp(const F&a, const F&b){
	return a.w>b.w;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i].w;
	}
	a[1].k=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;++i){
		if(a[i].k==1){
			kk=i;
			break;
		}
	}
	p=(kk+n-1)/n;
	if(p%2==1){
		if(kk%n==0) q=n;
		else q=kk%n;
	}
	else{
		if(kk%n==0) q=1;
		q=n-kk%n+1;
	}
	cout<<p<<" "<<q<<endl;
	return 0;
}
