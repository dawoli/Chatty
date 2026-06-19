#include<bits/stdc++.h>
using namespace std;
const int Max_n=1e3+5;
int t,n,m,k,a,b,d0,cnt;
char s[Max_n][Max_n];
bool visit[Max_n][Max_n];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k>>a>>b>>d0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) cin>>s[i][j];
		}
		memset(visit,false,sizeof(visit));
		visit[a][b]=true;
		cnt=1;
		while(k--){
			int tx=a,ty=b;
			if(d0==0){
				b++;
				if(a<1 || a>n || b<1 || b>m || s[a][b]=='x'){
					a=tx;
					b=ty;
					d0=(d0+1)%4;
				}
				else if(visit[a][b]==false){
					visit[a][b]=true;
					cnt++;
				}
			}
			
			else if(d0==1){
				a++;
				if(a<1 || a>n || b<1 || b>m || s[a][b]=='x'){
					a=tx;
					b=ty;
					d0=(d0+1)%4;
				}
				else if(visit[a][b]==false){
					visit[a][b]=true;
					cnt++;
				}
			}
			
			else if(d0==2){
				b--;
				if(a<1 || a>n || b<1 || b>m || s[a][b]=='x'){
					a=tx;
					b=ty;
					d0=(d0+1)%4;
				}
				else if(visit[a][b]==false){
					visit[a][b]=true;
					cnt++;
				}
			}
			
			else if(d0==3){
				a--;
				if(a<1 || a>n || b<1 || b>m || s[a][b]=='x'){
					a=tx;
					b=ty;
					d0=(d0+1)%4;
				}
				else if(visit[a][b]==false){
					visit[a][b]=true;
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
