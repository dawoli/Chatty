#include<bits/stdc++.h>
using namespace std;
int n,a[110110][3];
int dp[210][210][210];
bool A(){
	for(int i = 1;i<=n;i++)
		if(a[i][2]!=0 or a[i][3]!=0)return 0;
	return 1;
}
bool B(){
	for(int i = 1;i<=n;i++)
		if(a[i][3]!=0)return 0;
	return 1;	
}
struct no{
	int a,b;
}x[101010];
bool cp(no p,no q){
	int pd=p.a-p.b;
	int qd=q.a-q.b;
	return pd>qd;
}
void fun1(){
	memset(dp,0,sizeof(dp));
	for(int i = 1;i<=n;i++)
		for(int x = 0;x<=i;x++)
			for(int y = 0;x+y<=i;y++){
				int z=i-x-y;
				if(x)dp[x][y][z]=max(dp[x][y][z],dp[x-1][y][z]+a[i][1]);
				if(y)dp[x][y][z]=max(dp[x][y][z],dp[x][y-1][z]+a[i][2]);
				if(z)dp[x][y][z]=max(dp[x][y][z],dp[x][y][z-1]+a[i][3]);
				
			}
	int ans=-1;
	for(int x = 0;x<=n/2;x++){
		for(int y = 0;y<=n/2;y++){
			int z=n-x-y;
			if(z>n/2)continue;
			ans=max(ans,dp[x][y][z]);
		}
	}
	cout<<ans<<endl;
}
void fun(){
	cin>>n;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=3;j++)
			cin>>a[i][j];
	if(n<=200)fun1();
	else if(A()){
		sort(a[1]+1,a[1]+n+1,greater<int>());
		int ans=0;
		for(int i = 1;i+i<=n;i++)ans+=a[i][1];
		cout<<ans<<endl;
	}
	else if(B()){
		for(int i = 1;i<=n;i++)
			x[i]={a[i][1],a[i][2]};
		sort(x+1,x+n+1,cp);
		int ans=0;
		for(int i = 1;i+i<=n;i++)
			ans+=x[i].a;
		for(int i = n/2+1;i<=n;i++)
			ans+=x[i].b;
		cout<<ans<<endl;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int tt;cin>>tt;
	while(tt--)fun();
}
