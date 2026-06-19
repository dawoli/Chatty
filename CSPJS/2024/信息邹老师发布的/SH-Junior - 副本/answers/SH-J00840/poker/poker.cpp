#include<bits/stdc++.h>
using namespace std;
int n,d[100],c[100],h[100],s[100],num,ans;
char m,k; 
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1 ; i<=n ; i++)
	{
		num=0;
		cin>>m>>k;
		if(k=='A') num=1;
		if(k=='T') num=10;
		if(k=='J') num=11;
		if(k=='Q') num=12;
		if(k=='K') num=13;
		else if(num==0) num=k-'0';
		if(m=='D') d[num]=1;
		if(m=='C') c[num]=1;
		if(m=='H') h[num]=1;
		if(m=='S') s[num]=1;
	}
    for(int i=1 ; i<=13 ; i++)
    {
    	if(d[i]==0) ans++;
    	if(c[i]==0) ans++;
    	if(h[i]==0) ans++;
    	if(s[i]==0) ans++;
	}
	cout<<ans;
}

