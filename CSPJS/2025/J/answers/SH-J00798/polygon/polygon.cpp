#include<bits/stdc++.h>
using namespace std;
int n,i,a,maax;
long long cnt,num;
long long  nnn(long long a){
	if(a==1) return 1;
	return a*nnn(a-1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1,maax=0;i<=n;i++){
		cin>>a;
		num+=a;
		maax=max(maax,a);
		if(i>=3){
			if(n==i) cnt+=1;
			else cnt+=(nnn(n)/nnn(i)/nnn(n-i));
		}
	}
	if(num<=2*maax){
		cout<<0;
	}
	else{
		cout<<cnt;
	}
	return 0;
}
