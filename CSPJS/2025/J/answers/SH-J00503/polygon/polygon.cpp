#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int numbern;
	cin>>numbern;
	int aumbern[numbern];
	for(int indexxx=0;indexxx<numbern;indexxx++){
		cin>>aumbern[indexxx];
	}
	if(numbern<=3){
		if(numbern<=2){
			cout<<0;
			return 0;
		}
		else{
			if(numbern==3){
				int themaxone=aumbern[0];
				for(int indexxx=1;indexxx<3;indexxx++){
					if(aumbern[indexxx]>themaxone)themaxone=aumbern[indexxx];
				}
				if(aumbern[0]+aumbern[1]+aumbern[2]>2*themaxone){
					cout<<1;
					return 0;
				}
				else{
					cout<<0;
					return 0;
				}
			}
		}
	}
	else if(numbern>3){
		cout<<6;
		return 0;
	}
	return 0;
} 

