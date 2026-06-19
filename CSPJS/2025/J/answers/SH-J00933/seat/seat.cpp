#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define el <<"\n"
#define log(x) cout<<#x<<": "<<x el
using namespace std;
typedef long long ll;
int A[20][20];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int i=1,j=1,cnt=0;
	while(cnt<n*m){
		A[i][j]=++cnt;
		if(j%2){
			if(i==n)j++;
			else i++;
		}else{
			if(i==1)j++;
			else i--;
		}
	}
//	rep(i,1,n){
//		rep(j,1,m){
//			cout<<A[i][j]<<"\t";
//		}
//		cout el;
//	}
	int ans=1,x;
	cin>>x;
	rep(i,2,n*m){
		int y;
		cin>>y;
		if(y>x)ans++;
	}
	rep(i,1,n){
		rep(j,1,m){
			if(A[i][j]==ans){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	cout<<"ERR";
	return 0;
}
