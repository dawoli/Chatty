#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
ll T,nCar,nDet,Len,vLim,v[N],a[N],PosCar[N],PosDet[N],ans;
//L[i]:代表让车i超速的第一个位置 R[i]代表让车i超速的最后一个位置
ll read(){
	ll x=0,f=1;
//	cin>>x;
	char c=getchar();
	while(c<'0'||c>'9') f=((bool)(c^'-')<<1)-1,c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f*x;
}
struct qu{ll l,r;}es[N];
bool cmp(const qu&a,const qu&b){
	return a.r<b.r||(a.r==b.r&&a.l<b.l);
}
void chu(){
	memset(PosCar,0,sizeof(PosCar));
	memset(v,0,sizeof(v));
	memset(a,0,sizeof(a));
	memset(es,0,sizeof(es));
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		chu();
		nCar=read(),nDet=read(),Len=read(),vLim=read();
		ans=nCar;
		for(ll i=1;i<=nCar;++i)
			PosCar[i]=read(),v[i]=read(),a[i]=read();
		for(ll i=1;i<=nDet;++i) PosDet[i]=read();
		sort(PosDet+1,PosDet+nDet+1);
		for(ll i=1;i<=nCar;++i){//必须大于V
//			cout<<i<<":";
			if(a[i]==0){
				if(v[i]>vLim){
					es[i].l=lower_bound(PosDet+1,PosDet+nDet+1,PosCar[i])-PosDet,es[i].r=nDet;
					if(PosDet[nDet]<PosCar[i]) es[i].l=es[i].r=-1,--ans;
				}
				else es[i].l=-1,es[i].r=-1,--ans;
			}
			if(a[i]>0){
				ll s=max(0ll,(vLim*vLim-v[i]*v[i])/(2*a[i])+1);//从s开始就会被探测到
//				cout<<s<<" ";
//				cout<<vLim<<" "<<v[i]<<" "<<a[i]<<" "<<s<<"\n";
				if(PosDet[nDet]<PosCar[i]+s) es[i].l=es[i].r=-1,--ans;
				else{
					es[i].l=lower_bound(PosDet+1,PosDet+nDet+1,PosCar[i]+s)-PosDet,es[i].r=nDet;
					if(PosCar[i]+s>PosDet[es[i].l]) es[i].l=es[i].r=-1,--ans;
				}
			}
			if(a[i]<0){
				if(v[i]<vLim) es[i].l=es[i].r=-1,--ans;
				else{
					ll s=(v[i]*v[i]-vLim*vLim)/(2*(-a[i]));//s是最后一个会被查到的地方
//					cout<<"a:"<<a[i]<<"\n";
					if((v[i]*v[i]-vLim*vLim)%(2*(-a[i]))==0) --s;
//					cout<<"s:"<<s<<"\n";
					if(v[i]<vLim) es[i].l=es[i].r=-1,--ans;
					else{
						es[i].l=lower_bound(PosDet+1,PosDet+nDet+1,PosCar[i])-PosDet;
						es[i].r=upper_bound(PosDet+1,PosDet+nDet+1,PosCar[i]+s)-1-PosDet;
						if(PosDet[nDet]<=PosCar[i]+s) es[i].r=nDet;
						if(PosDet[es[i].l]<PosCar[i]||PosDet[es[i].r]<PosCar[i])
							es[i].l=es[i].r=-1,--ans;
					}
				}
			}
		}
		cout<<ans<<" ";
		sort(es+1,es+nCar+1,cmp);
		ll lst=0,cnt=0;
//		for(ll i=1;i<=nCar;++i)
//			cout<<es[i].l<<" "<<es[i].r<<"\n";
		for(ll i=1;i<=nCar;++i){
			if(es[i].l==-1) continue;
			if(lst<es[i].l) lst=es[i].r,++cnt;
		}
		cout<<nDet-cnt<<"\n";
	}
	return 0;
}
