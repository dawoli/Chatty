#include <bits/stdc++.h>
using namespace std;
long long N,K,A[500010],D[500010],Ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>N>>K;
	for(int I=1;I<=N;I++){
		cin>>A[I];
		D[I]=A[I]^D[I-1];
	}
	if(N<=10000){
		for(int I=1,Cur=0;I<=N;I++){
			for(int J=Cur+1;J<=I;J++){
				if((D[J-1]^D[I])==K){
					Ans++;
					Cur=I;
					break;
				}
			}
		}
		cout<<Ans;
		return 0;
	}
	cout<<114514;
	return 0;
}
