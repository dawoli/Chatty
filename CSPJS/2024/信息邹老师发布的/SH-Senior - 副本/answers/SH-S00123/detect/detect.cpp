#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int T,n,m,L,V,s[1000005],a[1000005],p[1000005];
int dn[100005],vn[100005],an[100005],ans1,ans2;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		ans1=ans2=0;//多测清空 
		for(int i=0;i<=L;i++) s[i]=a[i]=0;//多测清空 
		for(int i=1;i<=n;i++) cin>>dn[i]>>vn[i]>>an[i];
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		for(int i=1;i<=n;i++){//前缀和预处理 
			int d=dn[i],v=vn[i],a=an[i];
			int cnt=0;//被多少机器检测到 
			int l=-1,r=-1;//若超速，起止位置 
			if(a==0){//匀速行驶且超速(省去匀速行驶且未超速)
				if(v>V) l=d,r=L+1;
			}
			else{//匀加速行驶 
				int S=d+(V*V-v*v)/(2*a);
//				cout<<S<<endl;
				if(S*2*a!=d+V*V-v*v&&a>0){//S精度微调 
					S++;
				}
				if(S<d){//超速且在加速（省去未超速且在减速） 
					if(a>0) l=d,r=L;
				}
				else if(S>L){//超速且在减速（省去未超速且在加速） 
					if(a<0) l=d,r=L;
				}
				else{
					if(a<0){//超速但在减速 
						l=d,r=S-1;
					} 
					else{//未超速但在加速
						l=S+1,r=L;
					} 
				}
			}
			if(l!=-1&&r!=-1){
				int uni;
				for(int j=1;j<=m;j++){//i车j机器 
					if(p[j]>=l&&p[j]<=r){
						if(cnt==0){
							ans1++;
						}
						cnt++;
						uni=j;
					}
				}
			}
			s[l]++,s[r+1]--;
		}
		for(int i=1;i<=L;i++){
			a[i]=a[i-1]+s[i];
//			cout<<a[i]<<" ";
		}
		cout<<ans1<<" "<<ans1<<endl;//ans2不会做…… 
	}
	return 0;
}
/*1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15*/
