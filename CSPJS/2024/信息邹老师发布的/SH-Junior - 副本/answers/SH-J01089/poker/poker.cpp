#include <bits/stdc++.h>
using namespace std;
bool d[14],c[14],h[14],s[14];
int main(){
	freopen("pocker.in","r",stdin);
	freopen("pocker.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		char x,y;
		cin>>x>>y;
		if(x=='D'){
			if('2'<=y&&y<='9') d[y-'0']=true;
			else{
				if(y=='T') d[10]=true;
				else if(y=='A') d[1]=true;
				else if(y=='J') d[11]=true;
				else if(y=='Q') d[12]=true;
				else d[13]=true;
			}
		}
		else if(x=='C'){
			if('2'<=y&&y<='9') c[y-'0']=true;
			else{
				if(y=='T') c[10]=true;
				else if(y=='A') c[1]=true;
				else if(y=='J') c[11]=true;
				else if(y=='Q') c[12]=true;
				else c[13]=true;
			}
		}
		else if(x=='H'){
			if('2'<=y&&y<='9') h[y-'0']=true;
			else{
				if(y=='T') h[10]=true;
				else if(y=='A') h[1]=true;
				else if(y=='J') h[11]=true;
				else if(y=='Q') h[12]=true;
				else h[13]=true;
			}
		}
		else if(x=='S'){
			if('2'<=y&&y<='9') s[y-'0']=true;
			else{
				if(y=='T') s[10]=true;
				else if(y=='A') s[1]=true;
				else if(y=='J') s[11]=true;
				else if(y=='Q') s[12]=true;
				else s[13]=true;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=13;i++) if(!d[i]) ans++;
	for(int i=1;i<=13;i++) if(!c[i]) ans++;
	for(int i=1;i<=13;i++) if(!h[i]) ans++;
	for(int i=1;i<=13;i++) if(!s[i]) ans++;
	cout<<ans;
	return 0;
} 
