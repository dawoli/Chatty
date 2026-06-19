#include<bits/stdc++.h>
using namespace std;
long long a[999],n,ans;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string k;
		cin>>k;
		int now=0;
		if(k[0]=='D') 0;
		else if(k[0]=='C') now+=13;
		else if(k[0]=='H') now+=26;
		else if(k[0]=='S') now+=39;
		if(k[1]=='A') now+=1;
		else if(k[1]=='2') now+=2;
		else if(k[1]=='3') now+=3;
		else if(k[1]=='4') now+=4;
		else if(k[1]=='5') now+=5;
		else if(k[1]=='6') now+=6;
		else if(k[1]=='7') now+=7;
		else if(k[1]=='8') now+=8;
		else if(k[1]=='9') now+=9;
		else if(k[1]=='T') now+=10;
		else if(k[1]=='J') now+=11;
		else if(k[1]=='Q') now+=12;
		else if(k[1]=='K') now+=13;
		a[now]++;
	}
	for(int i=1;i<=52;i++) if(!a[i]) ans++;
	cout<<ans;
	return 0;
}
