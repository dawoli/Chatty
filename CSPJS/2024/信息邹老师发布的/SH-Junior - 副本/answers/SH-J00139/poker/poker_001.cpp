#include<bits/stdc++.h>
using namespace std;
int b[114][114],s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		char c,h;
		cin>>c>>h;
		
		if(h=='A')b[c][1]=1;
		else if(h=='T')b[c][10]=1;
		else if(h=='J')b[c][11]=1;
		else if(h=='Q')b[c][12]=1;
		else if(h=='K')b[c][13]=1;
		else b[c][h-'0']=1;
	}
	for(int i=1;i<=13;i++){
		if(b['S'][i]==0) s++;
		if(b['C'][i]==0) s++;
		if(b['D'][i]==0) s++;
		if(b['H'][i]==0) s++;
	}cout<<s;
	return 0;
}
