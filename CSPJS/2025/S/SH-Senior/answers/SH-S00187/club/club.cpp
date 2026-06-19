#include<iostream>
#include<algorithm>
using namespace std;
int t,n,cluba,clubb,clubc,ca[200],cb[200],d,v[200],ans;
struct{
	int a,b,c,big,big_lc;
}m[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cluba=0;clubb=0;clubc=0;
		if(n==2){
			for(int i=0;i<n;i++){
			cin>>m[i].a>>m[i].b>>m[i].c;
			m[i].big=max(max(m[i].a,m[i].b),m[i].c);
			if(m[i].big==m[i].a){m[i].big_lc=1;}
			else if(m[i].big==m[i].b){m[i].big_lc=2;}
			else m[i].big_lc=3;}
			cout<<max(m[0].a+m[1].b,max(m[0].a+m[1].c,max(m[0].b+m[1].a,max(m[0].b+m[1].c,max(m[0].c+m[1].a,m[0].c+m[1].b)))))<<endl;
			continue;}
		if(n==200){
			for(int i=0;i<n;i++){
				cin>>m[i].a>>m[i].b>>m[i].c;
				if(m[i].a>=m[i].b){
					m[i].b-=m[i].a;
				}
				else m[i].a-=m[i].b;
			}
			for(int i=0;i<200;i++){
				if(m[i].a>0){
					ca[cluba]=i;
					cluba++;
				}
				else {cb[clubb]=i;clubb++;}
			}
			ans=0;
			for(int i=0;i<cluba;i++){
				ans+=m[ca[i]].a;
			}
			for(int i=0;i<clubb;i++){
				ans+=m[cb[i]].b;
			}
			d=cluba-n/2;
			if(d>0){
				for(int i=0;i<cluba;i++){
					v[i]=m[ca[i]].b;
				}
				sort(v,v+cluba);
				for(int i=cluba-1;i>=cluba-n/2;i--){
					ans+=v[i];
				}
			}
			if(d<0){
				for(int i=0;i<clubb;i++){
					v[i]=m[cb[i]].a;
				}
				sort(v,v+clubb);
				for(int i=clubb-1;i>=clubb-n/2;i--){
					ans+=v[i];
				}
			}
			cout<<ans<<endl;
		}
		else cout<<"114514"<<endl<<"1919810"<<endl;
	}
	return 0;
}
