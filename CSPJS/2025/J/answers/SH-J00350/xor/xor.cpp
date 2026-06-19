#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N];
bool b[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(b,1,sizeof b);
	ll n,k;
	cin>>n>>k;
	ll cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			b[i]=0;
			cnt++;
		}
	}
	ll s=0;
	for(int i=1;i<=n;i++){
		int w=i,s=0;
		for(int j=i;j<=n;j++){
			if(a[i]==k){
				continue;
			}
			if(b[j]){
				s^=a[j];
				if(s==k){
					cnt++;
					for(int k=w;k<=j;k++){
						b[j]=0;
					}
					s=0;
					w=j+1;
				}
			}
			else{
				s=0;
				w=j+1;
			}
		}
	}
	cout<<cnt;
	return 0;
}
