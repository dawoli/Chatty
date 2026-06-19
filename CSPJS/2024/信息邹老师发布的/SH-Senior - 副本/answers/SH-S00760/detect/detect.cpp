#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V,d[100010],v[100010],a[100010],p[100010],pp[1000010],ppp[1000010],ans1,ans2,s,ooo[1000010],nn,p_[1000010];
struct _o{
	int o,oo;
}o_[1000010];
bool cmp(_o _o1,_o _o2){
	if(_o1.o<_o2.o)return 1;
	else if(_o1.o>_o2.o)return 0;
	else return _o1.oo<_o2.oo;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		ans1=ans2=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&p[i]);
			pp[p[i]]=1;
			p_[p[i]]=i;
		}
		nn=0,L=p[m];
		if(p[1]==0)ppp[0]=1;
		for(int i=1;i<=L;i++){
			ppp[i]=ppp[i-1]+pp[i];
		}
		for(int i=1;i<=n;i++){
			if((v[i]<=V&&a[i]<=0)||(d[i]>L));
			else if(a[i]>0){
				if(v[i]>V){
					ans1++;
					o_[++nn].o=d[i],o_[nn].oo=L;
				}
				else{
					s=(V*V-v[i]*v[i])/(a[i]*2);
					if(s<L)if(ppp[L]-ppp[d[i]+s]){
						ans1++;
						o_[++nn].o=d[i]+s+1,o_[nn].oo=L;
					}
				}
			}
			else if(a[i]<0){
				s=(V*V-v[i]*v[i]-1)/(a[i]*2);
				if((ppp[d[i]+s]-ppp[d[i]])||pp[d[i]]){
					ans1++;
					o_[++nn].o=d[i],o_[nn].oo=d[i]+s;
				}
			}
			else{
				ans1++;
				o_[++nn].o=d[i],o_[nn].oo=L;
			}
		}
		sort(o_+1,o_+nn+1,cmp);
		for(int i=1;i<=nn;i++){
			ooo[o_[i].o]++,ooo[o_[i].oo]--;
		}
		for(int i=1;i<=L;i++){
			ooo[i]+=ooo[i-1];
		}
		int i=1;
		while(i<=nn){
			int an=o_[i].o;
			for(int j=o_[i].o;j<=o_[i].oo;j++){
				if(ooo[j]>ooo[an]&&p_[an])an=j;
			}
			ans2++;
			int k=i;
			for(k;o_[k].o<=an;k++){
				for(int kk=an;kk<=o_[k].oo;k++){
					ooo[kk]--;
				}
			}
			i=k+1;
		}
		cout<<ans1<<" "<<m-ans2<<endl;
		for(int i=1;i<=L;i++){
			pp[i]=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
