#include<bits/stdc++.h>
using namespace std;
int n,k,a[500050],s[500050],r,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=r+1;j<=i;j++){
			s[i]^=s[j-1];
			if(s[i]==k){
				cnt++;
				r=i;
			//	cout<<s[i]<<' '<<j<<' '<<i<<'\n';
				s[i]^=s[j-1];
				break;
			}
			s[i]^=s[j-1];
		}
	}
	cout<<cnt;
	return 0;
} 
/*
len=1 1
len=2 
4 0
2 1 0 3
2 3 3 0

*/
