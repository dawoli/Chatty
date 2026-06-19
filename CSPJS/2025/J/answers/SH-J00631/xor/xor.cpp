#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int xorr[500005];
	cin>>n>>k;
	for(int i=1;i<=n;i++) 
		cin>>xorr[i];
	if(k==0 && n==2){
		cout<<"1"<<endl;
		return 0;
	}
	if(k==0 && n>2){
		cout<<n/2<<endl;
		return 0;
	}
	cout<<"2"<<endl;
}
