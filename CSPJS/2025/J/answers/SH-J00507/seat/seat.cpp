#include<bits/stdc++.h>
using namespace std;
int n,m;
int sum;
int pos=0;
int h,w;
struct node{
	int id,s,v;
};
node a[105];

bool cmp(node x,node y){
	return x.v>y.v;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++) cin>>a[i].v;
	a[1].id=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=sum;i++){
		a[i].s=i;
		if(a[i].id==1){
			pos=i;
			break;
		}
	}
	if(pos%n==0) h=pos/n;
	else h=pos/n+1;
	w=pos%(2*n);
	if(w==0) w=1;
	else{
		if(w>n) w=n-(w-n)+1;
	}
	cout<<h<<" "<<w<<endl;
	return 0;
}
