//uncompleted
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

inline int read() {
	char c=getchar(); int v=0,f=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (;isdigit(c);c=getchar()) v=v*10+c-48;
	return v*f;
}

#define r(a) a=read()

int T;
int n,m,x,can_catch,can_remove;
double L,V,d,v,a;
double catch_posL[100005],catch_posR[100005];
vector<int> det_pos;
bool vis[1000005];

signed main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	r(T);
	while (T--) {
		r(n); r(m);
		det_pos.clear();
		memset(vis,0,sizeof vis);
		can_catch=can_remove=0;
		scanf("%lf%lf",&L,&V);
		
		for (int i=1;i<=n;i++) {
			scanf("%lf%lf%lf",&d,&v,&a);
			if (a<0) {
				a=-a;
				if (v>V) {
					catch_posR[i]=(v*v-V*V)/(2.0*a)+d-1e-9;
					catch_posL[i]=d;
				}
				else {
					catch_posL[i]=L+1;
					catch_posR[i]=L+2;
				}
			}
			else if (a==0) {
				if (v>V) {
					catch_posR[i]=L;
					catch_posL[i]=d;
				}
				else {
					catch_posL[i]=L+1;
					catch_posR[i]=L+2;
				}
			}
			else {
				if (v>V) {
					catch_posL[i]=d;
					catch_posR[i]=L;
				}
				else {
					catch_posL[i]=(V*V-v*v)/(2.0*a)+d+1e-9;
					catch_posR[i]=L;
				}
			}
		}
		
		for (int i=1;i<=m;i++) {
			r(x);
			if (vis[x]) {
				can_remove++;
				continue;
			}
			vis[x]=1;
			det_pos.push_back(x);
		}
		
		for (int i=1;i<=n;i++) {
		//	cout<<catch_posL[i]<<" "<<catch_posR[i]<<"\n";
			auto it=lower_bound(det_pos.begin(),det_pos.end(),catch_posL[i]);
		//	auto it2=upper_bound(det_pos.begin(),det_pos.end(),catch_posL[i]);
			if (it==det_pos.end()) continue;
			else if ((*it)<=catch_posR[i]) can_catch++; 
		}
		printf("%d\n",can_catch);
	}
	return 0;
}

