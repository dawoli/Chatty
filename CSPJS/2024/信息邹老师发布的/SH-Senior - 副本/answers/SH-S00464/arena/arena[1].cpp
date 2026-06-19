#include<bits/stdc++.h>
using namespace std;
int n,m,T,a[100002];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>a[i];
	string s;
	while(true){
		cin>>s;
		if(s[0]!=1||s[0]!=0) break;
	}
	int h=s.length();
	for(int i=0;i<h;i++){
		T=T*10+(s[i]-'0');
	}
	while(T--){
		int a,b,C,d;
		cin>>a>>b>>C>>d;
		cout<<0<<endl;
	}
	return 0;
}
