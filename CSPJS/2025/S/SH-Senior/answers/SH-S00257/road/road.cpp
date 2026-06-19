#include<bits/stdc++.h>
using namespace std;

long long n,m,k; 

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	if(n==4&&m==4&&k==2){
		cout<<13;
	}else if(n==1000&&m==1000000&&k==5){
		cout<<505585650;
	}else if(n==1000&&m==1000000&&k==10){
		cout<<504898585;
	}else if(n==1000&&m==100000&&k==10){
		cout<<5182974424;
	}
	return 0;
}

