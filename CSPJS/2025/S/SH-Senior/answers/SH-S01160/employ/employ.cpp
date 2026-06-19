#include <bits/stdc++.h>
using namespace std;
int n,m;
int cnt=0;
const int Mod=998244353;
string str;
int s[510];
bool flag[510];
struct A{
	int id,c;
}aa[510];
A a[510];
int f(int x){
	if(x==1) return 1;
	return x*f(x-1)%Mod;
}
int chk(int q){
	int rp=0;
	int br=0;
	for(int i=1;i<=q;i++){
		if(s[i]==1&&br<a[i].c) rp++;
		else br++;
	}
	return rp;
}
void find(int p){
	int xhh=chk(p-1);
	if(p>n){
		if(xhh>=m) cnt=(cnt+1)%Mod;
		return;
	}
	if(xhh>=m){
		cnt+=f(n-p+1)%Mod;
		return;
	}
	if(xhh+n-p+1<m) return;
	for(int i=1;i<=n;i++){
		if(!flag[i]){
			flag[i]=true; 
			a[p]=aa[i];
			find(p+1);
			flag[i]=false;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]=='0') s[i+1]=0;
		if(str[i]=='1') s[i+1]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>aa[i].c;
	}
	find(1);
	cout<<cnt%Mod<<endl;
	return 0;
}
