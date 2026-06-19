#include<bits/stdc++.h>
using namespace std;

const long long N=5e3+5,md=998244353;
long long n;
long long a[N];
long long ans;
bool tepan;

bool check(string s){
	long long sum=0,maxx=0,cnt=0;
	for(long long i=0;i<s.size();i++){
		if(s[i]=='1'){
			cnt++;
			sum+=a[i+1];
			maxx=max(maxx,a[i+1]);
		}
	}
	return (cnt>=3 and (sum>maxx*2));
}
void dfs(string s){
	if(s.size()==n){
		if(check(s)){
			ans++;
			ans%=md;
		}
		return ;
	}
	dfs(s+'0');
	dfs(s+'1');
	return ;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	tepan=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			tepan=0;
		}
	}
	if(tepan==1){
		ans=1;
		for(long long i=1;i<=n;i++){
			ans*=2;
			ans%=md;
		}
		ans--;
		ans-=n;
		ans-=(n*(n-1)/2);
		while(ans<0){
			ans+=md;
		}
		ans%=md;
		cout<<ans%md<<"\n";
		return 0;
	}
	dfs("");
	cout<<ans%md<<"\n";
	return 0;
}
