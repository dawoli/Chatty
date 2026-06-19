#include<bits/stdc++.h>
using namespace std; 
long long int t,n,m,l,vm,ans1,ans2,p[125000],k,pi[1250000],ud,rd,used[120005],md,op;
struct car{
	long long int d,v,a;
}c[125000];
bool cmp(car x,car y){
	if(x.a==0||y.a==0) return 1;
	return x.d<y.d;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
    for(int y=1;y<=t;y++){
    	cin>>n>>m>>l>>vm;
    	ans1=ans2=rd=md=op=0,ud=op;
    	memset(p,0,sizeof(p));
    	memset(pi,0,sizeof(pi));
    	memset(used,0,sizeof(used));
    	for(int i=1;i<=n;i++) cin>>c[i].d>>c[i].v>>c[i].a;
    	for(int i=1;i<=m;i++) cin>>p[i];
    	int j=1;
    	sort(c+1,c+n+1,cmp);
    	for(int i=1;i<=l;i++){
    		if(i>p[ud]) ud++;
    		pi[i]=ud;
    	}
    	for(int i=1;i<=n;i++){
    	if(c[i].a==0){
		if(c[i].v<=vm) continue;
		if(c[i].d<=p[m]) ans1++;  
	}
	if(c[i].a<0){
		if(c[i].v<=vm) continue;
		if((p[pi[c[i].d]]-c[i].d)*2*c[i].v+c[i].v*c[i].v<=vm*vm) continue;
		ans1++;
	}
	if(c[i].a>0){
		if((p[pi[c[i].d]]-c[i].d)*2*c[i].a+c[i].v*c[i].v<=vm*vm) continue;
		ans1++;
	}
    	}
    	for(int i=1;i<=m;i++){
    		for(int k=1;k<=n;k++){
    		if(c[k].a<0&&(c[k].d<p[i]||c[k].v>vm)){
		j=i;
		while(vm*vm<c[k].v*c[k].v+(2*c[k].a*(p[j]-c[k].d))&&(j<=m&&m<=i+2))j++;
		if(j-i==1){used[j]=1,md=max(md,p[j]),ans2++;break;}
    	}
		}
    }
    for(int i=1;i<=n;i++){
    	if(c[i].a>=0){
    		if(vm*vm>=c[i].v*c[i].v+(2*c[i].a*(md-c[i].d))){op=1;break;}
    	}
    }
    	cout<<ans1<<" "<<m-ans2-op<<endl;
    }
    return 0;
}
