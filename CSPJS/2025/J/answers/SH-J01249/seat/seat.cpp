#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+1+n*m);
	int cnt=0;
	for (int i=n*m;i>=1;i--){
		cnt++;
		if (a[i]==t){
			break;
		}
	}
	int tmp=cnt%n;
	int x,y;
	if (tmp==0){
		x=cnt/n;
	}
	else{
		x=cnt/n+1;
	}
	if (tmp==0){
		if (x%2==1){
			y=n;
		}
		else{
			y=1;
		}
	}
	else{
		if (x%2==1){
			y=tmp;
		}
		else{
			y=n-tmp+1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
