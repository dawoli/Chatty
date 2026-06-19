#include<bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			cout<<(i-1)/n+1<<" "<<(((i-1)/n+1)%2==1?((i-1)%m+1):(m-(i-1)%m));
			break;
		}
	}
	return 0;
}
