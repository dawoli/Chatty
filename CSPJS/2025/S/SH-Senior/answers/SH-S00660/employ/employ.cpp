#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,s[510],c[510],d[510],a[510],cnt,ans;
char ch;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>ch,s[i]=ch-'0';
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=18){
		for(int i=1;i<=n;i++)a[i]=i;
		do{
			cnt=0;
			for(int i=1;i<=n;i++)d[i]=c[a[i]];
			for(int i=1;i<=n;i++)
				if(cnt>=d[i]||s[i]==0)cnt++;
			if(n-cnt>=m)ans++,ans%=mod;
		}while(next_permutation(a+1,a+n+1));
		cout<<ans<<"\n";
	}
	cout<<0<<"\n";
	return 0;
}
