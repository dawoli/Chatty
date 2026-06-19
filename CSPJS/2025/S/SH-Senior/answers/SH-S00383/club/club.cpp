#include<bits/stdc++.h>
using namespace std;
int t,n,x,y,z,mi,r;
int c1=0,c2=0,c3=0;
int ans=0;
int p[100010][3];
int p1,p2,p3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		ans=0;
		c1=0;c2=0;c3=0;
		p1=0;p2=0;p3=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>x>>y>>z;
			if(x>y&&x>z){
				if(y>z){
					p1++;
					p[p1][1]=x-y;
				}else{
					p1++;
					p[p1][1]=x-z;
				}
				if(c1+1<=n/2){
					c1++;
					ans+=x;
				}else{
					mi=200000;
					for(int k=1;k<=p1;k++){
						if(p[k][1]<mi)r=k;
						mi=min(mi,p[k][1]);
					}
					p[r][1]=200001;
					ans=ans-mi+x;
				}
			}else if(y>x&&y>z){
				if(x>z){
					p2++;
					p[p2][2]=y-x;
				}else{
					p2++;
					p[p2][2]=y-z;
				}
				if(c2+1<=n/2){
					c2++;
					ans+=y;
				}else{
					mi=200000;
					for(int k=1;k<=p2;k++){
						if(p[k][2]<mi)r=k;
						mi=min(mi,p[k][2]);
					}
					p[r][2]=200001;
					ans=ans-mi+y;
				}
			}else{
				if(x>y){
					p3++;
					p[p3][3]=z-x;
				}else{
					p3++;
					p[p3][3]=z-y;
				}
				if(c3+1<=n/2){
					c3++;
					ans+=z;
				}else{
					mi=20000;
					for(int k=1;k<=p3;k++){
						if(p[k][3]<mi)r=k;
						mi=min(mi,p[k][3]);
					}
					p[r][3]=200001;
					ans=ans-mi+z;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
