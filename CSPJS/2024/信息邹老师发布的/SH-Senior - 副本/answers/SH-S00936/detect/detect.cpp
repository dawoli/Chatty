#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=3010;
int n,t,m,d,v,a[N],c[N],ans1=0,ans2=0;
bool flag,b[N][N],f[N];
struct Node{
	int d,v,a,s,f;
	bool st;
}car[N]; 
bool check(int x,int y,int z,int i){
	int sum=x,s=x,l=y;
	bool flag=false;
	while(y>v){
		sum++;
		y=sqrt(l*l+2*z*(sum-s));
	}
	int f=sum-1;
	for(int j=1;j<=m;j++){
		if(a[j]>=s && a[j]<=f){
			c[j]++;
			b[j][i]=true;
			car[i].s=s;
			car[i].f=f;
			flag=true;
		} 
	}
	if(flag) return true;
	return false;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--){
    	scanf("%d %d %d %d",&n,&m,&d,&v);
    	ans2=m;
    	for(int i=1;i<=n;i++) scanf("%d %d %d",&car[i].d,&car[i].v,&car[i].a);
    	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    	sort(a+1,a+n+1);
    	for(int i=1;i<=n;i++){
    		int cnt=a[m]-car[i].d;
    		double s=sqrt(car[i].v*car[i].v+2*car[i].a*cnt);
    		if(car[i].a<0 && car[i].v>v){
				if(check(car[i].d,car[i].v,car[i].a,i)){
					ans1++;
					car[i].st=true;
				}
			}
    		else if(s>v){
    			ans1++;
    			car[i].st=true;
    			b[m][i]++;
    			f[i]=true;
			}			
		}
		for(int i=1;i<=n;i++){
			if(car[i].st){
				if(car[i].a<0){
					if(f[i]) continue;
					int maxn=0,p,cnt=0;
					for(int j=1;j<=m;j++){
						if(b[j][i]){
							if(maxn<b[j][i]){
								maxn=b[j][i];
								p=j;
							}
						}
					}
					for(int j=1;j<=n;j++){
						if(j==i) continue;
						if(b[p][j] && !f[j]){
							f[j]=true;
						}
					}
					ans2--;
				}else if(!flag){
				    ans2--;
				    flag=true;
			    }
			}
		}
		for(int i=1;i<=m;i++) c[i]=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				b[i][j]=0;
			}
		} 
		cout<<ans1<<" "<<ans2<<endl;
		for(int i=1;i<=n;i++) car[i].st=false;
		ans1=0,ans2=0;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
