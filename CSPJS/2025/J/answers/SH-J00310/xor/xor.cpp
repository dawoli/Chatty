#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int  Nn,Kn,Cnt=0;
	cin>>Nn>>Kn;
	int An[Nn];
	for(int i=0;i<Nn;i++){
		cin>>An[i];
		if(An[i]==1) Cnt++;
	}
	if(Kn==0){
	    Cnt=0;
		for(int i=0;i<Nn-1;i++){
			if(An[i]==0||(An[i]==1&&An[i+1]==1)) Cnt++;
			if(An[i]==1&&An[i+1]==1) i++;  
		}
		if(An[Nn-1]==0) Cnt++;
	}
    cout<<Cnt;
	return 0;
}

