#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100009;
int t,n,cnt1,cnt2,cnt3,wantt,minn;
int d11[N],d22[N],d33[N];
struct Node{int d1,d2,d3,want1,want2,delta,mx;} a[N];
bool cmp(const Node&x,const Node&y){
	return x.want1==wantt&&y.delta>x.delta;
}
void operatee(int i){
	if(a[i].d1>=a[i].d2&&a[i].d2>=a[i].d3){
		cnt1++;
		a[i].mx=a[i].d1;
		a[i].want1=1;
		a[i].want2=2;
		a[i].delta=a[i].d1-a[i].d2;
		d11[cnt1]=a[i].delta;
	}
	else if(a[i].d1>=a[i].d3&&a[i].d3>=a[i].d2){
		cnt1++;
		a[i].mx=a[i].d1;
		a[i].want1=1;
		a[i].want2=3;
		a[i].delta=a[i].d1-a[i].d3;
		d11[cnt1]=a[i].delta;
	}
	else if(a[i].d2>=a[i].d1&&a[i].d1>=a[i].d3){
		cnt2++;
		a[i].mx=a[i].d2;
		a[i].want1=2;
		a[i].want2=1;
		a[i].delta=a[i].d2-a[i].d1;
		d22[cnt2]=a[i].delta;
	}
	else if(a[i].d2>=a[i].d3&&a[i].d3>=a[i].d1){
		cnt2++;
		a[i].mx=a[i].d2;
		a[i].want1=2;
		a[i].want2=3;
		a[i].delta=a[i].d2-a[i].d3;
		d22[cnt2]=a[i].delta;
	}
	else if(a[i].d3>=a[i].d1&&a[i].d1>=a[i].d2){
		cnt3++;
		a[i].mx=a[i].d3;
		a[i].want1=3;
		a[i].want2=1;
		a[i].delta=a[i].d3-a[i].d1;
		d33[cnt3]=a[i].delta;
	}
	else if(a[i].d3>=a[i].d2&&a[i].d2>=a[i].d1){
		cnt3++;
		a[i].mx=a[i].d3;
		a[i].want1=3;
		a[i].want2=2;
		a[i].delta=a[i].d3-a[i].d2;
		d33[cnt3]=a[i].delta;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cnt1=0;cnt2=0;cnt3=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			operatee(i);
		}
		int ans=0;
		for(int i=1;i<=n;++i) ans+=a[i].mx;
		minn=0;wantt=0;
		if(cnt1>n/2){
			wantt=1;
			minn=cnt1-n/2;
			sort(d11+1,d11+1+cnt1);
			for(int i=1;i<=minn;++i){
				ans-=d11[i];
			}
		}
		if(cnt2>n/2){
			wantt=2;
			minn=cnt2-n/2;
			sort(d22+1,d22+1+cnt2);
			for(int i=1;i<=minn;++i){
				ans-=d22[i];
			}
		}
		if(cnt3>n/2){
			wantt=3;
			minn=cnt3-n/2;
			sort(d33+1,d33+1+cnt3);
			for(int i=1;i<=minn;++i){
				ans-=d33[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

