#include<bits/stdc++.h>
using namespace std;
int n,cnt[100];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char x,y;
		cin>>x>>y;
		int now=0;
		if(x=='D') ;
		else if(x=='C') now=13;
		else if(x=='H') now=26;
		else now=39;
		if(y=='A') ;
		else if(y>='2'&&y<='9') now+=(y-'1');
		else if(y=='T') now+=9;
		else if(y=='J') now+=10;
		else if(y=='Q') now+=11;
		else now+=12;
		cnt[now]=1;
	}
	int ans=52;
	for(int i=0;i<52;i++)
		if(cnt[i]) ans--;
	cout<<ans<<endl;
	return 0;
}
