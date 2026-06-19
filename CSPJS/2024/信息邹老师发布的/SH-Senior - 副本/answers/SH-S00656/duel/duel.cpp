#include<bits/stdc++.h>

using namespace std;

long c[100010];
long n;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(long i=0;i<n;++i){
		long tmp;
		cin>>tmp;
		c[tmp]++;
	}	
	long x=c[0];
	for(long i=0;i<100010;++i){
		if(c[i]>x)x=c[i];
	}
	
	cout<<x;
	
	return 0;
}
