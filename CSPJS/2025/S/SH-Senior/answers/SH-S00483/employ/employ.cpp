#include <iostream>
#include <algorithm>
#define int long long

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std; 
const int mod= 998244353;
int s[10005];
int c[10005];int n,m;
int qianzhui0[10005];
int ansq[10005];int ans=0;
int f[20];int vis[20];
int jiechen(int u){
	int ans=1;
	for(int i=u;i>=1;i--){
		ans=ans%mod*i%mod;
	}
	return ans;
}
bool cmp(int a,int b){
	return a>b;
}
bool check (){
//	cout << "fd";
	int now0=0,sum=0;
	for(int i=1;i<=n;i++){
		if(s[i]==0 or c[f[i]]<=sum){
			sum++;
		}
	}
	int anss=n-sum;
//	cout << anss;
	return anss>=m;
}
void dfs(int step){
	if(step==n+1){
		ans+=check();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		f[step]=i;
		vis[i]=1;
		dfs(step+1);
		vis[i]=0;
		
	}
}
signed main(int argc, char** argv) {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
//	scanf("%lld %lld",&n,&m);
	cin >> n >> m;
	int flag=1;
	int qian=0;
	for(int i=1;i<=n;i++){
//		scanf("%lld",&s[i]);
		char c;
		cin >> c;
		s[i]=c-'0';
		qianzhui0[i]=qian;
		if(s[i]==0){
			qian+=1;
			flag=0;
		}
		
	}
	
	qianzhui0[n+1]=qianzhui0[n];
	if(s[n]==0){
		qianzhui0[n+1]++;
	}
	for(int i=1;i<=n;i++){
//		scanf("%lld",&c[i]);
		cin >> c[i];
	}
	if(flag==1){
//		printf("%lld",jiechen(n));
		cout << jiechen(n) << endl;
	}
	else if(m==n){
		if(flag==0){
			cout << "0" << endl;
		}
		
	}
	else if(n<=10){
		dfs(1);
		cout << ans << endl;
	} 
	else if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			int t=upper_bound(qianzhui0+1,qianzhui0+n+1,c[i])-qianzhui0;
			t=t-1;
			t=t-qianzhui0[t+1];
			ansq[i]=t;
		}
		sort(ansq+1,ansq+n+1,cmp);
		for(int i=1;i<=n;i++){
			int t=ansq[i];
//			cout << t << " ";
//			t=t-1;
//			cout << t << " " ;
//			t=t-qianzhui0[t+1];
//			cout << t << endl;
			
			if(t<=0)continue;
			int partans=1;
			int tt=n-2;
			for(int j=1;j<i;j++){
				partans=partans%mod*tt%mod;
				tt--;
			}
			partans=partans*t%mod;
			partans=partans*jiechen(n-i)%mod;
			ans+=partans;
			ans%=mod;
		}
		cout << ans;
		
	}
	
	return 0;
}
/*
10 1
1101111011
6 0 4 2 1 2 5 4 3 3

10 1
0000011100
6 5 4 2 1 2 0 4 3 3
*/
