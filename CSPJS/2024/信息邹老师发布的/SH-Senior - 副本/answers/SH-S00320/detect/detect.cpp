#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,h,lv,n,m,l,d[N],a[N],v[N],p[N],num[N],ans,ans1;
bool flag;
bool cmp(int c,int b){
	return c<=b;
}
void fdct(int e,int f,int g){
	flag=false;
	if(g==0){
	for(int o=1;o<=m;o++){
		if(e<p[o]){
			flag=true;
			num[o]++;
		}
	}
}
if(flag==true)ans++;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>l>>lv;
		ans=0;
		ans1=0;
		memset(num,0,sizeof(num));
		for(int j=1;j<=n;j++){
			cin>>d[j]>>v[j]>>a[j];
		}
		for(int j=1;j<=m;j++){
			cin>>p[j];
		}
		sort(p,p+m+1,cmp);
		for(int j=1;j<=n;j++){
			fdct(d[j],v[j],a[j]);
		}
		for(int j=1;j<=m;j++){
			if(num[j]==0)ans1++;
		}
		cout<<ans<<' '<<ans1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
