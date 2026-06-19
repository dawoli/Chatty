#include <bits/stdc++.h>
using namespace std;

struct node{
	string d;
	int w;
};
node dp[100010];
int mi,t,n,flag;
string mis;
bool dx(string a,string b){
	int len=min(a.length(),b.length());
	for (int i=0;i<len;i++){
		if (a[i]-'0'>b[i]-'0')  return 0;
		if (b[i]-'0'>a[i]-'0')  return 1;
	}
	return 0;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	dp[0].d=dp[1].d="a",dp[2].d="1",dp[3].d="7",dp[4].d="4",dp[5].d="2",dp[6].d="0",dp[7].d="8";
	dp[0].w=dp[1].w=dp[2].w=dp[3].w=dp[4].w=dp[5].w=dp[6].w=dp[7].w=1;
	for (int i=8;i<=1000;i++){
		mi=INT_MAX,flag=0;
		mis="z";
		for (int j=2;j<=i-2;j++)  mi=min(dp[j].w+dp[i-j].w,mi);
		dp[i].w=mi;
		for (int j=2;j<=i-2;j++){
			string s=dp[j].d+dp[i-j].d;
			if (dp[j].w+dp[i-j].w==mi){
				for (int j=0;j<s.length();j++){
			        if (s[j]=='0')  s[j]='6';
			        if (s[j]!='0')  break;
		        }
				if (flag==0){
				    mis=s;
			        flag=1;
			    }
				if (dx(s,mis)){
					mis=s;
				}
			}
		}
		for (int j=0;j<dp[i].d.length();j++){
			if (dp[i].d[j]=='0')  dp[n].d[j]='6';
			if (dp[i].d[j]!='0')  break;
		}
		dp[i].d=mis;
	}
	cin>>t;
	while (t--){
		cin>>n;
		if (n%7==0){
			for (int i=0;i<n/7;i++){
				cout<<"8";
			}
			cout<<"\n";
		}else{
			if (dp[n].d=="a")  cout<<-1<<"\n";
		    else{
		        for (int i=0;i<dp[n].d.length();i++){
			        if (dp[n].d[i]=='0')  dp[n].d[i]='6';
			        if (dp[n].d[i]!='0')  break;
		        }
			    cout<<dp[n].d<<"\n";
		    }
		}
		
	}
	return 0;
}
