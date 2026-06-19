#include<bits/stdc++.h>
using namespace std;
int n,mod=998244353;
long long ans;
int a[5010],p[5010];
int b[5010];
int mem[5010];

//10:30 9 X 4=36 tps
//10:43 16 X 4=64 tps

long long C(int n,int m){
	memset(p,0,sizeof(p));
	if(m>n-m)m=n-m;
	for(int i=n;i>=n-m+1;i--){
		int tp=i;
		for(int j=2;j*j<=tp;j++){
			while(tp%j==0)p[j]++,tp/=j;
		}
		p[tp]++;
	}
	for(int i=1;i<=m;i++){
		int tp=i;
		for(int j=2;j*j<=tp;j++){
			while(tp%j==0)p[j]--,tp/=j;
		}
		if(tp!=1)p[tp]--;
	}
	long long w=1;
	for(int i=1;i<=5000;i++){
		for(int j=1;j<=p[i];j++)w*=i,w%=mod;
	}
	return w%mod;
}

void planA(){
	for(int i=3;i<=n;i++){
		if(mem[i]==0 && mem[n-i]==0){
			mem[i]=mem[n-i]=C(n,i);
		}
		ans+=mem[i];
		ans%=mod;
	}
	cout<<ans<<endl;
	return;
}

void planB(){
	if(a[3]>=a[2]+a[1])cout<<0;
	else cout<<1;
	return;
}

void dfs(int x,int now,int sum){
	if(now==n+1){
		if(x<3)return;
		if(sum>2*p[x]){
			ans++;
		}
		return;
	}
	p[x+1]=a[now];
	dfs(x+1,now+1,sum+a[now]);
	dfs(x,now+1,sum);
}

void planC(){
	dfs(0,1,0);
	cout<<ans%mod;
}

void planD(){
	int ans=0;
	vector<int> dp[501];
	for(int i=0;i<=n;i++){
		for(int j=1;j<=n*101;j++){
			dp[i].push_back(-INT_MAX);
		}
	}
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=n*100;j>=0;j--){
			for(int k=1;k<=n;k++){
				dp[i][j]=max(dp[i][j],dp[i-1][j]);
				if(j<a[k])continue;
				if(j>a[k]*2){
					dp[i][j]=max(dp[i][j],dp[i-1][j-a[k]]+1);
				}
				else dp[i][j]=max(dp[i][j],dp[i-1][j-a[k]]);
				dp[i][j]%=mod;
			}	
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=15;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
    }
	for(int i=1;i<=n*100;i++){
		ans=max(ans,dp[n][i]);
	}
	cout<<ans<<endl;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	if(n==3){
		planB();
		return 0;
	}
	if(a[n]==1){
		planA();
		return 0;
	}
	if(n<=20){
		planC();
		return 0;
    }
	if(n<=500){
		planD();
		return 0;
	}
}
