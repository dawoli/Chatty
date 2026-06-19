#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=107;
ll a[N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i = 1;i <= n*m;i++){
        cin>>a[i];
    }
    ll k=a[1];
    sort(a+1,a+n*m+1);
    ll id=lower_bound(a+1,a+n*m+1,k)-a;
    id=n*m+1-id;
    ll col=(id-1)/n+1;
    ll row=(id-1)%n+1;
    if(col%2==0)row=n+1-row;
    cout<<col<<" "<<row;
    return 0;
}
