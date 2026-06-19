#include <bits\stdc++.h>
using namespace std;
const int N=1e5+10;
struct newnum{
	int cla,clb,clc;
};
int ans=0;
newnum a[N];
bool cmp(newnum a,newnum b){
	if(a.cla>b.cla){
		return 1; 
	} else if(a.cla==b.cla){
		if(a.clb>b.clb){
			return 1;
		} else if(a.clb==b.clb){
			if(a.clc>b.clc){
				return 1;
			}
			else{
				return 0;
			}
		}
		else{
			return 0;
		}
	}
	return 0;
}
int check(int i,int oka,int okb,int okc){
	int g,c,d;
	if(a[i].cla>a[i].clb&&oka){
		if(a[i].cla>a[i].clc||!okc){
			ans+=a[i].cla;
			return 1;
		}
		else{
			ans+=a[i].clc;
			return 3;
		}
	}
	else if(!okb){
		if(a[i].cla>a[i].clc||!okc){
			ans+=a[i].cla;
			return 1;
		}
		else{
			ans+=a[i].clc;
			return 3;
		}
	}
	else{
		if(a[i].clb>a[i].clc||!okc){
			ans+=a[i].clb;
			return 2;
		}
		else{
			ans+=a[i].clc;
			return 3;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].cla>>a[i].clb>>a[i].clc; 
		} 
		sort(a+1,a+n+1,cmp);
		ans=0;
		int cnta=0;
		int cntb=0;
		int cntc=0; 
		for(int i=1;i<=n;i++){
			int x=0;
			if(cnta<=n/2){
				if(cntb<=n/2){
					if(cntc<=n/2){
						int kow=check(i,1,1,1);
						if(kow==1) cnta++;
						if(kow==2) cntb++;
						if(kow==3) cntc++;
					}
					else{
						int kow=check(i,1,1,0);
						if(kow==1) cnta++;
						if(kow==2) cntb++;
						if(kow==3) cntc++;
					}
				}
				else{
					if(cntc<=n/2){
						int kow=check(i,1,0,1);
						if(kow==1) cnta++;
						if(kow==2) cntb++;
						if(kow==3) cntc++;
					}
					else{
						int kow=check(i,1,0,0);
						if(kow==1) cnta++;
						if(kow==2) cntb++;
						if(kow==3) cntc++;
					}
				}
			}
			else{
				if(cntb<=n/2){
					if(cntc<=n/2){
						int kow=check(i,0,1,1);
						if(kow==1) cnta++;
						if(kow==2) cntb++;
						if(kow==3) cntc++;
					}
					else{
						int kow=check(i,0,1,0);
						if(kow==1) cnta++;
						if(kow==2) cntb++;
						if(kow==3) cntc++;
					}
				}
				else{
					if(cntc<=n/2){
						int kow=check(i,0,0,1);
						if(kow==1) cnta++;
						if(kow==2) cntb++;
						if(kow==3) cntc++;
					}
					else{
						int kow=check(i,0,0,0);
						if(kow==1) cnta++;
						if(kow==2) cntb++;
						if(kow==3) cntc++;
					}
				}
			}
//			ans+=max(a[i].cla,max(a[i].clb,a[i].clc));
//			cout<<a[i].cla<< b" " <<a[i].clb<<" "<<a[i].clc<<endl;
			a[i].cla=0;
			a[i].clb=0;
			a[i].clc=0;
			
		}
		cout<<ans<<endl; 
	}
	return 0;
} 
