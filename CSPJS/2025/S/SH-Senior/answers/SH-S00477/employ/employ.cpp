#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
#define fr1(i,a,b,k) for(int i=a;i<=b;i+=k)
#define fr2(i,a,b,k) for(int i=a;i>=b;i-=k)
using namespace std;
int n,m,s[505],c[505],fs1,ans=1,mod=998244353;
char str;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	fr1(i,1,n,1){
		cin>>str;
		s[i]=(str=='0'?0:1);
		if(s[i]==0){
			fs1=1;
		}
	}
	fr1(i,1,n,1){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	if(fs1==0){
		int cnt=1;
		fr1(i,1,n,1){
			if(c[i]==0){
				continue;
			}
			(ans*=cnt)%=mod;
			cnt++;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
