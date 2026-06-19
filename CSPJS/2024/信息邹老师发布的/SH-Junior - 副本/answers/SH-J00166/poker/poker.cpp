#include <bits/stdc++.h>  //使用数组储存每张牌是否存在 输出为0的元素个数 
using namespace std;
int n,ans=0,d[14],c[14],h[14],s[14];
int to_num(char a){
	if('2'<=a&&a<='9'){
		return a-'0';
	}
	if(a=='A') return 1;
	if(a=='J') return 11;
	if(a=='Q') return 12;
	if(a=='K') return 13;
	if(a=='T') return 10;
	return 0; 
}
string t;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		if(t[0]=='D') d[to_num(t[1])]=1;
		else if(t[0]=='C') c[to_num(t[1])]=1;
		else if(t[0]=='H') h[to_num(t[1])]=1;
		else if(t[0]=='S') s[to_num(t[1])]=1;
	}
	for(int i=1;i<=13;i++){
		if(!d[i]) ans++;
		if(!c[i]) ans++;
		if(!h[i]) ans++;
		if(!s[i]) ans++;
	}
	cout<<ans;
	return 0;
}
