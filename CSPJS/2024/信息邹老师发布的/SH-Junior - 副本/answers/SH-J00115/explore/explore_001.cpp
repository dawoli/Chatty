#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5,M=1e3+5;
int t,n,m,k;
int x,y,d;
int ans;
char a[N][M];
bool flag[N][M];
bool f(){
	if(d==0){
		if(y+1>m||a[x][y+1]=='x')return false;
		y++;
	}else if(d==1){
		if(x+1>n||a[x+1][y]=='x')return false;
		x++;
	}else if(d==2){
		if(y-1<1||a[x][y-1]=='x')return false;
		y--;
	}else{
		if(x-1<1||a[x-1][y]=='x')return false;
		x--;
	}return true;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k; 
		cin>>x>>y>>d;
		memset(flag,false,sizeof(flag));
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			} 
		}while(k--){
			if(flag[x][y]==0){
				flag[x][y]=1;
				ans++;
			}if(f()==0)d=(d+1)%4;
		}if(flag[x][y]==0){
			flag[x][y]=1;
			ans++;
		}cout<<ans<<"\n";
	} 
	return 0;
}
