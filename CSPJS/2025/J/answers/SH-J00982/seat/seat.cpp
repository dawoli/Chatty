#include<bits/stdc++.h>
using namespace std;
struct p{
	int score,num;
}a[105];
int n,m;
bool cmp(p x,p y){
	return x.score>y.score;
}
void seat(){
	int s=1,d=1,x=1,y=1;
	while(a[s-1].num!=1){
		if(x+d>n||x+d<1){
			y++;
			d=d*-1;
		}
		else{
			x+=d;
		}
		s++;
	}
	cout<<y<<' '<<x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i].score;
		a[i].num=i+1;
	}
	sort(a,a+n*m,cmp);
	seat();
}
