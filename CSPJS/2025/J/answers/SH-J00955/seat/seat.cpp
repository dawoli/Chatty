#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],l,p,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int nn=n*m;
	for(int i=1;i<=nn;i++) cin>>a[i];
	cnt=a[1];
	sort(a+1,a+nn+1);
	for(int i=nn;i>0;i--){
		if(a[i]==cnt) p=nn-i+1;//p为排名 
	}
	if(p%n==0) l=p/n;//l为列数 
	else l=(p-p%n)/n+1;
	if(l==1) cout<<l<<" "<<p;
	else if(l>=2&&l%2==1){
		if(p-l*n==0) cout<<l<<" "<<n;
		else cout<<l<<" "<<p-(l-1)*n;
	} 
	else cout<<l<<" "<<n-p+(l-1)*n+1;
	return 0;
}
