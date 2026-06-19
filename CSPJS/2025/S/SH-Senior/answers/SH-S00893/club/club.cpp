#include<bits/stdc++.h>
using namespace std;
struct Stu{
	int a[4];
	int sac;
	int Max,maxID,sMax,smaxID;
}a[100009];
int n,t,top,ans;
bool cmp(const Stu&x,const Stu&y){
	return x.sac>y.sac;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		top=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			if(x==y&&y==z) ans+=x;
			else{
				a[++top].a[1]=x,a[top].a[2]=y,a[top].a[3]=z;
				if(x==y){
					if(x>z){
						a[top].Max=x,a[top].maxID=4,a[top].sMax=z,a[top].smaxID=3,a[top].sac=x-z;
					}else{
						a[top].Max=z,a[top].maxID=3,a[top].sMax=x,a[top].smaxID=4,a[top].sac=z-x;
					}
				}else if(x==z){
					if(x>y){
						a[top].Max=x,a[top].maxID=5,a[top].sMax=y,a[top].smaxID=2,a[top].sac=x-y;
					}else{
						a[top].Max=y,a[top].maxID=2,a[top].sMax=x,a[top].smaxID=5,a[top].sac=y-x;
					}
				}else if(y==z){
					if(y>x){
						a[top].Max=y,a[top].maxID=6,a[top].sMax=x,a[top].smaxID=1,a[top].sac=y-x;
					}else{
						a[top].Max=x,a[top].maxID=1,a[top].sMax=y,a[top].smaxID=6,a[top].sac=x-y;
					}
				}else{
					if(x>y&&y>z) a[top].Max=x,a[top].maxID=1,a[top].sMax=y,a[top].smaxID=2,a[top].sac=x-y;
					else if(x>z&&z>y) a[top].Max=x,a[top].maxID=1,a[top].sMax=z,a[top].smaxID=3,a[top].sac=x-z;
					else if(y>x&&x>z) a[top].Max=y,a[top].maxID=2,a[top].sMax=x,a[top].smaxID=1,a[top].sac=y-x;
					else if(y>z&&z>x) a[top].Max=y,a[top].maxID=2,a[top].sMax=z,a[top].smaxID=3,a[top].sac=y-z;
					else if(z>x&&x>y) a[top].Max=z,a[top].maxID=3,a[top].sMax=x,a[top].smaxID=1,a[top].sac=z-x;
					else if(z>y&&y>x) a[top].Max=z,a[top].maxID=3,a[top].sMax=y,a[top].smaxID=2,a[top].sac=z-y;
				}
			}
		}
		sort(a+1,a+top+1,cmp);
		int sum[9]={};
		for(int i=1;i<=top;i++){
			Stu nw=a[i];
			if(nw.maxID>3){
				ans+=nw.Max;
				continue;
			}else if(sum[nw.maxID]+1<=n/2){
				sum[nw.maxID]++;
				ans+=nw.Max;
				continue;
			}
			if(nw.smaxID>3){
				ans+=nw.sMax;
				continue;
			}else{
				sum[nw.smaxID]++;
				ans+=nw.sMax;
				continue;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
