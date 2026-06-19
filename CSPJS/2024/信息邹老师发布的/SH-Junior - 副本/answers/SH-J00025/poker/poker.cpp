#include<bits/stdc++.h>
using namespace std;
bool H[4][15];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char a,b;
		cin>>a>>b;
		int k=0,p=0;
		if(b=='A')k=1;
		else if(b=='2')k=2;
		else if(b=='3')k=3;	
		else if(b=='4')k=4;	
		else if(b=='5')k=5;	
		else if(b=='6')k=6;	
		else if(b=='7')k=7;	
		else if(b=='8')k=8;	
		else if(b=='9')k=9;	
		else if(b=='T')k=10;	
		else if(b=='J')k=11;	
		else if(b=='Q')k=12;	
		else if(b=='K')k=13;
		if(a=='D')p=1;
		else if(a=='C')p=2;
		else if(a=='H')p=3;
		else if(a=='S')p=4;
		H[p][k]=1;			
	}
	long long ans=0;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=13;j++)
			if(H[i][j]==0)ans++;
	cout<<ans<<endl;
	return 0;
} 
