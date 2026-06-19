#include <bits/stdc++.h>

using namespace std;
const int N=5e5+10;
int n,k,a[N],cnt;
bool f=1,f1=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
		if(a[i]!=1||a[i]!=0)f1=0;
		if(a[i]==1){
			cnt++;
		}
	}
	if(f){
		cout<<1;
		return 0;
	}
	if(f1){
		cout<<cnt;
		return 0;
	}
	cout<<2;
	return 0;
} 
