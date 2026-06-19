#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	long long n,a[4][13]={0},ans=52;
	cin>>n;
	for(int i=0;i<n;i++){
		char H,S;
		cin>>H>>S;
		int h,s;
		if(H=='D'){
			h=0;
		}
		if(H=='C'){
			h=1;
		}
		if(H=='H'){
			h=2;
		}
		if(H=='S'){
			h=3;
		}
		if(S=='A'){
			s=0;
		}
		if(S=='2'){
			s=1;
		}
		if(S=='3'){
			s=2;
		}
		if(S=='4'){
			s=3;
		}
		if(S=='5'){
			s=4;
		}
		if(S=='6'){
			s=5;
		}
		if(S=='7'){
			s=6;
		}
		if(S=='8'){
			s=7;
		}
		if(S=='9'){
			s=8;
		}
		if(S=='T'){
			s=9;
		}
		if(S=='J'){
			s=10;
		}
		if(S=='Q'){
			s=11;
		}
		if(S=='K'){
			s=12;
		}
		if(!a[h][s]){
			a[h][s]=1;
			ans--;
		}
	}
	cout<<ans;
	return 0;
}
