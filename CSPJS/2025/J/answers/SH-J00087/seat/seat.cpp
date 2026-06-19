#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
struct stu{
	int s,id;
}a[105];
bool cmp(stu a,stu b){
	return a.s>b.s;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;j+=2){
			if(a[i+n*(j-1)].id==1){
				c=j,r=i;
				break;
			}
		}
	for(int i=1;i<=n;++i)
		for(int j=2;j<=m;j+=2){
			if(a[n*j-i+1].id==1){
				c=j,r=i;
				break;
			}
		}
	cout<<c<<" "<<r<<"\n";
	return 0;
}
