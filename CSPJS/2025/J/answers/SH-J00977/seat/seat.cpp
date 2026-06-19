#include<bits/stdc++.h>
using namespace std;
int n,m,a[509];
int x,cnt,b[509];

bool cmp(int x,int y){
	if(x>y) return true;
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;cin>>x;
	a[1]=x;
	for(int i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			cnt=i;
			break;
		}
	}
//	cout<<cnt<<"\n";
	b[0]=1;
	for(int i=1;i<=n;i++){
		b[i]=i;
	}
	for(int i=n+1;i<2*n;i++){
		b[i]=2*n-i+1;
	}
	cout<<ceil(cnt*1.0/n);
	cout<<" "<<b[cnt%(2*n)];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
