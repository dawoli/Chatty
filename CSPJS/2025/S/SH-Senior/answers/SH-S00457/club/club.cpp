#include<bits/stdc++.h>
using namespace std;
#define int long long
struct ss{
	int a,b,c,del;
};
int n,T;
ss x[100009];
ss xa[100009];
bool spa=1,spb=1;
bool cmp1(const ss&y,const ss&z){
	return y.a>z.a;
}
bool cmp2(const ss&y,const ss&z){
	return abs(y.a-y.b)>abs(z.a-z.b);
}
bool cmp3(const ss&y,const ss&z){
	return y.del>z.del;
}
int sA(){
	int ans=0;
	sort(x+1,x+n+1,cmp1);
	for(int i=1;i<=n/2;i++){
		ans+=x[i].a;
	}
	return ans;
}
int solveB(){
	int ans=0;
	int numa=0,numb=0;
	sort(x+1,x+n+1,cmp2);
	for(int i=1;i<=n;i++){
		if(x[i].a>x[i].b){
			numa++;
			ans+=x[i].a;
		}else{
			numb++;
			ans+=x[i].b;
		}
		if(numa==n/2){
			for(int j=i+1;j<=n;j++){
				ans+=x[j].b;
			}
			return ans;
		}
		if(numb==n/2){
			for(int j=i+1;j<=n;j++){
				ans+=x[j].a;
			}
			return ans;
		}
	}
	return ans;
}
int solveall(){
	int ans=0;
	int maxi;
	int maxii;
	int cnta=0,cntb=0,cntc=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		maxi=max(x[i].a,max(x[i].b,x[i].c));
		if(maxi==x[i].a) cnta++;
		else if(maxi==x[i].b) cntb++;
		else cntc++;
		if(cnta==n/2){
			for(int j=1;j<=n;j++){
				int maxj=max(x[j].a,max(x[j].b,x[j].c));
				if(maxj==x[j].b or maxj==x[j].c){
					ans+=maxj;
				}else{
					cnt++;
					xa[cnt]=x[j];
					xa[cnt].del=xa[cnt].a-max(xa[cnt].b,xa[cnt].c);
				}
			}
			sort(xa+1,xa+cnt+1,cmp3);
			for(int j=1;j<=n/2;j++){
				ans+=xa[j].a;
			}
			for(int j=n/2+1;j<=cnt;j++){
				ans=ans+xa[j].a-xa[j].del;
			}
			return ans;
		}else if(cntb==n/2){
			for(int j=1;j<=n;j++){
				int maxj=max(x[j].b,max(x[j].a,x[j].c));
				if(maxj==x[j].a or maxj==x[j].c){
					ans+=maxj;
				}else{
					cnt++;
					xa[cnt]=x[j];
					xa[cnt].del=xa[cnt].b-max(xa[cnt].a,xa[cnt].c);
				}
			}
			sort(xa+1,xa+cnt+1,cmp3);
			for(int j=1;j<=n/2;j++){
				ans+=xa[j].b;
			}
			for(int j=n/2+1;j<=cnt;j++){
				ans=ans+xa[j].b-xa[j].del;
			}
			return ans;
		}else if(cntc==n/2){
			for(int j=1;j<=n;j++){
				int maxj=max(x[j].c,max(x[j].b,x[j].a));
				if(maxj==x[j].b or maxj==x[j].a){
					ans+=maxj;
				}else{
					cnt++;
					xa[cnt]=x[j];
					xa[cnt].del=xa[cnt].c-max(xa[cnt].b,xa[cnt].a);
				}
			}
			sort(xa+1,xa+cnt+1,cmp3);
			for(int j=1;j<=n/2;j++){
				ans+=xa[j].c;
			}
			for(int j=n/2+1;j<=cnt;j++){
				ans=ans+xa[j].c-xa[j].del;
			}
			return ans;
		}
	}
	for(int i=1;i<=n;i++){
		maxii=max(x[i].a,max(x[i].b,x[i].c));
		ans+=maxii;
	}
	return ans;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		spa=1;
		spb=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].b!=0) spa=0;
			if(x[i].c!=0){
				spa=0;
				spb=0;
			}
		}
		if(spa){
			cout<<sA()<<endl;
			continue;
		}
		if(spb){
			cout<<solveB()<<endl;
			continue;
		}
		cout<<solveall()<<endl;
	}
	return 0;
}
