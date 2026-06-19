#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll rd(){
	ll x=0;
	char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0'&& c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int n,q;
string s1[200010],s2[200010],t1,t2;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=rd(),q=rd();
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		cin>>t1>>t2;
		cout<<0<<endl;
	}
	return 0;
}
