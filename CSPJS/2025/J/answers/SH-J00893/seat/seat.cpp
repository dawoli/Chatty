#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e3+10;
int a[N];
int ex;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
			cin>>a[i];
	}
	ex=a[1];
	sort(a+1,a+1+n*m,greater<>());
//	for(int i=1;i<=n*m;i++) cout<<a[i];
	int i=1,j=1,cnt=1;
	while(i<=n&&j<=m){
//		cout<<j<<" "<<i<<"\n";
		if(a[cnt]==ex){
			cout<<j<<" "<<i<<"\n";
			return 0;
		}
		if(i<n&&j%2==1) i++;
		else if(i>1&&j%2==0) i--;
		else j++;
		cnt++;
	}
	cout<<i<<" "<<j<<"\n";
	return 0;
}
