#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll s[10010];
ll a[110][110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>s[i];
	}
	ll special=s[1];
	sort(s+1,s+n*m+1);
	ll i=1,j=1,d=n*m;
	while(d>=1){
		a[i][j]=s[d];
		d--;
		if(j%2==1){
			i++;
			if(i>n){
				i--;
				j++;
			}
		}
		else if(j%2==0){
			i--;
			if(i<1){
				i++;
				j++;
			}
		}
	}
	for(ll q=1;q<=n;q++){
		for(ll e=1;e<=m;e++){
			if(a[q][e]==special){
				cout<<e<<" "<<q;
				return 0;
			}
		}
	}
	return 0;
}
