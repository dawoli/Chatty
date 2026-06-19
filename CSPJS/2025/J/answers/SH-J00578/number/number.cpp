#include <bits/stdc++.h>
using namespace std;
int A[10];
string S;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>S;
	for(int I=0;I<S.size();I++){
		if(S[I]>='0'&&S[I]<='9'){
			A[S[I]-'0']++;
		}
	}
	for(int I=9;I>=0;I--){
		while(A[I]--){
			cout<<I;
		}
	}
	return 0;
}
