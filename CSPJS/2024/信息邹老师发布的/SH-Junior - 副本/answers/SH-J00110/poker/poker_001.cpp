#include<bits/stdc++.h>
using namespace std;
bool D[20],C[20],H[20],S[20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);

	int n;
	cin>>n;
	char a,b;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		if(a=='D'){
			if(b>='2'&&b<='9') D[int(b-'0')]=1;
			else if(b=='A') D[1]=1;
			else if(b=='T') D[10]=1;
			else if(b=='J') D[11]=1;
			else if(b=='Q') D[12]=1;
			else if(b=='K') D[13]=1;
		}
		else if(a=='C'){
			if(b>='2'&&b<='9') C[int(b-'0')]=1;
			else if(b=='A') C[1]=1;
			else if(b=='T') C[10]=1;
			else if(b=='J') C[11]=1;
			else if(b=='Q') C[12]=1;
			else if(b=='K') C[13]=1;
		}
		else if(a=='H'){
			if(b>='2'&&b<='9') H[int(b-'0')]=1;
			else if(b=='A') H[1]=1;
			else if(b=='T') H[10]=1;
			else if(b=='J') H[11]=1;
			else if(b=='Q') H[12]=1;
			else if(b=='K') H[13]=1;
		}
		else if(a=='S'){
			if(b>='2'&&b<='9') S[int(b-'0')]=1;
			else if(b=='A') S[1]=1;
			else if(b=='T') S[10]=1;
			else if(b=='J') S[11]=1;
			else if(b=='Q') S[12]=1;
			else if(b=='K') S[13]=1;
		}
	}
	int ans=52;
	for(int i=1;i<=13;i++){
		if(D[i]) ans-=1;
	}
	for(int i=1;i<=13;i++){
		if(C[i]) ans-=1;
	}
	for(int i=1;i<=13;i++){
		if(H[i]) ans-=1;
	}
	for(int i=1;i<=13;i++){
		if(S[i]) ans-=1;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
