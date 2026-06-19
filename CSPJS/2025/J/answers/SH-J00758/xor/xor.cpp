#include<bits/stdc++.h>
using namespace std;
#define N 500005
int n,k,cnt;
long long sum,num[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			sum=sum^num[r];
			if(sum==k){
				l=r;
				++cnt;
				break;
			}
		}
		sum=0;
	}
	cout<<ans;
	return 0;
}
