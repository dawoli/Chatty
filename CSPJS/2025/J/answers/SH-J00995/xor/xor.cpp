#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	if(k==0){
		int cnta=0,cntb=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)cnta++;
			else if(a[i]==1&&a[i+1]==1)cntb++,i++;
		}
		cout<<cnta+cntb;
	}else if(k==1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)cnt++;
		}
		cout<<cnt;
	}
} 
