#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9,M=2e6+9;
int n,k,a[N],b[M],cnt=0,c[N],cnt2=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	b[0]=1;
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]^a[i];
		if(b[c[i]^k]==1){
			cnt++;
			for(int j=cnt2;j<=i-1;j++){
				b[c[j]]=0;
			}
			cnt2=i;
		}
		b[c[i]]=1;
	}
	cout<<cnt;
	return 0;
}
