#include<bits/stdc++.h>
using namespace std;

int n,ans=0,sum=0;
int a[100];
char aa,b;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>aa>>b;
		if(aa=='C') ans+=13;
		if(aa=='H') ans+=26;
		if(aa=='S') ans+=39;
		if(b>='2'&&b<='9') ans+=(b-'0');
		if(b=='T') ans+=10;
		if(b=='J') ans+=11;
		if(b=='Q') ans+=12;
		if(b=='K') ans+=13;
		if(b=='A') ans+=1;
		a[ans]=1;
		ans=0;
	}
	for(int i=1;i<=52;i++){
		if(a[i]==0){
			sum++;
		}
	}
	cout<<sum;
	
	
	return 0;
}
