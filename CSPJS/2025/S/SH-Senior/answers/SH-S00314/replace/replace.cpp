#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[200005],ss[200005],t,tt,k[200005],kk[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i]>>ss[i];
	for(int i=1;i<=n;i++){
		int ddd,dddd;
		int ssz=s[i].size();
		for(int j=0;j<ssz;j++)
			if(s[i][j]!=ss[i][j]){ddd=j;break;}
		for(int j=ssz-1;j>=0;j--)
			if(s[i][j]!=ss[i][j]){dddd=j;break;}
		for(int j=ddd;j<=dddd;j++)k[i]+=s[i][j],kk[i]+=ss[i][j];
	}
	while(m--){
		int d,dd,ans=0;
		string b="",bb="";
		cin>>t>>tt;
		int tsz=t.size();
		for(int i=0;i<tsz;i++)
			if(t[i]!=tt[i]){d=i;break;}
		for(int i=tsz-1;i>=0;i--)
			if(t[i]!=tt[i]){dd=i;break;}
		for(int i=d;i<=dd;i++)b+=t[i],bb+=tt[i];
		for(int i=1;i<=n;i++)
		    if(k[i]==b&&kk[i]==bb)ans++;
		cout<<ans<<endl;
	}
	return 0;
}
