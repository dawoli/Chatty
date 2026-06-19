#include<bits/stdc++.h>
using namespace std;
int s[5][17],n;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		char a,num;cin>>a>>num;int h,d; 
		if(a=='D') h=1;
		else if(a=='C') h=2;
		else if(a=='H') h=3;
		else if(a=='S') h=4;	
		d=num-'0';
		if(num=='A') d=1;
		else if(num=='T') d=10;
		else if(num=='J') d=11;
		else if(num=='Q') d=12;
		else if(num=='K') d=13;
		s[h][d]=1;
	}
	int ans=52;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(s[i][j]==1){
				ans--;
			}
		}
	}                    
	cout<<ans;
	return 0;
} 
