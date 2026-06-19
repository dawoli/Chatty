#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
string s;
int n,m,a[550];
int sx[15]={0,1,2,3,4,5,6,7,8,9,10};
bool chks1(){
	for(int i = 0;i<s.size();i++)
		if(s[i]!=49)return 0;
	return 1;
}
int jc(int n){
	if(n<=1)return 1;
	return n*jc(n-1)%mod;
}
bool chkm1(){return m==1;}
bool chkmn(){return m==n;}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i = 1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(chks1())cout<<jc(n)<<endl;
	else if(chkmn())cout<<0<<endl;
	else if(chkm1()){
		int mn=1e9;
		for(int i = 0;i<s.size();i++)
			if(s[i]==49){mn=i;break;}
		if(mn>=1e8){cout<<0;return 0;}
		int cnt=lower_bound(a+1,a+n+1,mn)-a;
		cout<<(n-cnt+1)*jc(n-1)%mod;
	}		
	else{
		int cnt1=0;
		for(int i = 0;i<s.size();i++)cnt1+=s[i]-48;
		if(cnt1<m){cout<<0;return 0;}
		int ans=0;
		for(int i = 1;i<=jc(n);i++){
			int cnt=0,fail=0;
			for(int j = 1;j<=n;j++){
				if(s[j-1]==48 or fail>=a[sx[j]])fail++;
				else cnt++;
			}
			if(cnt>=m)ans++;
			next_permutation(a+1,a+n+1);
		}
		cout<<ans;
	}
}
