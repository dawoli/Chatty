#include<bits/stdc++.h>
using namespace std;
string S;
int F=0;
int Ton[1000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>S;
	memset(Ton,0,sizeof(Ton));
	for(int i=0;i<S.size();i++){
		if(S[i]>='0'&&S[i]<='9'){
			if(S[i]!='0') F=1;
			Ton[S[i]-'0']++;
		}
	}
	if(F==0){
		printf("0\n");
		return 0;
	}
	for(int i=9;i>=0;i--){
		while(Ton[i]>0) printf("%d",i),Ton[i]--;
	}
	return 0;
}
