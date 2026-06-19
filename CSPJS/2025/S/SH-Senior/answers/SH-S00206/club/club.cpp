#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,T;
const int N=1e5+5;
struct pe{
	int m[4];
	int r[4];
	int c12,c23;
	int f;
}d[N];
int num[4];
int ans=0;
bool cmp1(pe a,pe b){
	return a.c12>b.c12;
}
bool cmp2(pe a,pe b){
	return a.c23>b.c23;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		num[1]=0;
		num[2]=0;
		num[3]=0;
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			d[i].f=0;
			for(int j=1;j<=3;j++){
				scanf("%d",&d[i].m[j]);
			}
				if(d[i].m[1]>=d[i].m[2] && d[i].m[1]>=d[i].m[3]){
						d[i].r[1]=1;
						if(d[i].m[2]>d[i].m[3]){
							d[i].r[2]=2;
							d[i].r[3]=3;
						}
						else{
							d[i].r[3]=2;
							d[i].r[2]=3;
						}
				}
				else if(d[i].m[2]>=d[i].m[1] && d[i].m[2]>=d[i].m[3]){
					d[i].r[1]=2;
					if(d[i].m[1]>d[i].m[3]){
						d[i].r[2]=1;
						d[i].r[3]=3;
					}
					else{
						d[i].r[3]=1;
						d[i].r[2]=3;
					}
				}
				else{
					d[i].r[1]=3;
					if(d[i].m[1]>d[i].m[2]){
						d[i].r[2]=1;
						d[i].r[3]=2;
					}
					else{
						d[i].r[3]=1;
						d[i].r[2]=2;
					}
				}
				d[i].c12=d[i].m[d[i].r[1]]-d[i].m[d[i].r[2]];
				d[i].c23=d[i].m[d[i].r[2]]-d[i].m[d[i].r[3]];
		}
		sort(d+1,d+n+1,cmp1);
		
		for(int i=1;i<=n;i++){
			int rn1=d[i].r[1];
			int rn2=d[i].r[2];
			int rn3=d[i].r[3];
			if(num[rn1]==(n/2)){
				continue;
			}
			ans+=d[i].m[rn1];
			num[rn1]++;
			d[i].f=1;	
		//	cout<<i;
		}
		for(int i=1;i<=n;i++){
			int rn1=d[i].r[1];
			int rn2=d[i].r[2];
			int rn3=d[i].r[3];
			if(num[rn2]==(n/2) or d[i].f){
				continue;
			}
			ans+=d[i].m[rn2];
			num[rn2]++;
			d[i].f=1;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
