#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=225;
int n,m;
pair<int,int> a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1,a+n*m+1,greater<pair<int,int>>());
	for(int i=1;i<=n*m;i++){
		if(a[i].second==1){
			int y=(i+n-1)/n;
			if(y%2)cout<<y<<' '<<i-(y-1)*n<<'\n';
			else cout<<y<<' '<<y*n-i+1<<'\n';
			return 0;
		}
	}
	return 0; 
}
