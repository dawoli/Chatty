#include<bits/stdc++.h>
using namespace std;
struct node{
	int num;
	bool tru;
}f[10009];
int cmp(node a,node b){
	return a.num>b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>f[i].num;
	f[1].tru=1;
	int cnt=0;
	sort(f+1,f+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(f[i].tru==1){
			cnt=i;
			break;
		}
	}
	int l=(cnt-1)/n+1;
	cout<<l<<" ";
	cnt-=(l-1)*n;
	if(l%2==0) cout<<n-cnt+1;
	else cout<<cnt;
	return 0;
}
