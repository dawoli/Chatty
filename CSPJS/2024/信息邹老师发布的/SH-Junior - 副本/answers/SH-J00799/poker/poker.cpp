#include<bits/stdc++.h>
using namespace std;
int n,f[55],ans=52;
int solve(char c,char cc){
	int i=0,j=0;
	if(c=='D') i=0;
	else if(c=='C') i=1;
	else if(c=='H') i=2;
	else if(c=='S') i=3;
	
	if(cc=='A') j=1;
	else if(cc=='T') j=10;
	else if(cc=='J') j=11;
	else if(cc=='Q') j=12;
	else if(cc=='K') j=13;
	else j=cc-'0';
	
	return i*13+j;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char ch1,ch2;
		cin>>ch1>>ch2;
		if(f[solve(ch1,ch2)]==0){
			ans--;
			f[solve(ch1,ch2)]=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
