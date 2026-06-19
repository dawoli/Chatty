#include<bits/stdc++.h>
using namespace std;
string S;
char C[1000001];
int T[11];
char I=0,J=0,D=0;
int main(){
//	freopen("number4.in","r",stdin);
//	freopen("number4.out","w",stdout);
	
	cin>>S;
	if(S.size()==1){
		cout<<S;
	}
	if(S.size()==2){
		if(S[0]>='0'&&S[0]<='9'&&(S[1]<'0'||S[1]>'9')){
			cout<<S[0];
		}
		if(S[1]>='0'&&S[1]<='9'&&(S[0]<'0'||S[0]>'9')){
			cout<<S[1];
		}
		if(S[0]>='0'&&S[0]<='9'&&S[1]>='0'&&S[1]<='9'){
			if(S[0]>=S[1]){
				cout<<S[0]<<S[1];
			}
			else{
				cout<<S[1]<<S[0];
			}
		}
	}
	return 0;
}
