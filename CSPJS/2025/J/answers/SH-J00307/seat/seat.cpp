#include<bits/stdc++.h>
using namespace std;
struct o{
	int fs,bh;
}a[111];
int k=0,k1=0;
bool cmp(o x,o y){
	return x.fs>y.fs;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,f=0,c=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[++k].fs;
	a[1].bh=1;
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++){
		if(a[i].bh==1){
			cout<<(i-1)/n+1<<' ';
			if(((i-1)/n+1)%2==0)cout<<n-((i-1)%n+1)+1;
			else cout<<(i-1)%n+1;
		}
	}
}
