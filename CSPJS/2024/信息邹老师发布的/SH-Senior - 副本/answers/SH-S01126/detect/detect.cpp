#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
long long p1[maxn];//分子 起点 
long long q1[maxn];//分母 终点 
long long p2[maxn];//分子 起点 
long long q2[maxn];//分母 终点 
bool b1[maxn];//开闭区间，true=闭，false=开 
bool b2[maxn];
int d[maxn];//0=不超速，1=超速
int e[maxn];//是否被记录超速 
int pi[maxn];//摄像头的位置 
int main(){
	freopen("detect1.in","r",stdin);
	freopen("detect1.out","w",stdout);
	int t,n,m,l,v,di,vi,ai,sum,y;
	cin >> t;
	for(int i=0;i<t;i++){
		sum=0;
		cin >> n >> m >> l >> v;
		for(int j=0;j<n;j++){
			cin >> di >> vi >> ai;
			if(ai==0){
				if(vi>v){
					p1[j]=di;
					q1[j]=1;
					p2[j]=l;
					q2[j]=1;
					d[j]=1;
					b1[j]=true;
					b2[j]=true; 
				}else{
					d[j]=0;
				}
			}else if(ai<0){
				if(vi<=v){
					d[j]=0;
				}else{
					p2[j]=vi*vi-v*v-2*ai*di;
					q2[j]=-2*ai;
					y=__gcd(p2[j],q2[j]);
					p2[j]/=y;
					q2[j]/=y;
					p1[j]=di;
					q1[j]=1;
					d[j]=1;
					b1[j]=true;
					b2[j]=false; 
				}
			}else{
				if(vi>v){
					p1[j]=di;
					q1[j]=1;
					p2[j]=l;
					q2[j]=1;
					d[j]=1;
					b1[j]=true;
					b2[j]=true; 
				}else{
					p1[j]=v*v-vi*vi+2*ai*di;
					q1[j]=2*ai;
					y=__gcd(p1[j],q1[j]);
					p1[j]/=y;
					q1[j]/=y;
					p2[j]=l;
					q2[j]=1;
					d[j]=1;
					b1[j]=false;
					b2[j]=true;
				}
			}
		}
		for(int j=0;j<m;j++){
			cin >> pi[j];
			for(int k=0;k<n;k++){
				if(d[k]==1){
					if((p1[k]<pi[j]*q1[k] || (b1[k] && p1[k]==pi[j]*q1[k]))&&(pi[j]*q2[k]<p2[k] || (b2[k] && pi[j]*q2[k]==p2[k]))){
						if(e[k]==0){
							sum++;
							e[k]=1;
						}
					}
				}
			}
		}
		cout << sum << ' ';
		cout << m-1 << endl;
	}
	return 0;
}
