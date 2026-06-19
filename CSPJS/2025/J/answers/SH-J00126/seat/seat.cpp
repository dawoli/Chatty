#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,now;
int a[1010];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cnt=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt){
			now=i;
			break;
		}
	}
	int nx=((now-1)/n)+1,ny=0;
	now-=(nx-1)*n;
	if(nx%2==0){
		ny=n-now+1;
	}
	else ny=now;
	cout<<nx<<" "<<ny;
	
	return 0;
}
