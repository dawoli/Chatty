#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],s[500010],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int r=1;
	for(int l=1;l<=n;r++){
		if((s[r]^s[l-1])==k){
			cnt++;
			l=r+1;
			r=l;
			
		}
		else if(r==n)
			l++,r=l;
	}
	cout<<cnt;
	return 0;
}
