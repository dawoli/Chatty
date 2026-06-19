#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,m,k;
char mapp[1001][1001];
bool visit[1001][1001];
ll mx[4]={0,1,0,-1};
ll my[4]={1,0,-1,0};
ll x,y,d;
ll ans=1;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;//多测不清空,暴零两行泪 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				visit[i][j]=0; 
			} 
		} 
		n=0,m=0,k=0;
		scanf("%d%d%d",&n,&m,&k); 
		scanf("%d%d%d",&x,&y,&d); 
		for(int i=1;i<=n;i++){
			string s;
			cin>>s;
			for(int j=1;j<=m;j++){
				mapp[i][j]=s[j-1];
			} 
		} 
		visit[x][y]=1;
		ans++;
//		cout<<n<<m<<k;
		for(int i=1;i<=k;i++){		
			
			ll tx=x+mx[d];
			ll ty=y+my[d];
			if(tx<=0 or tx>n or ty<=0 or ty>m or mapp[tx][ty]=='x'){
				d=(d+1)%4;
//				cout<<"t\n"; 
			}
			else{
				x=tx;
				y=ty;
//				cout<<x<<" "<<y<<endl;
				if(visit[x][y]==0){
					ans++; 
				} 
				visit[x][y]=1;
			}
		}
//		if(visit[x][y]==0){
//				ans++; 
//		} 
//		visit[x][y]=1;
		cout<<ans<<endl;
	}
	
	return 0;
}
