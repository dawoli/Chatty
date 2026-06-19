#include<bits/stdc++.h> 
using namespace std;
bool a[60]={};
int n,ans=52;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		int b=0;
		if(s[0]=='S') b+=39;
		else if(s[0]=='D') b+=13;
		else if(s[0]=='H') b+=26;
		if(s[1]=='A') b++;
		else if(s[1]=='K') b+=13;
		else if(s[1]=='Q') b+=12;
		else if(s[1]=='J') b+=11;
		else if(s[1]=='T') b+=10;
		else b=b+(s[1]-'0');
		a[b]=1;
	}
	for(int i=1;i<=52;i++)
	{
		if(a[i]) ans--;
	}
	cout<<ans<<endl;
	return 0;
}
