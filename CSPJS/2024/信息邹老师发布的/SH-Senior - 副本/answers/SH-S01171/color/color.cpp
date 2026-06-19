#include<bits/stdc++.h>
using namespace std;

int T,n,a[200005];long long dp[2005][2005];
vector<int>V[1000005];set<int>s[2];

int naom(int xx,int yy){
	return xx*(xx==yy);
}

long long planA(){
	long long ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]+naom(a[i+1],a[i]));
			dp[i+1][i]=max(dp[i+1][i],dp[i][j]+naom(a[i+1],a[j]));
		}
	}
	for(int i=0;i<n;i++)ans=max(ans,dp[n][i]);
	for(int i=0;i<=n;i++){
		for(int j=0;j<i;j++){
			dp[i][j]=0;
		}
	}
	return ans;
}

long long planB(){
	long long ans=0;
	for(int o=0;o<2;o++){
		s[o].insert(0);s[o].insert(n+1);
	}
	for(int i=1;i<=n;i++){
		V[a[i]].push_back(i);
	}
	for(int i=1000000;i>=1;i--){
		for(auto uu:V[i]){
			set<int>::iterator itr1=s[0].lower_bound(uu),itr2=itr1;itr2--;
			set<int>::iterator itr3=s[1].lower_bound(uu),itr4=itr1;itr4--;
			int val1=naom(a[*itr1],i)+naom(a[*itr2],i)-naom(a[*itr1],a[*itr2]);
			int val2=naom(a[*itr3],i)+naom(a[*itr4],i)-naom(a[*itr3],a[*itr4]);
			if(val1>val2)s[0].insert(uu);
			else s[1].insert(uu);
			ans+=max(val1,val2);
		}
		V[i].clear();
	}
	s[0].clear();s[1].clear();
	return ans;
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n<=2000)cout<<planA();
		else cout<<planB();
		cout<<'\n';
	}
	cout<<endl;
	return 0;
}
