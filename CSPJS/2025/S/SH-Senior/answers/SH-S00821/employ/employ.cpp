#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int Mod=998244353;
int cnt=0,n,m,p;
int c[505],f[1005][1005];
char s[505];
int a(int n,int m){
	int ans=1;
	if(n/2>=m){
		for(int i=n;i>=n-m;i--)
			ans=ans*i%Mod; 
		for(int i=1;i<=m;i++)
			ans/=i;
	}
	else {
		for(int i=n;i>=m;i--)
			ans=ans*i%Mod; 
		for(int i=1;i<=n-m;i++)
			ans/=i;
	}
	return ans%Mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)	cin>>c[i];
	
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(s[i]==0)		cnt++;
		cout<<a(m,cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
