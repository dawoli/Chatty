#include<bits/stdc++.h>
using namespace std;
int s[100005][3],c[3],d[100005],g[100005],v[100005][3],x[100005],u[3];
int tmax(int a,int b,int f){
	return max(max(a,b),f);
}
int tmid(int a,int b,int f){
	u[0]=a;
	u[1]=b;
	u[2]=f;
	sort(u,u+3);
	return u[1];
}
void solve(){
	memset(s,0,sizeof(s));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	memset(g,0,sizeof(g));
	memset(v,0,sizeof(v));
	memset(x,0,sizeof(x));
	int n,ans=0,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<3;j++){ 
			cin>>s[i][j];
		}	
	for(int i=0;i<n;i++){
		int m=tmax(s[i][0],s[i][1],s[i][2]),z;
		g[i]=m;
		for(int j=0;j<3;j++){
			if(m==s[i][j]){
				z=j;
				break;
			}
		}
		c[z]++;
		v[i][z]=1;
		d[i]=m-tmid(s[i][0],s[i][1],s[i][2]);
	}
	for(int i=0;i<n;i++){
		ans+=g[i];
	}
	if(c[0]>n/2||c[1]>n/2||c[2]>n/2){
		int k=tmax(c[0]-n/2,c[1]-n/2,c[2]-n/2),q;
		for(int i=0;i<3;i++)
			if(k==c[i]-n/2){
				q=i;
				break;
			}
		for(int i=0;i<n;i++){
			if(v[i][q]==1)
				x[cnt++]=d[i];
		}
		sort(x,x+c[q]);
		for(int i=0;i<k;i++)
			ans-=x[i];
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
