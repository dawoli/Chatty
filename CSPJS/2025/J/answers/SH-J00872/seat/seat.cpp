#include<bits/stdc++.h>
using namespace std;
int N=0,M=0,A=0,K=0,B=0,H=0,G=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>N>>M;
	if(N==1&&M==1){
		cout<<1<<' '<<1;
		return 0; 
	}
	int R[N*M+2];
	int P[101];
	cin>>R[1];
	A=R[1];
	for(int I=2;I<=N*M;I++){
		cin>>R[I];
		G++;
	}
	for(int S=1;S<=G;S++){
		B=R[S];
		P[B]++;
	}
	for(int D=100;D>=0;D--){
		if(P[D]==1){
			R[H]=D;
			H++;
		}
	}
	
	for(int J=0;J<=H;J++){
		if(R[J]==A){
			if(J%N==0){
				cout<<J/N<<' '<<N;
				break;
			}
			cout<<J/N+1<<' ';
			if((J/N+1)%2==0){
				cout<<N-J%N+1;
			}
			else if(J%N==0){
				cout<<N;
			}
			else{
				cout<<J%N; 
			} 
		}
	}
	return 0;
}
