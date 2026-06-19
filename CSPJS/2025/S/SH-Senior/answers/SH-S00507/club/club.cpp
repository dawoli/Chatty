#include<bits/stdc++.h>
using namespace std;
int T,n,cna=0,cnb=0,cnc=0,ans=0;
int a[100005],b[100005],c[100005];
int na[100005],nb[100005],nc[100005];
int cha[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(na,0,sizeof(na));
		memset(nb,0,sizeof(nb));
		memset(nc,0,sizeof(nc));
		memset(cha,0,sizeof(a));
		scanf("%d",&n);
		cna=0;
		cnb=0;
		cnc=0;
		ans=0;
		for(int j=1;j<=n;j++){
			scanf("%d%d%d",&a[j],&b[j],&c[j]);
			ans+=max(a[j],max(b[j],c[j])); 
			if(max(a[j],max(b[j],c[j]))==a[j]){
				cna++;
				na[j]=a[j];
				cha[j]=a[j]-max(b[j],c[j]);
			}
			else if(max(a[j],max(b[j],c[j]))==b[j]){
				cnb++;
				nb[j]=b[j];
				cha[j]=b[j]-max(a[j],c[j]);
			}
			else if(max(a[j],max(b[j],c[j]))==c[j]){
				cnc++;
				nc[j]=c[j];
				cha[j]=c[j]-max(b[j],a[j]);
			}
		}
		//cout<<ans<<endl<<"a ";
		while(cna>(n/2)){
			int mi=30000,aim;
			for(int j=1;j<=n;j++){
				if(na[j]!=0 && cha[j]<mi){
					mi=cha[j];
					aim=j;
				} 
			} 
			ans-=cha[aim];
			//cout<<ans<<" ";
			na[aim]=0;
			cna--;
		}
		//cout<<endl<<"b ";
		while(cnb>(n/2)){
			int mi=30000,aim;
			for(int j=1;j<=n;j++){
				if(nb[j]!=0 && cha[j]<mi){
					mi=cha[j];
					aim=j;
				} 
			} 
			ans-=cha[aim];
			//cout<<aim<<" ";
			nb[aim]=0;
			cnb--;
		}
		//cout<<endl<<"c ";
		while(cnc>(n/2)){
			int mi=30000,aim;
			for(int j=1;j<=n;j++){
				if(nc[j]!=0 && cha[j]<mi){
					mi=cha[j];
					aim=j;
				} 
			} 
			ans-=cha[aim];
			//cout<<ans<<" ";
			nc[aim]=0;
			cnc--;
		}
		//cout<<endl;
		printf("%d\n",ans);
//		for(int j=1;j<=n;j++){
//			cout<<cha[j]<<" ";
//		}
	}
	return 0;
} 
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
