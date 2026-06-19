#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll k[1009];
bool cmp(const int a,const int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
			cin>>k[i];
	ll cnt=0;
	ll t=k[1];
	sort(k+1,k+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				cnt++;
				if(k[cnt]==t){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=1;j<=m;j++){
				cnt++;
				if(k[cnt]==t){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}

