#include<bits/stdc++.h>
using namespace std;
string er(int x){
	string s="";
	while(1){
		if(x==1){
			s+='1';
			break;
		}
		s+=x%2+'0';
		x/=2;
	}
	return s;
}
int axor(int an,int m){
	int ans=0;
	string ns=er(an),ms=er(m);
	if(ns.size()>ms.size()) swap(ns,ms);
	for(int i=0;i<ns.size();i++){
		if(ms[i]!=ns[i]) ms[i]='1';
		else ms[i]='0';
	}
	for(int i=0;i<ms.size();i++)
		ans+=(ms[i]-'0')*pow(2,i);
	return ans;
}
int a[500009];
int qu(int r,int am){
	for(int i=r+1;i<=am;i++)
		a[i]=axor(a[i-1],a[i]);
	return a[am];
}
int t[500009][500009],su[500009],f[500009];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(qu(i,j)==k)
				t[j][++su[j]]=i;
	f[0]=0;
	for(int i=1;i<=n;i++){
		int p[500009],en=0;
		for(int j=1;j<=su[i];j++)
			p[++en]=t[i][j]-1;
		p[0]=f[i-1];
		f[i]=*max_element(p,p+en+1);
	}
	cout<<f[n];
	return 0;
}
