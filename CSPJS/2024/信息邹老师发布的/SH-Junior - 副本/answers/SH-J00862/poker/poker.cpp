#include <bits/stdc++.h>
using namespace std;
int pai[10][100],n;
int main(){
	freopen("poker.in ","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		string wpp;
		cin>>wpp;
		int flow,dot;
		if(wpp[0]=='C')flow=0;
		if(wpp[0]=='S')flow=1;
		if(wpp[0]=='H')flow=2;
		if(wpp[0]=='D')flow=3;
		if(wpp[1]=='A')dot=0;
		else if(wpp[1]=='T')dot=9;
		else if(wpp[1]=='J')dot=10;
		else if(wpp[1]=='Q')dot=11;
		else if(wpp[1]=='K')dot=12;
		else {
			dot=wpp[1]-'0'-1;
		}
		pai[flow][dot]=1;
	}
	int cnt=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			if (pai[i][j]!=1)cnt++;
		}
	} 
	cout<<cnt<<endl;
	return 0;
}
