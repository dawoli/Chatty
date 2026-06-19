#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
const int N=1e3;
int n,m;
struct str{
	int num;
	int ans;
};
str a[N];
bool cmp(str x,str y){
	return x.ans>y.ans;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].ans;
		a[i].num=i;
	}
	int x;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1) x=i;
	}
	if(x%n==0)cout<<x/n<<' ';
	else cout<<x/n+1<<' ';
	if((x/n)%2==1){
		if(x%n==0)cout<<n;
		else cout<<n-x%n+1;
	}
	else{
		if(x%n==0)cout<<n;
		else cout<<x%n;
	}
	return 0;
}
