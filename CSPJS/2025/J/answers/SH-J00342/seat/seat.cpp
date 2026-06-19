#include<bits/stdc++.h>
using namespace std;
int n,m;
struct info{
	int a,id;
}f[10009];
bool cmp(info x,info y){
	return x.a>y.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>f[i].a;
		f[i].id=i;
	}
	sort(f+1,f+n*m+1,cmp);
	int tmp=0;
	for(int i=1;i<=n*m;i++)
		if(f[i].id==1)
			tmp=i;
	int lie=(tmp+n-1)/n;
	if(lie%2==1){
		int cnt=tmp%n;
		if(cnt==0) cnt=n;
		cout<<lie<<" "<<cnt<<endl;
	}else{
		int cnt=tmp%n;
		if(cnt==0) cnt=n;
		cout<<lie<<" "<<n+1-cnt<<endl;
	}
	return 0;
}
