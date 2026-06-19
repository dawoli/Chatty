#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v,p[100010],ans1,ans2;
struct Car{
	int d,v,a;
}car[100010];
bool det[100010];
bool flag;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t){
		cin>>n>>m>>l>>v;
		ans1=0;
		ans2=m;
		flag=0;
		memset(det,0,sizeof(det));
		for(int i=0;i<n;i++)
			cin>>car[i].d>>car[i].v>>car[i].a;
		for(int i=0;i<m;i++)	
			cin>>p[i];
		for(int i=0;i<n;i++){
			flag=0;
			for(int j=0;j<m;j++)
				if(car[i].d>p[j])continue;
				else if(car[i].d<p[j]){
					if(car[i].v*car[i].v+2*car[i].a*(p[j]-car[i].d)>0){
						double v0=sqrt(car[i].v*car[i].v+2*car[i].a*(p[j]-car[i].d));
						if(v0>v){
							flag=1;
							det[p[j]]=1;
						}
					}
				}
				else
					if(car[i].v>v){
						flag=1;
						det[p[j]]=1;
					}
			if(flag)ans1++;
		}
		cout<<ans1<<" ";
		for(int i=0;i<=l;i++)
			if(det[i])ans2--;
		cout<<ans2<<endl;
		t--;
	}
	return 0;
}
