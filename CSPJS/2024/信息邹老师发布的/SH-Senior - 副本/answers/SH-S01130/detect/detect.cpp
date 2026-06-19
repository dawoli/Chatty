#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll T,m,L,V;
struct Car{
	ll d;
	ll v;
	ll a;
};
struct Qu{
	ll l;
	ll r;
};
bool operator <(const Qu &A,const Qu &B){
	return A.r<B.r;
}
Car car[100009];
bool overspeed[29];
bool overspeed2[29];
ll detect[100009];
double lastv[100009];
Qu qujian[100009];
ll speed[29][29]; // [car][detect]
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		memset(lastv,0,sizeof(lastv));
		memset(speed,0,sizeof(speed));
		memset(overspeed,0,sizeof(overspeed));
		memset(overspeed2,0,sizeof(overspeed2));
		cin>>n>>m>>L>>V;
		bool alla0=1;
		bool allbigger0=1;
		for(ll i=1;i<=n;i++){
			cin>>car[i].d>>car[i].v>>car[i].a;
			if(car[i].a!=0) alla0=0;
			if(car[i].a<=0) allbigger0=0;
		} 
		for(ll i=1;i<=m;i++){
			cin>>detect[i];
		}
		sort(detect+1,detect+1+m);
		if(alla0){
			ll ans=0;
			for(ll i=1;i<=n;i++){
				if(car[i].d<=detect[m]&&car[i].v>V){
					ans++;
				}
			}
			cout<<ans<<" ";
			if(ans==0) cout<<m<<endl;
			else cout<<m-1<<endl;
			continue;
		}
		if(allbigger0){
			ll ans=0;
			for(ll i=1;i<=n;i++){
				lastv[i]=sqrt(2*car[i].a*(detect[m]-car[i].d)*1.0+car[i].v*car[i].v*1.0);
				if(lastv[i]>(double)V) ans++;
			}
			cout<<ans<<" ";
			if(ans==0) cout<<m<<endl;
			else cout<<m-1<<endl;
			continue;
		}
		if(n<=20&&m<=20){
			ll ans=0;
			for(ll i=1;i<=n;i++){
				
				if(car[i].a>0){
					double x=(double)car[i].d+(V*V-car[i].v*car[i].v)*1.0/(2*car[i].a*1.0);
					if(x<=detect[m]){
						ll pos=lower_bound(detect+1,detect+1+m,x)-detect;
						for(ll j=pos;j<=m;j++){
							speed[i][j]=1;
						}
					}
				}else if(car[i].a==0){
					if(car[i].v>V&&car[i].d<=detect[m]){
						ll pos=lower_bound(detect+1,detect+1+m,car[i].d)-detect;
						for(ll j=pos;j<=m;j++){
							speed[i][j]=1;
						}
					}
				}
				else if(car[i].a<0){
					if(car[i].v>V){
						double x=(double)car[i].d+(V*V-car[i].v*car[i].v)*1.0/(2*car[i].a*1.0);	
						ll pos;
						if(x>=detect[m]) pos=m;
						else{
							pos=lower_bound(detect+1,detect+1+m,x)-detect;
							if(detect[pos]>x) pos--;
						}
						ll pos2=lower_bound(detect+1,detect+1+m,car[i].d)-detect;
						for(ll j=pos2;j<=pos;j++){
							speed[i][j]=1;
						}
					}
				
				}
				for(ll j=1;j<=m;j++){
					if(speed[i][j]){
						ans++; overspeed[i]=1; break;
					}
				}
			}
			cout<<ans<<" ";
			if(ans==0){
				cout<<m<<endl;
				continue;
			}
		//	for(ll i=1;i<=n;i++){
			//	for(ll j=1;j<=m;j++){
			//		cout<<speed[i][j]<<" ";
			//	}
			//	cout<<endl;
		//	}
			//cout<<"overspeed:";
			//for(ll i=1;i<=n;i++){
			//	cout<<overspeed[i]<<" ";
			//}
			//cout<<endl;
			ll maxn=0;
			for(ll i=1;i<=(1<<m)-1;i++){
				memset(overspeed2,0,sizeof(overspeed2));
				for(ll j=1;j<=m;j++){
					if(i&(1<<(j-1))){
						for(ll J=1;J<=n;J++){
							if(speed[J][j]){
								overspeed2[J]=1;
								//if(i==16){
								//	cout<<"overspeed2"<<" "<<J<<endl;
								//}
							}//else{
							//	overspeed2[J]=0;
						//	}
						}
					}
				}
				//if(i==16){
				
				//for(ll i=1;i<=n;i++){
				//	cout<<overspeed2[i]<<" ";
				//}}
				bool flag=1;
				for(ll J=1;J<=n;J++){
					if(overspeed[J]!=overspeed2[J]){
						flag=0; break;
					}
				}
				if(flag){
					//cout<<"A"<<i<<endl;
					ll cnt1=0;
					for(ll j=1;j<=m;j++){
						//cout<<j<<" ";
						//cout<<(i&(1<<(j-1)))<<" ";
						if((i&(1<<(j-1)))==0){
							cnt1++;
						}
					}
					if(cnt1>maxn) maxn=cnt1;
				}
			}
			cout<<maxn<<endl;
		}
		else{
			ll ans=0;
			for(ll i=1;i<=n;i++){
				
				if(car[i].a>0){
					double x=(double)car[i].d+(V*V-car[i].v*car[i].v)*1.0/(2*car[i].a*1.0);
					if(x<=detect[m]){
						ll pos=lower_bound(detect+1,detect+1+m,x)-detect;
						/*for(ll j=pos;j<=m;j++){
							speed[i][j]=1;
						}*/
						
						if(pos<=m){
							ans++;qujian[ans].l=pos;
						qujian[ans].r=m;overspeed[i]=1;
						}
						
					}
				}else if(car[i].a==0){
					if(car[i].v>V&&car[i].d<=detect[m]){
						ll pos=lower_bound(detect+1,detect+1+m,car[i].d)-detect;
						/*for(ll j=pos;j<=m;j++){
							speed[i][j]=1;
						}*/
						
						if(pos<=m){
							ans++;qujian[ans].l=pos;
						qujian[ans].r=m;overspeed[i]=1;
						}
					}
				}
				else if(car[i].a<0){
					if(car[i].v>V){
						double x=(double)car[i].d+(V*V-car[i].v*car[i].v)*1.0/(2*car[i].a*1.0);	
						ll pos;
						if(x>=detect[m]) pos=m;
						else{
							pos=lower_bound(detect+1,detect+1+m,x)-detect;
							if(detect[pos]>x) pos--;
						}
						ll pos2=lower_bound(detect+1,detect+1+m,car[i].d)-detect;
					/*	for(ll j=pos2;j<=pos;j++){
							speed[i][j]=1;
						}*/
						//cout<<"i="<<i<<" "<<pos2<<" "<<pos<<endl;
					
		
						if(pos2<=pos){	
							
							ans++;qujian[ans].l=pos2;
							qujian[ans].r=pos;overspeed[i]=1;
						}
						
					}
				
				}
				//for(ll j=1;j<=m;j++){
				//	if(speed[i][j]){
				//		ans++; overspeed[i]=1; break;
				//	}
				//}
			}
			cout<<ans<<" ";
		//	for(ll j=1;j<=ans;j++){
			//	cout<<qujian[j].l<<" "<<qujian[j].r<<endl;
			//	}
			if(ans==0){
				cout<<m<<endl;
				continue;
			}else{
				sort(qujian+1,qujian+1+ans);
				
				ll res=1;
				ll last=qujian[1].r;
				for(ll j=2;j<=ans;j++){
					if(qujian[j].l>last){
						last=qujian[j].r;
						res++;
					}
				}
				cout<<m-res<<" "<<endl;
			}
			//for(ll i=1;i<=n;i++){
			//	for(ll j=1;j<=m;j++){
			//		cout<<speed[i][j]<<" ";
			//	}
			//	cout<<endl;
			//}
			//cout<<"overspeed:";
			//for(ll i=1;i<=n;i++){
			//	cout<<overspeed[i]<<" ";
			//}
			//cout<<endl;
			/*ll maxn=0;
			for(ll i=1;i<=(1<<m)-1;i++){
				memset(overspeed2,0,sizeof(overspeed2));
				for(ll j=1;j<=m;j++){
					if(i&(1<<(j-1))){
						for(ll J=1;J<=n;J++){
							if(speed[J][j]){
								overspeed2[J]=1;
								//if(i==16){
								//	cout<<"overspeed2"<<" "<<J<<endl;
								//}
							}//else{
							//	overspeed2[J]=0;
						//	}
						}
					}
				}
				//if(i==16){
				
				//for(ll i=1;i<=n;i++){
				//	cout<<overspeed2[i]<<" ";
				//}}
				bool flag=1;
				for(ll J=1;J<=n;J++){
					if(overspeed[J]!=overspeed2[J]){
						flag=0; break;
					}
				}
				if(flag){
					//cout<<"A"<<i<<endl;
					ll cnt1=0;
					for(ll j=1;j<=m;j++){
						//cout<<j<<" ";
						//cout<<(i&(1<<(j-1)))<<" ";
						if((i&(1<<(j-1)))==0){
							cnt1++;
						}
					}
					if(cnt1>maxn) maxn=cnt1;
				}
			}*/
			//cout<<maxn<<endl;
		}
	
	}
	return 0;
} 
/*1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15*/
