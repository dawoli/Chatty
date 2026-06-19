#include<bits/stdc++.h>
//#define q1 q
//#define q2 q
//#define q3 q
using namespace std;

const int N=1e5+10;
int t,n;

struct node{
	int a1,a2,l1,l2;int cha;
}a[N];
int djk[10];

bool cmp(const node &x,const node &y){
	return x.cha<y.cha;
}
priority_queue<int,vector<int>,greater<int>> q1;
priority_queue<int,vector<int>,greater<int>> q2;
priority_queue<int,vector<int>,greater<int>> q3;
int op[10];
int ans;


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n; op[1]=n/2; op[2]=n/2; op[3]=n/2;
		memset(a,0,sizeof(a)); ans=0;
		while(!q1.empty()) q1.pop();while(!q2.empty()) q2.pop();while(!q3.empty()) q3.pop();
		for(int i=1;i<=n;i++){
			int mx=-1,mmx=-1,lx=0,lm=0;
			for(int j=1;j<=3;j++){
				cin>>djk[j];
				if(djk[j]>mx) mx=djk[j],lx=j;
			}
			for(int j=1;j<=3;j++) {
				if(lx==j) continue;
				if(djk[j]>mmx){
					mmx=djk[j]; lm=j;
				}
			}
			a[i].a1=mx;a[i].l1=lx; a[i].a2=mmx; a[i].l2=lm;
			a[i].cha=mx-mmx;
		}
		sort(a+1,a+n+1,cmp);
//		for(int i=1;i<=n;i++){
//			cout<<a[i].a1<<" "<<a[i].a2<<" "<<a[i].l1<<" "<<a[i].l2<<" "<<a[i].cha<<endl;
//		}
		for(int i=1;i<=n;i++){
			int df=a[i].l1; 
			int qp=1e8;
			if(df==1&&!q1.empty()) qp=q1.top();
			if(df==2&&!q2.empty()) qp=q2.top();
			if(df==3&&!q3.empty()) qp=q3.top();
			if(op[a[i].l1]){
				op[a[i].l1]--; ans+=a[i].a1;
				if(df==1) q1.push(a[i].cha);
				if(df==2) q2.push(a[i].cha);
				if(df==3) q3.push(a[i].cha);
			}
			
			else if(a[i].cha>qp){
				ans+=a[i].a1-qp; 
				if(df==1) q1.pop();if(df==2) q2.pop();if(df==3) q3.pop();
				if(df==1) q1.push(a[i].cha);
				if(df==2) q2.push(a[i].cha);
				if(df==3) q3.push(a[i].cha);
			}
			else{
				ans+=a[i].a2;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
