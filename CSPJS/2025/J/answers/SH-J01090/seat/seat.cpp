#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e2+5;
int n,m;
int score;
int a[MAXN];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>score;
	for(int i=1;i<n*m;i++) cin>>a[i];
	sort(a+1,a+n*m,cmp);
	int index;
	for(index=1;index<n*m;index++){
		if(a[index]>score) continue;
		break;
	}
	int c,r;
	c=(index+n-1)/n;
	r=index%n;
	if(r==0) r=n;
	if(!(c%2)) r=n+1-r;
	cout<<c<<' '<<r<<endl;
	return 0;
}
