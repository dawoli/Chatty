#include<bits/stdc++.h>
using namespace std;
long long T,n,m,k,x,y,d;
char mp[1005][1005];
bool vst[1005][1005];
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--) {
		long long cnt=0;
		cin>>n>>m>>k>>x>>y>>d;
		for(long long i=1; i<=n; i++)
			for(long long j=1; j<=m; j++)
				vst[i][j]=1;
		for(long long i=1; i<=n; i++)
			for(long long j=1; j<=m; j++)
				cin>>mp[i][j];
		vst[x][y]=0;
		while(k--) {
			long long xx=x,yy=y;
			if(d==0) yy++;
			else if(d==1) xx++;
			else if(d==2) yy--;
			else xx--;
			if(mp[xx][yy]!='.'||xx<1||xx>n||yy<1||yy>m)
				d=(d+1)%4;
			else {
				x=xx,y=yy;
				vst[xx][yy]=0;
			}
		}
		for(long long i=1; i<=n; i++)
			for(long long j=1; j<=m; j++)
				if(!vst[i][j])
					cnt++;
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
