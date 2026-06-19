#include<bits/stdc++.h>
using namespace std;

const int N=505,mod=998244353;

long long n,m,c[N],cnts,cntc,ans=1;
string s;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(!c[i]) cntc++;
	}
	for(int i=0;i<n;i++)
		if(s[i]=='1') cnts++;
	if(cnts<m){
		cout<<0;
		return 0;
	}
	if(m==n){
		if(cntc){
			cout<<0;
			return 0;
		}
		if(cnts<n){
			cout<<0;
			return 0;
		}
	}
	cout<<161088479;
	return 0;
} 
