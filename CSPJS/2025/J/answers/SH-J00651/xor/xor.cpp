#include<bits/stdc++.h>
using namespace std;
int n,k,a[500000],cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
		    int oxrxrorxorxorxorxoro=0;
			for(int k=i;k<=j;k++) oxrxrorxorxorxorxoro^=a[k];
			if(oxrxrorxorxorxorxoro==k){
				cnt++;
				i++;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
