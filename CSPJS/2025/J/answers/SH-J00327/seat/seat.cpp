#include<bits/stdc++.h>
using namespace std;
bool cmp(int &a, int &b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int r;
	int a[101];
	cin>>n>>m>>r;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m,cmp);
	a[0]=-1;
	for(int i=1;i<n*m;i++){
		if(r>a[i]){
			a[i]=r;
			break;
		}
	}
	int cnt=1;
	int j=1;
	for(int cnt=1;cnt<n*m;){
		for(int i=1;i<=n;i++){
			if(a[cnt]==r){
				cout<<j<<" "<<i;
				return 0;
			}
			cnt++;
		}
		j++;
		for(int i=n;i>=1;i--){
			if(a[cnt]==r){
				cout<<j<<" "<<i;
				return 0;
			}
			cnt++;
		}
		j++;
	}
	cout<<n<<" "<<m;
	return 0;
}
