#include<bits/stdc++.h>
using namespace std;

long long n,f,m,k,a[1000],an,am;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>f;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>=f){
			k++;
		}
	}
	k++;
	an=am=1;
	while(k>2*n){
		am+=2;
		k-=2*n;
	}
	if(k>n){
		am++;
		k-=n;
		an=n-k+1;
	}else{
		an=k;
	}
	cout<<am<<" "<<an<<endl;
	return 0;
}
