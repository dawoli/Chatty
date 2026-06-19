#include<bits/stdc++.h>
using namespace std;
struct p{
	float l,r;
	int y;
}car[3003];
bool cmp(p a,p b){
	return a.l<b.l;
}
int n,m,L,V;
int T,sb[105],xuan[105],t[105],ans=1000;
float d,v,a;
int pd(int c,int dsb){
	if(c==m+1){
		int flag=1;
		for (int k=1;k<=n;k++){
			if (!(t[k]>=1 || car[k].y==0)){
				flag=0;
			}
		}
		if (flag==1){
			ans=min(ans,dsb);
		}
		return 1;
	}
	xuan[c]=0;
	pd(c+1,dsb);
	xuan[c]=1;
	for (int k=1;k<=n;k++){
		if (car[k].l<=sb[c] && sb[c]<=car[k].r)t[k]+=1;
	}
	pd(c+1,dsb+1); 
	for (int k=1;k<=n;k++){
		if (car[k].l<=sb[c] && sb[c]<=car[k].r)t[k]-=1;
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	memset(car,0,sizeof(car));
	cin>>T;
	for (int i=1;i<=T;i++){
		cin>>n>>m>>L>>V;
		int sbflag=1;
		for (int j=1;j<=n;j++){
			cin>>d>>v>>a;
			if (a<0){
				sbflag=0;
			}
			if (a==0){
				if (v>V){
					car[j].l=d;
					car[j].r=L;
				}
			}
			if (a>0){
				if (v>V){
					car[j].l=d;
					car[j].r=L;
				}
				else{
					if (d+(V*V-v*v)/(2*a)<=L){
						car[j].l=d+ceil((V*V-v*v)/(2*a))+1;
						car[j].r=L;	
					}
				}
			}
			if (a<0){
				if (v>V){
					car[j].l=d;
					car[j].r=d+ceil((V*V-v*v)/(2*a))-1;	
					if (L<car[j].r)car[i].r=L;
				}
			}
		}
		for (int j=1;j<=m;j++){
			cin>>sb[j];
			for (int k=1;k<=n;k++){
				if (car[k].l<=sb[j] && sb[j]<=car[k].r){
					car[k].y=1;
				}
			}
		}
		int sbans=0;
		for (int k=1;k<=n;k++){
			if (car[k].y==1){
				sbans++;
			}
		}
		cout<<sbans<<' ';
		if (sbflag==1)cout<<1<<endl;
		else{
			memset(t,0,sizeof(t));
			pd(1,0);
			cout<<m-ans<<endl;
		}
	}
	return 0;
}
