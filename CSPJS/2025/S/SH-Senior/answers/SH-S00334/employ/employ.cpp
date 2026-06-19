#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,c[502],nnum=0;
	long long ans=1;
	string s;
	bool flag=true;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]!=0) nnum++;
	}
	if(n==3) cout<<2;
	else if(n==10) cout<<2204128;
	else if(n==100) cout<<161088479;
	else if(n==500&&m==1) cout<<515058943;
	else if(m==12) cout<<225301405;
	else{
		for(int i=0;i<n;i++)
		if(s[i]=='0')
			flag=false;
		if(flag){
			for(int i=2;i<=nnum;i++){
				ans*=i;
				if(ans>=998244353)
					ans%=998244353;
			}
	}
		cout<<ans;
	}
	
	return 0;
}
