#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll N=1e5+9,INF=-1;
const ld ERR=1e-3;
ll T,k,nCar,nDet,Len,Lmt,dst[N],v[N],a[N],pos[N];
struct range{
	ld st,ed;
}vE[N];
void FIO(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
}
inline ld X(ll p){
	return abs((Lmt*Lmt-v[p]*v[p])/2.0/a[p]);
}
inline bool open(ll x){
	return k&(1<<(nDet-x));
} 
inline ll lowbit(ll x){
	return x&(-x);
}
ll count(){
	ll res=0;
	for(ll i=1;i<=nCar;i++){
		bool Exceed=0;
		for(ll j=1;j<=nDet;j++){
			if(open(j))Exceed+=(pos[j]-vE[i].st>=0&&0<=vE[i].ed-pos[j]);
		}
		res+=Exceed;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	FIO();
	cin>>T;
	while(T--){
		ll ans=0;
		cin>>nCar>>nDet>>Len>>Lmt;
		for(ll i=1;i<=nCar;i++)cin>>dst[i]>>v[i]>>a[i];
		for(ll i=1;i<=nDet;i++)cin>>pos[i];
		for(ll i=1;i<=nCar;i++){
			if(a[i]>0){
				if(v[i]>Lmt){
					vE[i].st=dst[i];
					vE[i].ed=Len;
				}
				else if(dst[i]+X(i)<Len){
					vE[i].st=dst[i]+X(i)+ERR;
					vE[i].ed=Len;
				}
				else vE[i].st=vE[i].ed=INF;
			}
			else if(a[i]<0){
				if(v[i]>Lmt){
					vE[i].st=dst[i];
					vE[i].ed=dst[i]+X(i)-ERR;
				}
				else vE[i].st=vE[i].ed=INF;
			}
			else{
				if(v[i]>Lmt){
					vE[i].st=dst[i];
					vE[i].ed=Len;
				}
				else vE[i].st=vE[i].ed=INF;
			}
		}
//		for(ll i=1;i<=nCar;i++)cout<<vE[i].st<<" "<<vE[i].ed<<endl; 
//		return 0;
		ll all=0;
		for(ll i=1;i<=nCar;i++){
			bool Exceed=0;
			for(ll j=1;j<=nDet;j++){
				Exceed+=(pos[j]-vE[i].st>=0&&0<=vE[i].ed-pos[j]);
			}
			if(Exceed)all++;
			else vE[i].st=vE[i].ed=INF;
		}
		cout<<all<<" ";
		if(*min_element(a+1,a+1+nCar)>=0){
			cout<<nDet-((bool)all)<<endl;
		} 
		else{
			for(k=1;k<(1<<nDet);k++){
				if(count()==all){
					ll res=0;
					for(ll i=k;i;i-=lowbit(i))
						res++;
					ans=max(ans,nDet-res);
				}
			}
			cout<<ans<<endl;
		} 
	}
	return 0;
} 
