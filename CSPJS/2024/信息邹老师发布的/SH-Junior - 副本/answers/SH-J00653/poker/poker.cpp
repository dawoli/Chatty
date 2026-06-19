#include <bits/stdc++.h>
using namespace std;
bool f[60];int ans=52;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		string h;cin>>h;
		int j=0;
		if(h[0]=='D') j+=0;
		else if(h[0]=='C') j+=13;
		else if(h[0]=='H') j+=26;
		else j+=39;
		if(isdigit(h[1])) j+=h[1]-'0';
		else if(h[1]=='T') j+=10;
		else if(h[1]=='J') j+=11;
		else if(h[1]=='Q') j+=12;
		else if(h[1]=='A') j+=1;
		else j+=13;
		if(f[j]==0){
			ans--;
			f[j]=1;
		}
	}
	cout<<ans;
}
