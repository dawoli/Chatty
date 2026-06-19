#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int numbern,mumberm,zuowei;
	cin>>numbern>>mumberm;
	int aumberm[numbern*mumberm];
	for(int immn=0;immn<numbern*mumberm;immn++){
		cin>>aumberm[immn];
	}
	int fumberm=aumberm[0];
	sort(aumberm,aumberm+numbern*mumberm);
	for(int immn=0;immn<numbern*mumberm;immn++){
		if(aumberm[immn]==fumberm){
			zuowei=immn+1;
			break;
		}
	}
	
	zuowei=numbern*mumberm-zuowei+1;

	fumberm=0;
	while(zuowei>=numbern){
		zuowei=zuowei-numbern;
		fumberm++;
	} 
	if(zuowei==0&&fumberm%2==0){
		cout<<fumberm<<" "<<0;
		return 0;
	}
	else if(zuowei==0&&fumberm%2!=0){
		cout<<fumberm<<" "<<numbern;
		return 0;
	}
	else if(zuowei!=0&&fumberm%2==0){
		cout<<fumberm+1<<" "<<zuowei;
		return 0;
	}
	else if(zuowei!=0&&fumberm%2!=0){
		cout<<fumberm+1<<" "<<numbern-zuowei+1;
		return 0;
	}
	return 0; 
}

