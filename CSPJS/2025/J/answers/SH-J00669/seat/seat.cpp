#include<bits/stdc++.h>
using namespace std;
int n,m;
int num,s;
int a[10009];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			s=i;
			break;
		}
	}
	//cout<<s<<endl;
	int l=(s+n-1)/n,r=0;
	int cnt=s-n*(l-1);
	if(cnt==0) cnt=n;
	if(l%2==1) r=cnt;
	else r=n+1-cnt;
	cout<<l<<" "<<r<<"\n";
	return 0;
}
