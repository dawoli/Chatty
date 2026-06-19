#include<bits/stdc++.h>
using namespace std;
int a[110],b[20][20];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int h1=a[1],u;
	sort(a+1,a+n*m+1,cmp);
	for(int i=n*m;i>=1;i--){
		if(a[i]==h1)u=i;
	}
	u=n*m+1-u;
	int h=u%n;
	if(h==0)h=n;
	int l=u/n+1;
	if(u%n==0)l--;
	if(l%2==0){
		h=n-h+1;
	}
	cout<<l<<" "<<h<<"\n";
	return 0;
} 
