#include<bits/stdc++.h>
using namespace std;
long long a[]={6,2,5,5,4,5,6,3,7,6},t,n,myans=20241026;
#define maxsize long(1e5+5)
long long store[maxsize];
long long dfs(long long re) {
	if(store[re]) return store[re];
	for(long long i=1;i<=pow(10,re/2+1);i++) {
		long long j=i,s=0;
		if(!store[i]) {
			while(j) {
				s+=a[j%10];
				j/=10;
			}
			store[i]=s;
		}
		if(store[i]==re) return i;
		//cout<<"INVALID: "<<i<<" takes "<<s<<endl; 
	}
	return -1;
}
int main() {
	freopen("sticks.in","r",stdin); 
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	for(long long i=0;i<t;i++) {
		cin>>n;
		cout<<dfs(n)<<endl;
	}
}
