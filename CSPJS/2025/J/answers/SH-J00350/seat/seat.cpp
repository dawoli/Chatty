#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=20;
ll a[N*N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	ll s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
	ll w=a[1];
	ll cnt;
	sort(a+1,a+1+s,cmp);
	for(int i=1;i<=s;i++){
		if(a[i]==w){
			cnt=i;
			break;
		}
	}
	if(cnt%n==0){
		cout<<cnt/n<<" ";
		if(cnt/n%2==1){
			cout<<n;
		}
		else{
			cout<<"1";
		}
	}
	else{
		cout<<cnt/n+1<<" ";
		if((cnt/n+1)%2==1){
			cout<<cnt%n;
		}
		else{
			cout<<n-cnt%n+1;
		}
	}
	return 0;
}
