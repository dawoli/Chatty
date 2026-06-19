#include<bits/stdc++.h>
using namespace std;
struct s{
	long long x,y,c;
};
s s1,s2;
long long n,m,ans=0,t;
char c[1010][1010];
bool vis[1010][1010];
queue<s> q;
int main(){
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c[i][j];
			}
		}
		if(n==1){
			for(int i=1;i<=m;i++){
				if(c[1][i]=='$'){
					ans++;
				}
			}
			cout<<ans<<" "<<m-1;
		}
		else{
			cout<<0<<" ";
			s1.x=1;
			s1.y=1;
			s1.c=0;
			vis[1][1]=1;
			q.push(s1);
			while(!q.empty()){
				s1=q.front();
				if(s1.x==n&&s1.y==m){
					cout<<s1.c;
					return 0;
				}
				vis[s1.x][s1.y]=1;
				q.pop();
				if(s1.x-1>0&&vis[s1.x-1][s1.y]==0&&c[s1.x-1][s1.y]!='*'){
					s2.x=s1.x-1;
					s2.y=s1.y;
					s2.c=s1.c+1;
					q.push(s2);
				}
				if(s1.y-1>0&&vis[s1.x][s1.y-1]==0&&c[s1.x][s1.y-1]!='*'){
					s2.x=s1.x;
					s2.y=s1.y-1;
					s2.c=s1.c+1;
					q.push(s2);
				}
				if(s1.x+1<=n&&vis[s1.x+1][s1.y]==0&&c[s1.x+1][s1.y]!='*'){
					s2.x=s1.x+1;
					s2.y=s1.y;
					s2.c=s1.c+1;
					q.push(s2);
				}
				if(s1.y+1<=m&&vis[s1.x][s1.y+1]==0&&c[s1.x][s1.y+1]!='*'){
					s2.x=s1.x;
					s2.y=s1.y+1;
					s2.c=s1.c+1;
					q.push(s2);
				}
			}
		}
	}
}
