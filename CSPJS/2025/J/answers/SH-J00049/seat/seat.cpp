#include<bits/stdc++.h>
using namespace std;
int p[110][110],A,n,m;
int a[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
		if(i==1) A=a[i];
	}
	sort(a+1,a+n*m+1,greater<int>());
	int I=1,cnt=0;
	for(int j=1;j<=m;++j){
		if(I==1){
			for(;I<n;++I){
				cnt++;
				p[I][j]=a[cnt];
			}
			cnt++;
			p[I][j]=a[cnt];
		}else{
			for(;I>1;--I){
				cnt++;
				p[I][j]=a[cnt];
			}
			cnt++;
			p[I][j]=a[cnt];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(p[i][j]==A){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
