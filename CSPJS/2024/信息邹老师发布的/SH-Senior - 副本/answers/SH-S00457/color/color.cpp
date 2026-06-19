#include <iostream>
#include <cstring>
#define int long long
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std; 
struct node{
	int v,wrong_last;
};
int a[200005];int n;
//node f[2005][2];//0hong 1lan
//j [0] qu 1 [1] qu 0
int f[105][105][105];
int d[200005][11][11];
int dfs(int u,int last0,int last1){
	if(u==n+1)return 0;
	if(f[u][last0][last1]!=0){
		return f[u][last0][last1];
	}
	return f[u][last0][last1]=max(dfs(u+1,a[u],last1)+(a[u]==last0)*a[u],dfs(u+1,last0,a[u])+(a[u]==last1)*a[u]);
	
}
int dfsmall(int u,int last0,int last1){
//	cout <<a[u]<< " " <<  u << " " << last0 <<" " <<  last1<< endl;
	if(d[u][last0][last1]!=0){
		return d[u][last0][last1];
	}
	if(u==n+1)return 0;
	
	d[u][last0][last1]=max(dfsmall(u+1,a[u],last1)+(a[u]==last0)*a[u],dfsmall(u+1,last0,a[u])+(a[u]==last1)*a[u]-10000000);
	return d[u][last0][last1];
//	dfsmall(u+1,a[u],last1);
//	dfsmall(u+1,last0,a[u]);
	return 0;
}
signed main() {//longlong     !!!!!!!!!!!!!!!!!!!!!!!!!
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	scanf("%lld",&t);
//	t=3;
	for(int tt=1;tt<=t;tt++){
//		if(tt<=6 or  tt>=9)continue;
		memset(f,0,sizeof(f));
		memset(d,0,sizeof(f));
//		cout << tt << endl;
		scanf("%lld",&n);
//		n=1000;
		int maxx=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			maxx=max(maxx,a[i]);			
		}
//		cout << maxx<<endl;
		if(n<=15){
			
			printf("%lld\n", dfs(1,0,0));
		}
		
		else if(n<=100){
			printf("%lld\n", dfs(1,0,0));
		}
//		else if(maxx<=10){
		else {
//			cout << "fsda";
			printf("%lld\n", dfsmall(1,0,0));
		}
//		else continue;
		
		
	}
//	printf("543543");
//	for(int i=1;i<=n;i++){
//		for(int jjj=1;jjj<i;jjj++){
//			int j=a[jjj];
//			f[i][0].v=max(f[i-1][0].v+(a[i]==a[i-1])*a[i],f[i-1][1].v+(a[i]==f[i-1][1].wrong_last)*)a[i];
////			f[i][j][0].v=max(f[i-1][0].v+(a[i]==a[i-1])*a[i],f[i-1][1].v+(a[i]==f[i-1][1].wrong_last)*)a[i];
//			f[i][j][0].wrong_last
//			f[i][0].v=max(f[i-1][0]+(a[i]==a[i-1])*a[i]+f[i-1][1]+(a[i]==last)*a[i]);
//			f[i][a[i]][0]=max(f[i-1][0]+(a[i]==a[i-1])*a[i]+f[i-1][1]+(a[i]==last)*a[i]);
//			f[i][j][1]
//		}
//	}
	return 0;
}
