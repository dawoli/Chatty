#include<bits/stdc++.h>
using namespace std;
int k[4][13];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,z1,z2,sum=0;
	char a,d;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>d;
		if(a=='D') z1=1;
		if(a=='C') z1=2;
		if(a=='H') z1=3;
		if(a=='S') z1=4;
		if(d=='A') z2=1;
		if(d=='2') z2=2;
		if(d=='3') z2=3;
		if(d=='4') z2=4;
		if(d=='5') z2=5;
		if(d=='6') z2=6;
		if(d=='7') z2=7;
		if(d=='8') z2=8;
		if(d=='9') z2=9;
		if(d=='T') z2=10;
		if(d=='J') z2=11;
		if(d=='Q') z2=12;
		if(d=='K') z2=13;
		k[z1][z2]=1;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(k[i][j]==0) sum++;
		}
	}
	cout<<sum;
	return 0;
} 
