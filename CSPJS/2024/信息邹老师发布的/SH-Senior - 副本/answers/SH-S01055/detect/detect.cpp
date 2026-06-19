#include<bits/stdc++.h>
#define int long long
using namespace std;
class car{
public:
	bool ON = true;bool fast_;
	double v;
	int a,L;
	int checkpoint_=0,prevcheckpoint_=-1;
	double checkspeed(int x){
		if(x<checkpoint_){
			return -1;
		}
		int deltalength=x-checkpoint_;
		if((v*v+2*a*deltalength)<0){
			ON=false;
			return (double)-1;
		}
		prevcheckpoint_=checkpoint_;
		checkpoint_=x;
		v=sqrt(v*v+2*a*deltalength);
		return v;
	}
	car(int v0,int a0,int L0,int startpoint_){
		fast_=false;
		ON=true;
		v=(double)v0;
		a=a0;
		L=L0;
		checkpoint_=startpoint_;
	}
};
vector<car> c;
void process_(){
	c.clear();
	int n,m,L,V,cntchec=0,cntcar=0;
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++){
		int di,vi,ai;
		cin>>di>>vi>>ai;
		car temp(vi,ai,L,di);
		c.push_back(temp);
	}
	for(int i=1;i<=m;i++){
		int chec;bool useful=false;
		cin>>chec;
		for(int i=0;i<c.size();i++){
			if(c[i].ON){
				double velo=c[i].checkspeed(chec);
				if(velo>V&&(!c[i].fast_)){
					c[i].fast_=true;
					useful=true;
					cntcar++;
				}
			}
		}
		cntchec+=(int)useful;
	}
	cout<<cntcar<<' '<<m-cntchec<<endl;
	return;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T --> 0){
		process_();
	}
	return 0;
}
