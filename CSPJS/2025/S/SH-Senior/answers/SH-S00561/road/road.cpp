#include<bits/stdc++.h>
using namespace std;
int t,n;
struct mbr{
	int a;
	int b;
	int c;
};
mbr ga[100010],gb[100010],gc[100010];
int ka,kb,kc;
int ans;
bool cprsa(mbr x,mbr y){
	int ckx=x.a-max(x.b,x.c),cky=y.a-max(y.b,y.c);
	return ckx<cky;
}
bool cprsb(mbr x,mbr y){
	int ckx=x.b-max(x.a,x.c),cky=y.b-max(y.a,y.c);
	return ckx<cky;
}
bool cprsc(mbr x,mbr y){
	int ckx=x.c-max(x.b,x.a),cky=y.c-max(y.b,y.a);
	return ckx<cky;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		n=0;
		cin>>n;
		ans=0;
		ka=0;
		kb=0;
		kc=0;
		memset(ga,0,sizeof(ga));
		memset(gb,0,sizeof(gb));
		memset(gc,0,sizeof(gc));
		for(int i=1;i<=n;i++){
			mbr ppl;
			cin>>ppl.a>>ppl.b>>ppl.c;
			if(ppl.a>=ppl.b && ppl.a>=ppl.c){
				ga[ka+1]=ppl;
				ans+=ppl.a;
				ka++;
			}
			else if(ppl.a<=ppl.b && ppl.b>=ppl.c){
				gb[kb+1]=ppl;
				ans+=ppl.b;
				kb++;
			}
			else if(ppl.c>=ppl.b && ppl.a<=ppl.c){
				gc[kc+1]=ppl;
				ans+=ppl.c;
				kc++;
			}
		}
		if(ka<=(n/2) && kb<=(n/2) && kc<=(n/2)){
			cout<<ans<<endl;
		}
		else{
			if(ka>(n/2)){
				sort(ga+1,ga+ka+1,cprsa);
//				for(int i=1;i<=ka;i++){//
//					cout<<ga[i].a<<' '<<ga[i].b<<' '<<ga[i].c<<endl;//
//				}//
				for(int i=1;i<=ka-(n/2);i++){
					//cout<<t<<"t"<<ans<<endl;//
					ans-=(ga[i].a-max(ga[i].b,ga[i].c));
				}
			}
			else if(kb>(n/2)){
				sort(gb+1,gb+kb+1,cprsb);
//				for(int i=1;i<=kb;i++){//
//					cout<<gb[i].a<<' '<<gb[i].b<<' '<<gb[i].c<<endl;//
//				}//
				for(int i=1;i<=kb-(n/2);i++){
					//cout<<t<<"t"<<ans<<endl;//
					ans-=(gb[i].b-max(gb[i].a,gb[i].c));
				}
			}
			else if(kc>(n/2)){
				sort(gc+1,gc+kc+1,cprsc);
//				for(int i=1;i<=kc;i++){//
//					cout<<gc[i].a<<' '<<gc[i].b<<' '<<gc[i].c<<endl;//
//				}//
				for(int i=1;i<=kc-(n/2);i++){
					//cout<<t<<"t"<<ans<<endl;//
					ans-=(gc[i].c-max(gc[i].a,gc[i].b));
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
