#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;
int a[N],pre[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,x,cnt=0,use=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]^a[i];
	for(int i=1;i<=n;i++){
		for(int j=use;j<i;j++){
			x=pre[i]^pre[j];
			if(x==k){
				cnt++;
				use=i;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
