#include<bits/stdc++.h>
using namespace std;
int x[5010];
long long w;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b=0,k=0,maxn=INT_MIN;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>x[i];
		if(x[i]==1){
			b++;
		}
	}
	if(b==a){
		for(int i=3;i<=a;i++){
			w+=a-i+1;
			if(w>998244353){
				w%=998244353; 
			}
		}
	}
	else{
		for(int i=1;i<=a;i++){
			maxn=max(maxn,x[i]);
			k+=x[i];
		}
		if(k>maxn*2){
			w++;
		}
	}
	cout<<w;
	return 0;
} 
