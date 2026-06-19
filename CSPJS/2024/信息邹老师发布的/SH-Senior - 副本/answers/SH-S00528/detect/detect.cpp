#include<bits/stdc++.h>
using namespace std;
int t,n,m,len,lim,ans,can,d[100009],v[100009],a[100009],k[100009];
bool ta=1,tb=1,tc=1;
/*struct chao{
	int be,en;
};
chao w[100009];*/
int next(int qu){
	int l=0,r=m-1;
	while(l<r){
		int mid=(l+r)/2;
		if(qu>k[mid]){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
}
bool ifc(int nd,int nv,int na){
	if(na==0){
		return nv>lim;
	}
	if(na>0)
		return nv*nv+2*na*(k[m-1]-nd)>lim*lim;
	//return nv*nv+2*na*(next(nd)-nd)>lim*lim;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int no=0;no<t;no++){
		can=0;
		scanf("%d%d%d%d",&n,&m,&len,&lim);
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&d[i],&v[i],&a[i]);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
			if(a[i]!=0){
				ta=0;
			}
			else if(a[i]>0){
				tc=0;
			}
			else{
				tb=0;
			}
		}
		for(int i=0;i<m;i++){
			scanf("%d",&k[i]);
		}
		int mak=k[m-1];
		if(ta||tb){
			for(int i=0;i<n;i++){
			if(ifc(d[i],v[i],a[i])&&d[i]<=mak){
				can++;
			}
		}		
		printf("%d ",can);
			if(can!=0)
			printf("%d\n",m);
			else{
				printf("0\n");
			}
		}
		//else if(m<=20&&n<=20){
			//solveBF();
		//}
	}
	return 0;
}
//-libgcc
//HF#24THMC
