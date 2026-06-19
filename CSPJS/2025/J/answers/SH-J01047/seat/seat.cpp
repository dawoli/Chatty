#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N=1e6+10;

int a[N];

int cmp(int x,int y){
	return x>y;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	int nowx=1,nowy=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			cout<<nowx<<" "<<nowy<<endl;
			return 0;
		}
		if(nowy==m){
			nowx++;
			nowy=1;
		}
		else{
			nowy++;
		}
	}
}
