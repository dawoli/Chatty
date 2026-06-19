#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=505;
int n,m;
bool s[N];
int c[N];
int x[N];
bool spec_a=1;
void solve_brutal(){
	int r=0;
	for(int i=1;i<=n;i++)	x[i]=i;
	while(next_permutation(x+1,x+n+1)){
		int cnt=0,ans=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[x[i]]){
				++cnt;
				continue;
			}
			if(s[i]){
				++ans;
			}
		}
		if(ans>=m)	r=max(r,ans);
	}
	printf("%d\n",r);
	return;
}	
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string str;
	cin>>str;
	for(int i=0;i<n;i++){
		if(str[i]=='0') s[i+1]=0;
		else s[i+1]=1;
		if(s[i+1]!=1)	spec_a=0;
	}
	for(int i=1;i<=n;i++)	cin>>c[i];
	if(n<=10){
		solve_brutal();//10pts
	}
	else if(spec_a){//25pts
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod;
		}
		printf("%d\n",ans%mod);
	}
	else if(m==1){//10pts
		bool pd=0;
		for(int i=1;i<=n;i++){
			if(s[i]){
				pd=1;
				break;
			}
		}
		if(pd){
			int ans=1;
			for(int i=1;i<=n;i++){
				ans=(ans*i)%mod;
			}
			printf("%d\n",ans%mod);
		}
		else cout<<0<<endl;
	}
	return 0;
}
