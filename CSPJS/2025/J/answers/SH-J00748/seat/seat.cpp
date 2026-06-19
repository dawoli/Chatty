#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
bool cmp(ll a,ll b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n*m;i++){
        cin>>a[i];
    }
    ll t=a[1],pos=0;
    sort(a+1,a+n*m+1,cmp);
    for(ll i=1;i<=n*m;i++){
        if(a[i]==t){
            pos=i;
            break;
        }
    }
    ll r=(pos-1)/n+1;
    cout<<(pos-1)/n+1<<" ";
    if(r%2==1){
        cout<<pos-(r-1)*n<<endl;
    }else{
        cout<<n-(pos-(r-1)*n)+1<<endl;
    }
}