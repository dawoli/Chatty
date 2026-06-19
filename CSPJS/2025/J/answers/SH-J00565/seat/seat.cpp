#include<bits/stdc++.h>
using namespace std;
const int N=1009;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int nuu=n*m;
	for(int i=1;i<=nuu;i++)
		cin>>a[i];
	int p=a[1];
	sort(a+1,a+nuu+1);
	int cnt=0;
	for(int i=1;i<=nuu;i++){
		if(a[i]==p){
			cnt=nuu-i+1;
			break;
		}
	}
	int x=(cnt-1)/n+1;
	int y=0;
	if(x%2==1){
		y=cnt-(x-1)*n;
	}
	else{
		y=n+1-(cnt-(x-1)*n);
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}
