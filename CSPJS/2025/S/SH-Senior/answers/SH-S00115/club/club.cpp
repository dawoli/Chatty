#include<bits/stdc++.h>
using namespace std;
int n,t,m[5],xx,yy;
long long c;
struct B{
	int x1,x2,x3,l[5];
}b[100005];
bool cmp(B a,B b){
	if(a.x1==b.x1) return a.l[a.x1]-a.l[a.x2]>b.l[b.x1]-b.l[b.x2];
	return a.x1<b.x1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		c=0;
		m[1]=m[2]=m[3]=0;
		for(int i=1;i<=n;i++){
			cin >> b[i].l[1] >> b[i].l[2] >> b[i].l[3];
			xx=min(b[i].l[1],min(b[i].l[2],b[i].l[3])),yy=max(b[i].l[1],max(b[i].l[2],b[i].l[3]));
			if(xx==b[i].l[1]) b[i].x3=1;
			else if(xx==b[i].l[2]) b[i].x3=2;
			else b[i].x3=3;
			if(yy==b[i].l[1]&&b[i].x3!=1) b[i].x1=1; 
			else if(yy==b[i].l[2]&&b[i].x3!=2) b[i].x1=2; 
			else if(yy==b[i].l[3]&&b[i].x3!=3) b[i].x1=3;
			b[i].x2=6-b[i].x1-b[i].x3;
		}
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(m[b[i].x1]*2<n){
				m[b[i].x1]++;
				c+=b[i].l[b[i].x1];
			}else{
				m[b[i].x2]++;
				c+=b[i].l[b[i].x2];
			}
		}
		cout << c << '\n';
	}
	return 0;
}
//废了喵 这题竟然四点才写出来 
