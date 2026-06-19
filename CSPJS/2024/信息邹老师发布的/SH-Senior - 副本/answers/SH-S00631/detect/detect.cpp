#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,L,V,s=0;
int d[100001],v[100001],a[100001],ll[100001],rr[100001],p[100001];bool b[100001];
int tsa=1,l=0,r=0;double f=0;
bool ok(int i){
	for(int i=1;i<=m;i++){
		if(p[i]>=ll[i]&&p[i]<=rr[i]&&b[i]==true)
			return true;
	}
	return false;
}
int sl(){
	int mid=1;
	while(mid<=m&&p[mid]<l){
			if(p[mid+1]>=l&&p[mid+1]<=r)
				return mid+1;
			mid++;
	}
	if(p[mid+1]<l||p[mid+1]>r)
		return 0;
	return mid;
}
int sr(){
	int mid=m;
	while(mid>=1&&p[mid]>r){
			if(p[mid-1]<=r&&p[mid-1]>=l)
				return mid-1;
		mid--;
	}
	if(p[mid-1]>r||p[mid-1]<l)
		return 0;
	return mid;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		scanf("%d%d%d%d",&n,&m,&L,&V);
		s=0;
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",d+i,v+i,a+i);
		for(int i=1;i<=m;i++)
			scanf("%d",p+i);
		tsa=1;
		for(int i=1;i<=n;i++){
			if(a[i]!=0){
				tsa=0;break;
			}
		}
		if(tsa==1){
			for(int i=1;i<=n;i++){
				if(V>=v[i]){
					continue;
				}
				if(p[m]>=d[i])
					s++;
			}
			if(s>0)
				m--;
			printf("%d %d\n",s,m);
		}
		else{
			for(int i=1;i<=n;i++){
				if(V>=v[i]&&a[i]<=0){
					continue;
				}
				if(a[i]==0||a[i]>0&&v[i]>V){
					if(p[m]>=d[i])
						s++;
				}
				else if(a[i]<0){
					l=d[i];
					r=d[i]+((V*V)-(v[i]*v[i]))/2.0/a[i];
					ll[i]=1;
					rr[i]=sr();
					if(rr[i]!=0)
						s++;
				}
				else{
					f=(V*V-v[i]*v[i])/2.0/a[i];
					l=d[i]+max((int)f,0);
					if(f!=(int)f)
						l++;
					r=max(l,L);
					ll[i]=sl();
					rr[i]=m;
					if(ll[i]!=0)
						s++;
				}
				printf("%d ",s);
				int mi=100000;
				for(int i=1;i<=n;i++)
					b[i]=false;
				for(int i=1;i<=pow(2,m);i++){
					int ii=i;int q=0;
					for(int j=1;ii>0;ii/=2){
						if(ii%2==1){
							b[j]=true;q++;
						}
							else
							b[j]=false;
							j++;
						}
					if(!ok(i))
						continue;
					int aa=q;
					if(aa<mi)	
						mi==aa;
					cout<<mi;
				}
			}
		}
		printf("\n");
	}
	return 0;
} 
