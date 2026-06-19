#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int a,b,c,mx;
	int x,y;
};
node a[100005];
bool cmp(node a,node b){
	return a.mx>b.mx;
}
int x=0,y=0,z=0,ans=0;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		x=0,y=0,z=0,ans=0;
		priority_queue<int> vx,vy,vz;
		cin>>n;
		for(int i=0;i<n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a[i].a=x;
			a[i].b=y;
			a[i].c=z;
			a[i].mx=max(x,max(y,z));
			if(a[i].mx==x){
				a[i].x=1;
				if(y>z){
					a[i].y=y;
				}else{
					a[i].y=z;
				}
			}
			else if(a[i].mx==y){
				a[i].x=2;
				if(x>z){
					a[i].y=x;
				}
				else a[i].y=z;
			}
			else if(a[i].mx==z){
				a[i].x=3;
				if(x>y) a[i].y=x;
				else a[i].y=y;
			}
		}
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++){
			ans+=a[i].mx;
			if(a[i].mx==a[i].a&&a[i].mx==a[i].b){
				if(x>y){
					y++;
					vy.push(0);
				}else{
					x++;
					vx.push(0);
				}
			}
			else if(a[i].mx==a[i].a&&a[i].mx==a[i].c){
				if(x>z){
					z++;
					vz.push(0);
				}else{
					x++;
					vx.push(0);
				}
			}
			else if(a[i].mx==a[i].c&&a[i].mx==a[i].b){
				if(z>y){
					y++;
					vy.push(0);
				}else{
					z++;
					vz.push(0);
				}
			}
			else if(a[i].mx==a[i].a){
				x++;
				vx.push(-a[i].mx+a[i].y);
			}
			else if(a[i].mx==a[i].b){
				y++;
				vy.push(-a[i].mx+a[i].y);
			}
			else if(a[i].mx==a[i].c){
				z++;
				vz.push(-a[i].mx+a[i].y);
			}
		}
		if(x>n/2){
			for(int i=0;i<x-n/2;i++){
				ans+=vx.top();
				vx.pop();
			}
		}
		if(y>n/2){
			for(int i=0;i<y-n/2;i++){
				ans+=vy.top();
				vy.pop();
			}
		}
		if(z>n/2){
			for(int i=0;i<z-n/2;i++){
				ans+=vz.top();
				vz.pop();
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
