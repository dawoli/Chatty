#include <bits/stdc++.h>
using namespace std;
int N,M,S[110],Num,C,R;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>N>>M>>S[1];
	for(int I=2;I<=N*M;I++){
		cin>>S[I];
		if(S[I]>S[1]){Num++;}
	}
	C=Num/N+1,R=Num-(C-1)*N+1;
	if(C%2==0){R=N+1-R;}
	cout<<C<<' '<<R;
	return 0;
}
