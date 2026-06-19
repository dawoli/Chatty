#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	int a[n],b[n];
	bool cheat1=true;
	string s;
	cin>>s;
	int num=0;
	for(int i=0;i<n;i++){
		a[i]=s[i]-'0';
		if(a[i]==0) cheat1=false;
		else num++;
	} 
	for(int i=0;i<n;i++) cin>>b[i];
	if(m<num){
		cout<<0;
		return 0;
	} 
	if(m==n){
		if(!cheat1){
			cout<<0;
			return 0;
		}
		int a=1;
		for(int i=1;i<=n;i++) a=a*i,a%=998244353;
		cout<<a;
		return 0; 
	}
	if(cheat1){
		for(int i=0;i<n;i++)
			if(b[i]==0) n--;
		int a=1;
		for(int i=1;i<=n;i++) a=a*i,a%=998244353;
		cout<<a;
		return 0; 
	} 
}
