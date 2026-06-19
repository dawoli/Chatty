#include<bits/stdc++.h>
using namespace std;
float start[100010],end[100010],k[100010],e[100010],k2[100010];
float n,m,L,V,T,cnt,t,cmt,cntt,u;
int f;
float d[1000010],v[1010],a[1010],p[1000010];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int g=1;g<=T;g++){
		for(int i=0;i<100010;i++){
			start[i]=0;
			end[i]=0;
			k[i]=0;
			p[i]=0;
			d[i]=0;
			e[i]=0;
			k2[i]=0;
		}
		for(int i=0;i<1010;i++){
			v[i]=0;
			a[i]=0;
		}
		cnt=0;
		cntt=0;
		t=0;
		u=0;
		cmt=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(v[i]>V){
					start[i]=d[i];
					end[i]=L;
				}
				else{
					start[i]=end[i]=-1;
				}
			}
			if(a[i]>0){
				if((v[i]*v[i])+2*a[i]*(L-d[i])<=V*V){
					start[i]=end[i]=-1;
				}
				else{
					if(v[i]>V){
						start[i]=d[i];
						end[i]=L;
					}
					if(v[i]==V){
						start[i]=d[i]+0.000001;
						end[i]=L;
					}
					if(v[i]<V){
						t=(V-v[i])/a[i];
						start[i]=d[i]+v[i]*t+a[i]*t*t/2+0.000001;
						if(start[i]<=L){
							end[i]=L;
						}
						else{
							start[i]=end[i]=-1;	
						}
					}
				}
			}
			if(a[i]<0){
				if(v[i]<=V){
					start[i]=end[i]=-1;
				}
				else{
					start[i]=d[i];
					t=(V-v[i])/a[i];
					end[i]=d[i]+v[i]*t+a[i]*t*t/2;
				}
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(p[i]>=start[j]&&p[i]<=end[j]){
					k[j]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(k[i]>0){
				cnt++;
			}
		}
		cout<<cnt<<" ";
		while(cntt<cnt){
			cmt=cmt+1;
			for(int i=1;i<=m;i++){
				for(int j=1;j<=n;j++){
					if(p[i]>=start[j]&&p[i]<=end[j]){
						e[i]++;
					}
				}
			}
			for(int i=1;i<=m;i++){
				if(e[i]>e[f]){
					f=i;	
				}
			}
			cntt=cntt+e[f];
			for(int j=1;j<=n;j++){
				if(p[f]>=start[j]&&p[f]<=end[j]){
					start[j]=-1;
					end[j]=-1;
				}
			}
			for(int i=1;i<=m;i++){
				e[i]=0;
			}
			f=0;
		}
		cmt=m-cmt;
		cout<<cmt<<endl;
	}
	return 0;
}
