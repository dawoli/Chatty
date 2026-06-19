#include<bits/stdc++.h>
using namespace std;
long long k,a[500005],b;
int n,sum=0,mx=0,l=1;
int dfs(int s,int c){
	for(int i=s;i<=n;i++){
		c^=a[i];
		if(c==k){
			l++;
			dfs(i+1,0);
			l--;
			sum++;
			if(l==1){
				mx=max(mx,sum);
				sum=0;
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b=0;
	dfs(1,b);
	cout<<mx;
	return 0;
}

