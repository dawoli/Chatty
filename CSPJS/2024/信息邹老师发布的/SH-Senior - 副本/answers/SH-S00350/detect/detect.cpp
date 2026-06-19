#include<bits/stdc++.h>
#define long long ll;
using namespace std;
int T,n,m,L,gs,V,d[1000009],a[1000009],v[1000009],wz;
int r,l,mid[1000009],p[1000009];//mid为最近的摄像头 
int v1[1000009],cnt,mz[1000009];//瞬时速度 ,超速车辆，超速车辆名字 
struct node{
	int sw;
	int mw;
};
node qj[1000009],z;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>m>>L>>V;
		int ans=m;
		for(int j=1;j<=n;j++)
			cin>>d[j]>>v[j]>>a[j];
		for(int j=1;j<=m;j++)
			cin>>p[j];
		for(int j=1;j<=n;j++){//二分找距离最近摄像头是第几个 
			l=1,r=m;
			mid[j]=(r+l)/2;
			while(l<mid[j]){
				if(d[j]<p[mid[j]]) r=mid[j];
				else l=mid[j];
				mid[j]=(r+l)/2;	
			}
			if(d[j]>p[mid[j]])
				mid[j]++;
		}
		int k=1;
		for(int j=1;j<=n;j++){ //超速车辆计算 
			v1[j]=sqrt(v[j]*v[j]+2*a[j]*(p[mid[j]]-d[j]));
			if(v1[j]*v1[j]+2*a[j]*(p[wz]-d[r])<=0 && a[j]<=0)
				continue; 
			if(v1[j]>V ){
			 	cnt++;mz[k]=j;k++;
			 }
			else{
				l=mid[j],r=m;
				wz=(r+l)/2;
				while(l<wz){
					if(v[j]*v[j]+2*a[j]*(p[wz]-d[r])<=0 && a[j]<=0)
						continue; 
					if(sqrt(v[j]*v[j]+2*a[j]*(p[wz]-d[r]))<=V) {
						l=wz;
					}
					else{
						mz[k]=j;k++;
						cnt++;break;					
					} 
					wz=(r+l)/2;	
			 }
			}
			if(sqrt(v1[j]*v1[j]+2*a[j]*(p[wz]-d[r]))<V && wz==4){
				v1[j]=sqrt(v1[j]*v1[j]+2*a[j]*(p[wz]-d[r]));
				if(sqrt(v1[j]*v1[j]+2*a[j]*(p[wz]-d[r]))>V)
					cnt++;	
			}
		}
		cout<<cnt<<" "; 
		sort(mz+1,mz+cnt+1);
		k=1;
		for(int j=1;j<=n;j++){ 
		v1[j]=sqrt(v[j]*v[j]+2*a[j]*(p[mid[j]]-d[j]));
			if(v1[j]>V){
				qj[k].sw=mid[j];
				if(a[j]>=0)
					qj[k].mw=m;
				k++;
				
			}
			else if(mz[k]==j) {
				for(int i1=mid[j]+1;i1<=m;i++){
				if(sqrt(v[j]*v[j]+2*a[j]*(p[i1]-d[j]))>V){
					qj[k].sw=i1;	
					if(a[j]>=0)
						qj[k].mw=m;
					break;
				}
			}
			k++;
			}
		}

		for(int j=1;j<=cnt;j++){
			if(qj[j].sw==qj[j].mw){
				gs++;
				continue;
			}
				
			int minn,maxx;
			if(minn>=qj[j].sw && maxx<=qj[j].mw){
				minn=qj[j].sw,maxx=qj[j].mw;
			}
			if(qj[j].sw>=minn && qj[j].mw<=maxx){
				gs++;
				continue;
			}
			if(qj[j].mw<minn){
				gs++;continue;
			}
				
			if(qj[j].sw>maxx){
				gs++;continue;
			}
		
		}
		cout<<m-gs;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
v1[j]=sqrt(v[j]*v[j]+2*a[j]*(p[mid[j]]-d[j]));
			if(v1[j]*v1[j]+2*a[j]*(p[wz]-d[r])<=0 && a[j]<=0)
				continue; 
			for(int jk=mid[j];jk<=m;jk++){
				if(mz[k]=j && sqrt(v1[j]*v1[j]+2*a[j]*(p[jk]-d[j]))>V){
					//cout<<v1[j];
					k++;
					qj[j].sw=jk;
				//	cout<<jk<<" ";
					if(a[j]>=0)
						qj[j].mw=m;
					continue;
				}
				else
					v1[j]=sqrt(v1[j]*v1[j]+2*a[j]*(p[jk]-d[j]));
					
			}
			v1[j]=sqrt(v[j]*v[j]+2*a[j]*(p[mid[j]]-d[j]));
			for(int jk=mid[j];jk<=m;jk++){
				if(mz[k]=j && sqrt(v1[j]*v1[j]+2*a[j]*(p[mid[jk]]-d[j]))<V && a<0){
					qj[j].mw=jk;
				}
				else
					v1[j]=sqrt(v1[j]*v1[j]+2*a[j]*(p[mid[jk]]-d[j]));
			}*/
