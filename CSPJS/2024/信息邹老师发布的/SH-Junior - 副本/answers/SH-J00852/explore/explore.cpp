#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int x,y,d;
int X,Y;
char s[1010][1010];
bool jl[1010][1010];
void change(){
	X=x;Y=y;
	if(d==0) Y=y+1;
	else if(d==1) X=x+1;
	else if(d==2) Y=y-1;
	else if(d==3) X=x-1;
}
void go(){
	for(int i=1;i<=k;){
		jl[x][y]=1;
		while(1){
			change();
			i++;
			if(i>=k) break;
			if(s[X][Y]!='x'){
				break;
			}
			d=(d+1)%4;
		}
		x=X;y=Y;
		if(s[x][y]!='x') jl[x][y]=1;
	}
}
int ans;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		memset(jl,0,sizeof(jl));
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>s[i][j];
			}
		}
		for(int i=0;i<=n;i++) s[i][0]='x',s[i][m+1]='x';
		for(int i=0;i<=m;i++) s[0][i]='x',s[n+1][i]='x';
		go();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(jl[i][j]){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
