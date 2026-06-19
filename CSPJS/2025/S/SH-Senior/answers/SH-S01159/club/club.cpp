#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}f[100009];
int cmp(node x,node y){
	return x.a>y.a;
}
int k[100009],now=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<=100008;i++) f[i].a=f[i].b=f[i].c=k[i]=0;
		now=0;
		int n;
		cin>>n;
		int flag=0,flag2=0;
		for(int i=1;i<=n;i++){
			cin>>f[i].a>>f[i].b>>f[i].c;
			if(f[i].b!=0||f[i].c!=0) flag=1;
			if(f[i].c!=0) flag2=1;
		}
		if(n==2) cout<<max(max(f[1].a+f[2].b,f[1].a+f[2].c),max(max(f[1].b+f[2].a,f[1].b+f[2].c),max(f[1].c+f[2].a,f[1].c+f[2].b)));
		if(!flag){
			sort(f+1,f+1+n,cmp);
			long long cnt=0;
			for(int i=1;i<=n/2;i++) cnt+=f[i].a;
			cout<<cnt<<endl;
		}
		if(!flag2&&flag){
			long long cnt1=0,cnt2=0,cnt3=0;
			long long cnt=0;
			for(int i=1;i<=n;i++){
				if(f[i].a>f[i].b){
					cnt+=f[i].a;
					cnt1++;
				}
				else if(f[i].a<f[i].b){
					cnt+=f[i].b;
					cnt2++;
				}
				else{
					cnt+=f[i].b;
					cnt3++;
				}
			}
			if(cnt1<=n/2&&cnt2<=n/2){
				cout<<cnt<<endl;
			}
			if(cnt1<n/2){
				cnt1+=cnt3;
				int x=n/2-cnt1;
				for(int i=1;i<=n;i++){
					if(f[i].a<f[i].b){
						now++;
						k[now]=f[i].b-f[i].a;
					}
				}
				sort(k+1,k+1+now);
				for(int i=1;i<=x;i++) cnt-=k[i];
				cout<<cnt<<endl;
			}
			if(cnt2<n/2){
				cnt2+=cnt3;
				int x=n/2-cnt2;
				for(int i=1;i<=n;i++){
					if(f[i].a>f[i].b){
						now++;
						k[now]=f[i].a-f[i].b;
					}
				}
				sort(k+1,k+1+now);
				for(int i=1;i<=x;i++) cnt-=k[i];
				cout<<cnt<<endl;
			}
		} 
	}
	return 0;
}
