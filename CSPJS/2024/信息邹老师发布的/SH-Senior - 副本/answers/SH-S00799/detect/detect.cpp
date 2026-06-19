#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b) for(i = a;i < b;i++)

const int N = 1e5;

int forcnt,i,j,k;
int T;

int n,m,L,V,cnt,maxn;
int d[N],v[N],a[N],p[N];


int main(){
	freopen("detect1.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	f(forcnt,1,T+1){	
		scanf("%d %d %d %d",&n,&m,&L,&V);
		f(i,0,n){scanf("%d %d %d",&d[i],&v[i],&a[i]);if(d[i]>maxn)maxn = d[i];}
		for(int mid = n/2;mid >= 1;mid /= 2){
			f(j,0,mid){
				f(k,1,n/mid){
					int u = k;
					while(u>0 && d[u*mid+j] < d[(u-1)*mid+j]){
						int temp = d[u*mid+j];
						d[u*mid+j] = d[(u-1)*mid+j];
						d[(u-1)*mid+j] = temp;
						u--;
					}
				}
			}
		}
		f(i,0,m)scanf("%d",&p[i]);
		i = n;
		f(j,0,n){
			if(v[j]<=V){
				i--;
			}else if(p[m-1]<d[j]){
				i--;
			}
		}
		cout<<i<<" ";
		i = m-1;
		while(p[i]>=maxn){
			i--;
		}
		cout<<i<<endl;
	}
	return 0;
}
