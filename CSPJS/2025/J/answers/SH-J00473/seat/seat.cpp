#include <bits/stdc++.h>

using namespace std;
int n,m,k=1,h1=1,l1=1,e=1,cnt;
struct node{
	int v,h,l;
};
node a[110];
bool cmp(node x,node y){
	return x.v>y.v;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].v;
	}
	cnt=a[1].v;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(i>k*n){
			k++;
			l1++;
			h1-=e; 
			e*=-1;
		}
		a[i].h=h1;
		a[i].l=l1;
		h1+=e;
		if(a[i].v==cnt){
			cout<<a[i].l<<" "<<a[i].h;
			break;
		}
	}
	return 0;
} 
