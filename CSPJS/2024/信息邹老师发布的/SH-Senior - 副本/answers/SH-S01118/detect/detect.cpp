#include<bits/stdc++.h>
using namespace std;
struct node{
	int d,v,a,cnt;
}car[100010];
struct node2{
	int p;
	int f[4900],tail;
}cam[100010];

bool cmp(node2 t1,node2 t2){
	return t1.tail<t2.tail;
}

int t,n,m,l,v;
bool ok[100010];
int t1,t2,t3;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int T=0;T<t;T++){
		for(int i=0;i<n;i++) car[i].cnt=0;
		for(int i=0;i<m;i++) cam[i].tail=0;
		memset(ok,false,sizeof(ok));
		cin>>n>>m>>l>>v;
		for(int i=0;i<n;i++){
			cin>>car[i].d>>car[i].v>>car[i].a;
		}
		for(int i=0;i<m;i++){
			cin>>cam[i].p;
		}
		int ans1=0,ans2=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				long long v1 = car[i].v*car[i].v + 2*car[i].a*(cam[j].p-car[i].d);
				if(car[i].d>cam[j].p) continue;
				if(v1>v*v){
					if(!ok[i]){
						ans1++;
						ok[i] = true;
					}
					car[i].cnt++;
					cam[j].f[ cam[j].tail ] = i;
					cam[j].tail++;
				}
			}
		}
		sort(cam,cam+m,cmp);
		for(int i=0;i<m;i++){
			bool flag=false;
			for(int j=0;j<cam[i].tail;j++){
				if(car[cam[i].f[j]].cnt<=1){
					flag=true;
					break;
				}
			}
			if(!flag){
				for(int j=0;j<cam[i].tail;j++){
					car[cam[i].f[j]].cnt--;
				}
				ans2++;
			}
		}
		cout<<ans1<<" "<<ans2<<"\n";
	}
	return 0;
}

