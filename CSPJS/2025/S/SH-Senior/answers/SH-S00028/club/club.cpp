#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100009;
int n,t1=0,t2=0,t3=0,ans=0;
struct member{
	int d1,d2,d3,team;
	int c1,c2,c3;
}mem[N];
bool cmp1(member a,member b){
	return min(a.c1,a.c2)>min(b.c1,b.c2);
}
bool cmp2(member a,member b){
	return min(a.c1,a.c3)>min(b.c1,b.c3);
}
bool cmp3(member a,member b){
	return min(a.c3,a.c2)>min(b.c3,b.c2);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;t1=0;t2=0;t3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			mem[i].d1=mem[i].d2=mem[i].d3=mem[i].team=0;
			cin>>mem[i].d1>>mem[i].d2>>mem[i].d3;
			mem[i].c1=abs(mem[i].d2-mem[i].d1);
			mem[i].c2=abs(mem[i].d3-mem[i].d1);
			mem[i].c3=abs(mem[i].d2-mem[i].d3);
			if(mem[i].d1>=mem[i].d2&&mem[i].d1>=mem[i].d3){
				mem[i].team=1;
				ans+=mem[i].d1;
				t1++;
			}
			else if(mem[i].d2>=mem[i].d1&&mem[i].d2>=mem[i].d3){
				mem[i].team=2;
				ans+=mem[i].d2;
				t2++;
			}
			else if(mem[i].d3>=mem[i].d1&&mem[i].d3>=mem[i].d2){
				mem[i].team=3;
				ans+=mem[i].d3;
				t3++;
			}
		}
		int m=n/2;
		if(t1<=m&&t2<=m&&t3<=m){
			cout<<ans<<endl;
		}
		else if(t1>m){
			int k=t1-m;
			sort(mem+1,mem+1+n,cmp1);
			for(int i=n;i>=1;i--){
				if(mem[i].team==1){
					if(mem[i].d2>=mem[i].d3){
						ans=ans+mem[i].d2-mem[i].d1;
						mem[i].team=2;
					}
					else{
						ans=ans+mem[i].d3-mem[i].d1;
						mem[i].team=3;
					}
					k--;
					if(k==0)break;
				}
			}
			cout<<ans<<endl;
		}
		else if(t2>m){
			int k=t2-m;
			sort(mem+1,mem+1+n,cmp2);
			for(int i=n;i>=1;i--){
				if(mem[i].team==2){
					if(mem[i].d1>=mem[i].d3){
						ans=ans+mem[i].d1-mem[i].d2;
						mem[i].team=1;
					}
					else{
						ans=ans+mem[i].d3-mem[i].d2;
						mem[i].team=2;
					}
					k--;
					if(k==0)break;
				}
			}
			cout<<ans<<endl;
		}
		else if(t3>m){
			int k=t3-m;
			sort(mem+1,mem+1+n,cmp3);
			for(int i=n;i>=1;i--){
				if(mem[i].team==3){
					if(mem[i].d1>=mem[i].d2){
						ans=ans+mem[i].d1-mem[i].d3;
						mem[i].team=1;
					}
					else{
						ans=ans+mem[i].d2-mem[i].d3;
						mem[i].team=2;
					}
					k--;
					if(k==0)break;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
