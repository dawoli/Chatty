#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string An;
	int Bn[100001],Cnt=0;
	getline(cin,An);
	for(int i=0;i<An.length();i++){
		if(int(An[i]>=48) && int(An[i])<=57){
			Bn[Cnt]=int(An[i]);
			Cnt++;
		}
	}
	sort(Bn,Bn+Cnt);
	for(int i=Cnt-1;i>=0;i--) cout<<Bn[i]-48;
	return 0;
}
