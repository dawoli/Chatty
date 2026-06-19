#include<bits/stdc++.h>
using namespace std;
int ton[100006];
int zd=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int op;
	for(int k=1;k<=n;k++){
		cin>>op;
		ton[op]++;
	}
	for(int i=1;i<=100000;i++){
		if(ton[i]>zd) zd=ton[i];
	}
	cout<<zd<<"\n";
	return 0;
}
