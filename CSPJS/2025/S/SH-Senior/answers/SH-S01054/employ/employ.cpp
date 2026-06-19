#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N=510;
const int mod=988244353;

int a[N];
int xu[N];
int mp[N];
int b[N];
int now=1;

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(mp[a[i]]==0){
			b[now]=a[i];
			now++;
		}
		mp[a[i]]++;
	}
	sort(b+1,b+now);
	for(int i=1;i<n;i++){
		if(s[i-1]=='0'){
			xu[i]=xu[i-1]+1;
		}
		else xu[i]=xu[i-1];
	}
	int ans=1;
	if(m==1){
		for(int i=1;i<=n-1;i++){
			ans*=i;
			ans%=mod;
		}
		int sum=0;
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				for(int j=1;j<now;j++){
					if(b[j]>xu[i]) sum+=mp[b[j]],sum%=mod;
				}
			}
		}
		ans*=sum;
		ans%=mod;
		cout<<ans<<endl;
	}
	if(m==n){
		sort(a+1,a+1+n);
		bool f=1;
		for(int i=0;i<n;i++){
			if(xu[i]>a[i-1]) f=0;
		}
		cout<<0<<endl;
	}
}
