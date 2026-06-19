#include<bits/stdc++.h>
using namespace std;
int q,ans;
bool vis[53]; 
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>q;
	for(int i=0;i<q;i++){
		char pai_hs,pai_sz;
		int numm=0;
		cin>>pai_hs>>pai_sz;
		if(pai_hs=='D') numm+=0;
		else if(pai_hs=='C') numm+=1;
		else if(pai_hs=='H') numm+=2;
		else if(pai_hs=='S') numm+=3;
		if((int)pai_sz>='2'&&(int)pai_sz<='9') numm+=((int)pai_sz-49)*4;
		else if(pai_sz=='A') numm+=0;
		else if(pai_sz=='T') numm+=36;
		else if(pai_sz=='J') numm+=40;
		else if(pai_sz=='Q') numm+=44;
		else if(pai_sz=='K') numm+=48;
		//cout<<numm<<endl;
		vis[numm]=1;
	}
	for(int i=0;i<52;i++){
		if(vis[i]==0) ans++;
	}
	cout<<ans;
	return 0;//wish that dreams shine
} 
