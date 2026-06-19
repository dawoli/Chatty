#include<bits/stdc++.h>
using namespace std;
int dir1(int d,int x){
	if(d==0) return x;
	else if(d==1) return x+1;
	else if(d==2) return x;
	else return x-1;
}
int dir2(int d,int y){
	if(d==0) return y+1;
	else if(d==1) return y;
	else if(d==2) return y-1;
	else return y;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,x,y,k,d;
	char a[1005][1005];
	cin>>t;
	for(int i=1;i<=t;i++){
		long long cnt=1;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				cin>>a[j][k];
			}
		}
		for(int j=1;j<=k;j++){
			if(a[dir1(d,x)][dir2(d,y)]=='x'||dir1(d,x)>n||dir1(d,x)<=0||dir2(d,y)>m||dir2(d,y)<=0){
				d=(d+1)%4;
			}
			else{
				a[x][y]='0';
				x=dir1(d,x);
				y=dir2(d,y);
			}
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				if(j==x&&k==y) continue;
				if(a[j][k]=='0') cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
