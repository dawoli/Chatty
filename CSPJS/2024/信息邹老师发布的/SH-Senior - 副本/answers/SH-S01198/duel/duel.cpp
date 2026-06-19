#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long r[N],cnt=0,c[N],tu,n,rest,mx=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>tu;
		c[tu]++;
	}
	if(c[2]-c[1]<0){
		cout<<c[2]+c[1]-c[2];
	}
	else if(c[2]-c[1]>=0){
		cout<<c[2];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;//25pts plz
} 
