#include<iostream>
#include<algorithm>
#define debug(x) (cerr<<#x<<':'<<(x)<<endl)
#define endl '\n'
using namespace std;
typedef long long ll;
int a[10005];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int R=a[1];
	sort(a+1,a+n*m+1,[](int a,int b) {return a>b;});
	int cnt=0;
	for(int i=1;i<=m;i++) {
		if(i%2==1) for(int j=1;j<=n;j++) 
			if(a[++cnt]==R) 
				cout<<i<<' '<<j<<endl;
		if(i%2==0) for(int j=n;j>=1;j--) 
			if(a[++cnt]==R) 
				cout<<i<<' '<<j<<endl;
	}
	return 0;
}


