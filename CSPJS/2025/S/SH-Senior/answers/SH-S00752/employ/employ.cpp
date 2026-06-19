#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int N,M;
int Ans=0;
string S;
int C[10000];
int B[10000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>N>>M;
	cin>>S;
	for(int i=1;i<=N;i++){
		cin>>C[i];
		B[i]=i;
	}	
	do{
		int Cnt=0;
		int Cnt_F=0;
		for(int i=1;i<=N;i++){
			if(S[i-1]=='0') Cnt_F++;
			else{
				if(Cnt_F<C[B[i]]) Cnt++;
				else Cnt_F++;
			}
		}
		if(Cnt>=M) Ans++;
		Ans%=Mod;
	}while(next_permutation(B+1,B+N+1));
	printf("%d\n",Ans);
	return 0;
}
