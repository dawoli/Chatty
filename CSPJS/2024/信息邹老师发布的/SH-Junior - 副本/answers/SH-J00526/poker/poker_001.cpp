#include <bits/stdc++.h>
using namespace std;
int d[100],c[100],h[100],s[100];
int pd(char IO){
	if(IO=='A')return 1;
	if(IO=='T')return 10;
	if(IO=='J')return 11;
	if(IO=='Q')return 12;
	if(IO=='K')return 13;
	if(IO>='0'&&IO<='9'){
		return (int)(IO-'0');
	}
	return 99;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	string sr;
	int n;
	cin>>n;
	int ans=52;
	for(int i=1;i<=n;i++){
		cin>>sr;
		if(sr[0]=='D')d[pd(sr[1])]=1;
		else if(sr[0]=='C')c[pd(sr[1])]=1;
		else if(sr[0]=='H')h[pd(sr[1])]=1;
		else if(sr[0]=='S')s[pd(sr[1])]=1;
	}
	for(int i=1;i<=13;i++){
		ans-=d[i];
	}
	for(int i=1;i<=13;i++){
		ans-=c[i];
	}
	for(int i=1;i<=13;i++){
		ans-=h[i];
	}
	for(int i=1;i<=13;i++){
		ans-=s[i];
	}
	cout<<ans<<endl;
	
	return 0;
}

