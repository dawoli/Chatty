#include<bits/stdc++.h>
using namespace std;
int n,k,a[500114],s[500114],d[500114],res;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int len=1;len<=n;len++){
		for(int l=1;l<=n-len+1;l++){
			if(d[l] || d[l+len-1])continue;
			bool f=0;
			for(int i=l;i<=l+len-1;i++)if(d[i]){f=1;break;}
			if(f){d[l]=1;continue;} 
			int b;
			if(l!=1)b=s[l+len-1]^s[l-1];
			else b=s[l];
			if(b==k){
				res++;
				for(int i=l;i<=l+len-1;i++)d[i]=1;
			}
		}
	} 
	cout<<res;
} 
