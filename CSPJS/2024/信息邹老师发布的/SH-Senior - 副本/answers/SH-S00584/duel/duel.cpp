#include<bits/stdc++.h>
using namespace std;
long long n,a[101010],cnt=0;
long long p=1,q=2;
int main(){
	
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	while(q<=n){
		if(a[q]>a[p]) cnt++,p++;
		q++; 
	} 
	cout<<n-cnt<<endl; 
	
	return 0;
} 
