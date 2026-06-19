#include<bits/stdc++.h>
using namespace std;
int n,m,R;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)	cin>>a[i];
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	int id;
	for(int i=1;i<=n*m;++i)
		if(a[i]==R)
			id=i;
	int xx=(id/(2*n))*2,yy=id%(2*n);
	if(yy==0)	yy=2*n,xx-=2;
	if(yy<=n)	cout<<xx+1<<" "<<yy<<endl;
	else		cout<<xx+2<<" "<<2*n-yy+1<<endl;
}
