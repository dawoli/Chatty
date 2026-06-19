#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1009;
const ll M=109;
ll n,m;
ll a[N];
ll mp[M][M];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int r1=a[1];
	sort(a+1,a+1+n*m,cmp);
	int s=1;
	for(int i=1;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				mp[j][i]=a[s];
				if(mp[j][i]==r1){
					cout<<i<<' '<<j;
					return 0;
				}
				s++;
			}
		}else{
			for(int j=n;j>=1;j--){
				mp[j][i]=a[s];
				if(mp[j][i]==r1){
					cout<<i<<' '<<j;
					return 0;
				}
				s++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
