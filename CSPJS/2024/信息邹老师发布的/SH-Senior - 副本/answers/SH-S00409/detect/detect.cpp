#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+9;
struct Car{
	int d;
	int v;
	int a;
}c[MAXN];
int n,m,l,V,p[MAXN];
int pmax;
bool xzA=true;
int closed;

bool cmpf(double a,double b){
	if(a-b>0.000001) return 1;
	return 0;
}

bool cmp(const Car &a,const Car &b){
	return a.d<b.d;
}

void solve_A(){	
	sort(c+1,c+1+n,cmp);
	int res = 0;
	for(int i=1;i<=n;i++){
		if(c[i].d > pmax) break;
		if(c[i].v>V) res++;
	}
	if(res==0){
		cout<<0<<' '<<m<<endl;
		return ;
	}
	cout<<res<<' '<<m-1<<endl;
}

double calc_V(int d0,int d,int v0,int a){
	double s = (d - d0) * 1.0;
	double v02 = v0*v0*1.0;
	double ad = a * 1.0;
	double as = ad * s;
	return sqrt(v02*1.0+2.0*as);
}

void solve_BF(){
	vector<bool> vst(n+1,0);
	vector<bool> nes(m+1,0);
	int cnt = 0,rem = 0;
	for(int i=1;i<=m;i++){
		double Vd = V * 1.0;
		for(int j=1;j<=n;j++){
			if(c[j].d>p[i]) break;
			if(!vst[j])
				if(cmpf(calc_V(c[j].d,p[j],c[j].v,c[j].a),Vd)){
					cnt++;
					vst[j]=1;
					if(!nes[i]){
						rem++;
						nes[i]=1;
					}
				}
		}
	}
	cout<<cnt<<' '<<m-rem<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		pmax=0;
		cin>>n>>m>>l>>V;
		for(int i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
			if(c[i].a!=0) xzA=false;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
			pmax = max(p[i],pmax);
		}
		if(xzA){
			solve_A();
			continue;
		}
		if(n<=20){
			solve_BF();
			continue;
		}
	}
	return 0;
}
