#include <bits/stdc++.h>
using namespace std;
int n;
int tts=0;
int cldkl=0;//¿É»÷É± 
int r[100010]={};
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		r[x]++;
	}
	for(int i=1;i<=100005;i++){
		tts+=min(cldkl,r[i]);
		cldkl=max(0,cldkl-r[i]);
		cldkl+=r[i];
	}
	cout<<n-tts;
	return 0;
}

