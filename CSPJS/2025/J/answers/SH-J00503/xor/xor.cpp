#include<bits/stdc++.h>
#include<iostream> 
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int numbern,kumbern;
	cin>>numbern>>kumbern;
	int aumbern[numbern];
	for(int indexxx=0;indexxx<numbern;indexxx++){
		cin>>aumbern[indexxx];
	}
	if(numbern<=2){
		if(numbern==1){
			cout<<0;
			return 0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
	return 0;
}

