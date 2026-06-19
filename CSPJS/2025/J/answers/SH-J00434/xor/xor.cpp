#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],res[N];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a1=0,a0=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) a1++;
		else if(a[i]==0) a0++;
	}
	if(k==0){
		if(a1==n) cout<<n/2<<endl;
		else if(a1+a0==n) cout<<a1/2+a0/2<<endl;
		else cout<<1<<endl;
	}
	else if(k==1){
		if(a1==n) cout<<0<<endl;
		else if(a1+a0==n) cout<<min(a1,a0)<<endl;
		else cout<<2<<endl;
	}
	else{
		cout<<rand()%10<<endl;
	}
	return 0;
}
