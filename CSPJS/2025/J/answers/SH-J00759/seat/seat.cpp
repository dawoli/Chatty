#include<bits/stdc++.h>
using namespace std;
struct stu{
	int x,y,i,n;
	bool b;
};
bool q(stu a,stu b){
	return a.n>b.n;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	stu a[200];
	int n,m,ansx,ansy;
	cin>>n>>m;
	int ai=n*m;
	a[0].b=1;
	cin>>a[0].n;
	for(int i=1;i<ai;i++){
		cin>>a[i].n;
		a[i].b=0;
	}
	sort(a,a+ai,q);
	int ax=1,ay=1,bx,by,ni=1;
	if(a[0].b==1){
		cout<<1<<' '<<1;
		return 0;
	}			
	for(int i=0;i<ai;i++){
		int o=ax%2;
		if(ay==1){
			if(o){
				bx=ax;
				by=ay+1;
			}else{
				bx=ax+1;
				by=ay;
			}
		}else if(ay==n){
			if(o){
				bx=ax+1;
				by=ay;
			}else{
				bx=ax;
				by=ay-1;
			}			
		}else{
			if(o){
				bx=ax;
				by=ay+1;
			}else{
				bx=ax;
				by=ay-1;
			}			
		}
		
		if(a[ni].b){
			cout<<bx<<' '<<by;
			break;
		}
		ax=bx;
		ay=by;
		ni++;
	}
	return 0;
}
