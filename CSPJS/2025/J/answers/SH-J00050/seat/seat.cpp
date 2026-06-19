#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=101;

int n,m;
int a[N];

bool cmp(int a,int b){
	return a>b;
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k;
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			k=i;
			break;
		}
	}
	int ansx=(k+m-1)/m;
	cout<<ansx<<" ";
	if(ansx%2==1){
		cout<<k-(ansx-1)*m;
	}
	else{
		cout<<m-(k-(ansx-1)*m)+1;
	}
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	solve();
	
	return 0;
}

