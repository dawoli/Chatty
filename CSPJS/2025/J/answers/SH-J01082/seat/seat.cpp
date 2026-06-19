#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=110;
int n,m,a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1],y;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			y=i;break;
		}
	}
	int l=(y-1)/n+1,h=(y-1)%n+1;
	if(l%2==0) h=n-h+1;
	cout<<l<<" "<<h<<"\n";
	return 0;
}

