#include <bits/stdc++.h>
using namespace std;
int n,m;
struct A{
	int v,id;
}a[110];
bool cmp(A x,A y){
	return x.v>y.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].v;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			cout<<(i-1)/m+1<<" ";
			if(((i-1)/m+1)%2==1) cout<<(i-1)%m+1<<endl;
			else cout<<n-(i-1)%m<<endl;
		}
	}
	return 0;
} 
