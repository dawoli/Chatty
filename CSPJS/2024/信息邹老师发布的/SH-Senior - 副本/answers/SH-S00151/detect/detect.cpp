#include <bits/stdc++.h>
using namespace std;
long long T;
long long n,m,l,vl,vl2,sum=0,rs=0,t;
struct car{
	long long d,a,v;
};
car c[100005];
long long flag[100005];
long long p[100005];
bool cmp(car x1,car x2){
	return x1.d>x2.d;
}
long long find(long long q){
	long long left=0;
	long long right=m;
	long long mid;
	while(left<right){
		mid=(left+right)/2;
		if(right-left==1){
			return right;
		} 
		if(q<p[mid]){
			right=mid;
		}
		else if(q>p[mid]){
			left=mid;
		}
		else{
			return mid;
		}
	}	
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(long long q=1;q<=T;q++){
		sum=0,rs=0,t=0;
		cin>>n>>m>>l>>vl;
		vl2=vl*vl;
		for(long long i=1;i<=100005;i++){
			c[i].d=0;
			c[i].a=0;
			c[i].v=0;
			p[i]=0;
			flag[i]=0;
		}
		for(long long i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
		}
		for(long long i=1;i<=m;i++){
			cin>>p[i];
		}
		sort(p+1,p+m+1);
		rs=m;
		sort(c+1,c+n+1,cmp);
		for(long long i=1;i<=n;i++){
			if(c[i].d>p[m]){
				continue;
			}
			if(c[i].a>=0){
				if(2*c[i].a*(p[m]-c[i].d)+c[i].v*c[i].v>vl2){
					sum++;
				}
			}
			if(c[i].a<0){
				long long k=0,k2=0;
				if(c[i].d<p[1]){
					k=1;
				}
				else{
					k=find(c[i].d);
				}
				if(2*c[i].a*(p[k]-c[i].d)+c[i].v*c[i].v>vl2){
					sum++;
					k2=find((vl2-c[i].v*c[i].v)/2/c[i].a+c[i].d)-1;
				}
				for(int j=k;j<=k2;j++){
					flag[j]=1;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(flag[j-1]==0&&flag[j]==1){
				t++;
			}
		}
		cout<<sum<<" "<<m-1-t<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
