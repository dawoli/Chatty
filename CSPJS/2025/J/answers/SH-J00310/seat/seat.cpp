#include<bits/stdc++.h>
using namespace std;
int Mn,Nn,An[101];
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int Cn=0,Rn=0,Cnt=1;
	cin>>Nn>>Mn;
	for(int i=0;i<Nn*Mn;i++){
		cin>>An[i];
		if(An[i]>An[0]) Cnt++;
	}
	Cn=ceil(Cnt*1.0/Nn);
	if(Cn%2==1){
		if(Cnt%Nn==0) Rn=Nn;
		else Rn=Cnt%Nn;
	}
	else{
		if(Cnt%Nn==0) Rn=1;
		else Rn=Nn-Cnt%Nn+1;
	}
	cout<<Cn<<" "<<Rn;
	return 0;
}
