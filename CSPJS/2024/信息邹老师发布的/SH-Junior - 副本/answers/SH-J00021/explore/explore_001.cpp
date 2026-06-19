#include<bits/stdc++.h>
using namespace std;
const int N=1009;
long long t,n,m,k,x0,y0,x,y,d,a[N][N],an[N];
char b[N][N];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	set<string> s;
	cin>>t;
	for(int sb=1;sb<=t;sb++){
		cin>>n>>m>>k;
		cin>>x0>>y0>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>b[i][j];
				if(b[i][j]=='.')a[i][j]=1;
			}
		x=x0;y=y0;
		string p,q,l;
		for(int i=1;i<=k;i++){
			if(d==0&&a[x][y+1]==1)y++;
			else if(d==1&&a[x+1][y]==1)x++;
			else if(d==2&&a[x][y-1]==1)y--;
			else if(d==3&&a[x-1][y]==1)x--;
			else d=(d+1)%4;
			p=x+'0';
			q=y+'0';
			l=p+q;
			s.insert(l);
		}
		an[sb]=s.size();
	}
	for(int i=1;i<=t;i++)cout<<an[i]<<endl;
	return 0;
}
