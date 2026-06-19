#include<bits/stdc++.h>
using namespace std;
int a[500009];
bool flaga=1,flagb=1;
int cntx=0,cnty=0,cntz=0,cntk=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	if(a[i]==k)
	cntk++;
	if(a[i]!=1)
	flaga=0;
	if(a[i]>1)
	flagb=0;
	if(a[i]==0)
	cntx++;
	else if(a[i]==1)
	cnty++;
}
	if(flaga&&k==0){
		cout<<n/2;
		return 0;
	}
	else if(flagb&&k<=1){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i-1]==1){
					cntz++;
					a[i]=0;
					a[i-1]=0;
				}
			}
			cout<<cntx+cntz;
		}
		else if(k==1){
			cout<<cnty;
		}
		return 0;
	}
	cout<<cntk;
	return 0;
}

