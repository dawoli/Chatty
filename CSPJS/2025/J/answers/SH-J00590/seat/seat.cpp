#include <bits/stdc++.h>
using namespace std;
int sr,a[110];
int n,m,vn;
bool cmp(int a,int b){
	return a>b;
}
struct P{
	int vi,val;
}t[20][20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	sr=a[1];
	sort(a+1,a+n*m+1,cmp);
	vn=1;
	for(int i=1;i<=m;++i){
		if(i%2==1){
			for(int j=1;j<=n;++j){
				t[j][i].vi=vn;
				t[j][i].val=a[vn];
				vn++;
			}
		}else{
			for(int j=n;j>=1;--j){
				t[j][i].vi=vn;
				t[j][i].val=a[vn];
				vn++;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(sr==t[i][j].val){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
