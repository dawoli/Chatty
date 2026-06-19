#include<bits/stdc++.h>
using namespace std;
int n,m,a1[10001],a[10001],T;
int b[1001];
int tmp[10001];
int X[5];
struct cc{
	int num,x,ans=0;
};
cc c[10001];
bool cmp(cc a,cc b){
	return a.x<b.x;
}
int gettt(int q,int nu){
	int x=1;
	int y=1;
	for(int i=1;i<=q;i++){
		x*=10;y*=10;
	}
	return nu%x/(y/10);
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a1[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i].x;
		c[i].num=i;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	cin>>T;
	sort(c+1,c+1+m,cmp);
	while(T--){
		for(int i=0;i<=3;i++){
			cin>>X[i];
		}
		for(int i=1;i<=n;i++){
			a[i]=-1;
		}
		int d;
		int K;
		int noww=n;
		int cn=1;
		for(int i=1;i<=n;i++){
			noww=i;
			cn=1;
			a[i]=a1[i]^X[i%4];
			K=n;
			for(int j=1;j<=K;j++){
				for(int k=K;k>=1;k--){
					d=gettt(k,a[j]);
					if(d){
						for(int qq=2;qq<=noww;qq+=2){
							if(a[qq]>=j){
								tmp[cn]=qq;
								cn++;
							}
						}
					}else{
						for(int qq=1;qq<=noww;qq+=2){
							if(a[qq]>=j){
								tmp[cn]=qq;
								cn++;
							}
						}
					}
				}
				for(int qq=1;qq<=sizeof(tmp)/4;qq++){
					c[i].ans+=tmp[qq];
				} 
			}
		}
		int ans=c[1].num*c[1].x;
		for(int i=2;i<=n;i++){
			ans^=c[i].num*c[i].x;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
