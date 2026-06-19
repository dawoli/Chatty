#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
int m,n;
long long ans;
int b[509];
pair<int,int> c[509];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i].x,c[i].y=i,ans=max((int)ans,c[i].x);
	sort(c+1,c+1+n);
	if(m==1){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	if(n==m) {
		cout<<'0';
		return 0;
	}
	int f=0;
	b[0]=s[0];
	if(s[0]!=1) f=1;
	for(int i=1;i<s.size();i++) {
		if(s[i]!=1) f=1;
		b[i]=b[i-1]+s[i];
	}
	if(f==0){
		long long sum=0;
		for(int i=1;i<=n;i++){
			sum+=b[i]*c[i].x;
			sum%=998244353;
		}
		cout<<sum;
		return 0;
	}
	cout<<ans;
	return 0;
}
