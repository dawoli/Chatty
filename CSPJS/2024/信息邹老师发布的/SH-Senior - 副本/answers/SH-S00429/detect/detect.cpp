#include<bits/stdc++.h>
using namespace std;
struct node{
	int d,v,a;
};
inline int myabs(int x){
	return max(x,-x);
}
inline long double mydoubleabs(double x){
	return max(x,-x);
}
inline long double calc(int s,int v,int a){//距离 初速度 加速度 求行驶 s 个距离单位时的瞬间速度 
	return mydoubleabs(sqrt(2*a*s+v*v));
}
void solve(){
	int n,m,L,V;
	int p[100010];
	node s[100010];
	for(int i=0;i<=100001;i++){
		s[i].d=0;
		s[i].v=0;
		s[i].a=0;
		p[i]=-1;
	}
	cin>>n>>m>>L>>V;
	bool A=true,B=true,C=true,D=false;//分别对应性质A 性质B 性质C 和 数据极小的情况 

	for(int i=1;i<=n;i++){
		cin>>s[i].d>>s[i].v>>s[i].a;
		if(s[i].a!=0){
			A=false;
		}
		if(s[i].a<=0){
			B=false;
		}
		/*if(s[i].a>=0){
			C=false;
		}*/
	}
	if(n<=20&&m<=20) D=true;
	int southp=1e9,nouthp=-1e9;
	for(int i=1;i<=m;i++){
		cin>>p[i];
		if(p[i]<=southp) southp=p[i];
		if(p[i]>=nouthp) nouthp=p[i];
	}
	if(A){
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			if(myabs(s[i].v)<=V) continue;
			if(s[i].v<=0&&s[i].d>=southp){
				cnt1++;
			}
			else if(s[i].v>=0&&s[i].d<=nouthp){
				cnt2++;
			}
		}
		int ans1=2;
		int ans2=cnt1+cnt2;
		if(cnt1==0){
			ans1--;
		}
		if(cnt2==0){
			ans1--;
		}
		cout<<ans2<<" "<<m-ans1<<endl;
	}
	else if(B){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i].d>nouthp){
				continue;
			}
			long double car_speed=calc(nouthp-s[i].d,s[i].v,s[i].a);
			if(car_speed>V){
				cnt++;
			}
		} 
		if(cnt==0){
			cout<<0<<" "<<m<<endl;
			return ;
		}
		cout<<cnt<<" "<<m-1<<endl;
	}
	else if(D){
		int cnt1=0,cnt2=0;
		long double carspd[21][21];
		bool keepp[30];
		bool carchaosu[30];
		for(int i=0;i<=20;i++){
			for(int j=0;j<=20;j++){
				carspd[i][j]=0;
			}
			keepp[i]=false;
			carchaosu[i]=false;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(s[i].d>p[j]){
					continue;
				}
				carspd[i][j]=calc(p[j]-s[i].d,s[i].v,s[i].a);
				if(carspd[i][j]>V){
					if(!carchaosu[i]){
						cnt1++;
					}
					carchaosu[i]=true;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(carchaosu[i]&&carspd[i][j]>V){
					if(!keepp[j]){
						cnt2++;
					}
					keepp[j]=true;
					break;
				}
			}
		}
		cout<<cnt1<<" "<<m-cnt2<<endl;
	}
	else if(C){
		int cnt=0;
		for(int i=1;i<=n;i++){
			int nowp=lower_bound(p+1,p+m+1,s[i].d)-p;
			if(nowp>m){
				continue;
			}
			nowp=p[nowp];
			long double car_speed=calc(nowp-s[i].d,s[i].v,s[i].a);
			if(car_speed>V){
				cnt++;
			}
		}
	}
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		solve();
	}
	return 0;
} 
