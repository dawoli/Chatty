#include <bits/stdc++.h>
using namespace std;
int s[505000];
int cnt[505000];
int main(){
	freopen("xor4.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>s[i];
		cnt[i]=cnt[i-1]^s[i];	
	}
	if (k==0){
		int cnt1=0;
		for (int i=1;i<=n;i++){
			if (cnt[i]==0) cnt1++;
		}
		cout<<cnt1;
	}   
	else if (k==1){
		int cnt1=0;
		for (int i=1;i<=n;i++){
			if (s[i]==1) cnt1++;
		}
		cout<<cnt1;
	}
}
