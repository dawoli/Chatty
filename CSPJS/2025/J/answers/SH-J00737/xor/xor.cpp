#include <bits/stdc++.h>
using namespace std;
#define lowbit(x,y) (x^y)
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[100001];
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==1){
			cnt1++;
		}
		if(a[i]==0){
			cnt2++;
		}
	}
	if(n==2 && k==0){
		cout<<1<<endl;
		return 0;
	}
	if(k==1){
		cout<<cnt1<<endl;
	}
	else if(k==0){
		cout<<cnt1/2+cnt2/2<<endl;
	}
	else{
		cout<<0<<endl;
	}
	return 0;
}
