#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int n;
const int N=15;
bool D[N],C[N],H[N],S[N];
int cnt;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char s[5]={};
		cin>>s[0]>>s[1];
		if(s[0]=='D'){
			if(s[1]=='A') 		D[ s[1]+1-'A' ] = 1;//'A' -> '1'
			else if(s[1]=='T') D[ s[1]+10-'T' ] = 1;
			else if(s[1]=='J') D[ s[1]+11-'J' ] = 1;
			else if(s[1]=='Q') D[ s[1]+12-'Q' ] = 1;
			else if(s[1]=='K') D[ s[1]+13-'K' ] = 1;
			else 				D[ s[1] - '0' ] =1;
		}
		else if(s[0]=='C'){
			if(s[1]=='A') 		C[ s[1]+1-'A' ] = 1;//'A' -> '1'
			else if(s[1]=='T') C[ s[1]+10-'T' ] = 1;
			else if(s[1]=='J') C[ s[1]+11-'J' ] = 1;
			else if(s[1]=='Q') C[ s[1]+12-'Q' ] = 1;
			else if(s[1]=='K') C[ s[1]+13-'K' ] = 1;
			else 				C[ s[1] - '0' ] =1;
		}
		else if(s[0]=='H'){
			if(s[1]=='A') 		H[ s[1]+1-'A' ] = 1;//'A' -> '1'
			else if(s[1]=='T') H[ s[1]+10-'T' ] = 1;
			else if(s[1]=='J') H[ s[1]+11-'J' ] = 1;
			else if(s[1]=='Q') H[ s[1]+12-'Q' ] = 1;
			else if(s[1]=='K') H[ s[1]+13-'K' ] = 1;
			else 				H[ s[1] - '0' ] =1;
		}
		else{
			if(s[1]=='A') 		S[ s[1]+1-'A' ] = 1;//'A' -> '1'
			else if(s[1]=='T') S[ s[1]+10-'T' ] = 1;
			else if(s[1]=='J') S[ s[1]+11-'J' ] = 1;
			else if(s[1]=='Q') S[ s[1]+12-'Q' ] = 1;
			else if(s[1]=='K') S[ s[1]+13-'K' ] = 1;
			else 				S[ s[1] - '0' ] =1;
		}
		/*for(int j=1;j<=13;j++){
			cout<<j<<' '<<D[j]<<endl;
			cout<<j<<' '<<C[j]<<endl;
			cout<<j<<' '<<H[j]<<endl;
			cout<<j<<' '<<S[j]<<endl;
		}*/
	}
	for(int j=1;j<=13;j++){
		if(!D[j]) cnt++;
		if(!C[j]) cnt++;
		if(!H[j]) cnt++;
		if(!S[j]) cnt++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
