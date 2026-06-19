#include<bits/stdc++.h>
using namespace std;
int s[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a,cnt=0,last=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		s[i]=s[i-1]^a;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i-last;j++){
			if((s[i]^s[i-j])==k){
				last=i;
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}

