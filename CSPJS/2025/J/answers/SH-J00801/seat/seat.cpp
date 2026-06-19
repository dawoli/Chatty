#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[105],ind;
map<ll,ll>mp;
bool cmp(ll a,ll b){
	return (a > b);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i = 1;i <= n * m;i++){
		cin>>a[i];
		mp[a[i]] = i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(ll i = 1;i <= n * m;i++){
		if(mp[a[i]] == 1){
			ind = i;
			break;
		}
	}
	ll line = ceil(ind * 1.0 / n);
	if(line % 2){
		cout<<line<<' '<<ind-(line-1)*n<<endl;
	}
	else{
		cout<<line<<' '<<n-(ind-(line-1)*n)+1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
