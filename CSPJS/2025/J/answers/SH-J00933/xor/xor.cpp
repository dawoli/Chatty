#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define el <<"\n"
#define log(x) cout<<#x<<": "<<x el
using namespace std;
typedef long long ll;
int n,k;
int A[500005],B[500005];
bool f[1<<21];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	rep(i,1,n){
		cin>>A[i];
	}
	for(int i=n;i;i--){
		B[i]=B[i+1]^A[i];
	}
	int x=1,ans=0;
	rep(i,1,n){
		f[B[i]]=true;
		if(f[B[i+1]^k]){
			ans++;
			rep(j,x,i){
				f[B[j]]=false;
			}
			x=i+1;
		}
	}
	cout<<ans;
	return 0;
}
