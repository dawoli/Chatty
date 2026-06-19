#include<bits/stdc++.h>
using namespace std;
struct ak{
	int a,b;
};
bool cmp(ak a,ak b){
	if(a.a==b.a){
		return b.b<a.b;
	}
	return a.a<b.a;
}
int n;
int nc,mc,l,v,dc[100005],vc[100005],ac[100005],p[100005],cnt=0,pcnt=0,bq[100005];
bool pn=0;
ak bi[100005];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int x[5]={0,2,6,9,10};
	cin>>n;
	for(int ni=0;ni<n;ni++){
		cin>>nc>>mc>>l>>v;
		cnt=0;
		pcnt=0;
		pn=0;
		for(int i=0;i<nc;i++){
			cin>>dc[i]>>vc[i]>>ac[i];
			bi[i].a=-1;
		}
		for(int i=0;i<mc;i++){
			cin>>p[i];
		}
		for(int i=0;i<nc;i++){
			if(ac[i]==0){
				if(vc[i]>v){
					int s=lower_bound(p,p+mc,dc[i])-p;
					if(s<mc){
						bi[i].a=s;
						bi[i].b=mc-1;
						cnt++;
						//cout<<i<<endl;
					}
				}
			}
			else if(ac[i]>0){
				double ds=(v*v-vc[i]*vc[i])*0.5/ac[i];
				int s=max(lower_bound(p,p+mc,dc[i]+ds)-p,lower_bound(p,p+mc,dc[i])-p);
				if(s<mc){
					bi[i].a=s;
					bi[i].b=mc-1;
					cnt++;
						//cout<<i<<endl;
				}
			}
			else{
				if(vc[i]>v){
					double ds=(v*v-vc[i]*vc[i])*0.5/ac[i];
					int s=lower_bound(p,p+mc,dc[i])-p;
					int sq=lower_bound(p,p+mc,dc[i]+ds)-p-1;
					if(s<=sq){
						bi[i].a=s;
						bi[i].b=sq;
						cnt++;
						//cout<<i<<endl;
					}
					//cout<<i<<" "<<s<<" "<<sq<<endl;
				}
			}
		}
		sort(bi,bi+nc,cmp);
		int ij=0,pi;
		for(int i=-1;i<mc;i++){
			if(pi<i){
				pn=0;
			}
			for(;bi[ij].a==i&&ij<nc;ij++){
				if(i!=-1){
					if(!pn){	
						pcnt++;
						//cout<<i<<"!!!"<<endl;
						pn=1;
						pi=bi[ij].b;
					}
					pi=min(pi,bi[ij].b);
					//cout<<pi<<endl;
				}
			}
		}
		cout<<cnt<<" "<<mc-pcnt<<endl;
	}
	return 0;
} 
