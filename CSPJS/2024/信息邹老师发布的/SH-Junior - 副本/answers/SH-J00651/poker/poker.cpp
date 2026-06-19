#include<bits/stdc++.h>
using namespace std;
int n,a[60];
string s;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n;
	int i,ans=0;
	for(i=1;i<=n;i++){
		cin>>s;
		if(s[0]=='D'){
			if(s[1]<='9'&&s[1]>='1') a[s[1]-'0']=true;
			else if(s[1]=='J') a[11]=true;
			else if(s[1]=='Q') a[12]=true;
			else a[13]=true;
		}else if(s[0]=='C'){
			if(s[1]<='9'&&s[1]>='1') a[13+s[1]-'0']=true;
			else if(s[1]=='J') a[24]=true;
			else if(s[1]=='Q') a[25]=true;
			else a[26]=true;
		}else if(s[0]=='H'){
			if(s[1]<='9'&&s[1]>='1') a[26+s[1]-'0']=true;
			else if(s[1]=='J') a[37]=true;
			else if(s[1]=='Q') a[38]=true;
			else a[39]=true;
		}else {
			if(s[1]<='9'&&s[1]>='1') a[39+s[1]-'0']=true;
			else if(s[1]=='J') a[50]=true;
			else if(s[1]=='Q') a[51]=true;
			else a[52]=true;
		}
	}
	for(i=1;i<=52;i++){
		if(a[i]==false) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
