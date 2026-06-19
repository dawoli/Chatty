#include <bits/stdc++.h>
using namespace std;
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define foR(i,a,b) for(int i=a;i>=b;i--)
#define debug(s) //cout<<s<<'\n'

const int maxl=100006;

int t;
int n,a[4][maxl];
int best[maxl],snd[maxl],bv[maxl],dt[maxl];
int tdt[maxl],rdt[maxl],lb[4][maxl];
int low[10],p[10],lp[10];

signed cmp(const void *a, const void *b){
	return dt[*(int*)a]-dt[*(int*)b];
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	For(_i,1,t){
		//调了半天，原来忘记清空了… 
		cin>>n;
		For(i,1,3){
			For(j,1,n){
				lb[i][j]=0;
			}
			p[i]=0;
		} 
		For(i,1,n){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[1][i]>=a[2][i]&&a[2][i]>=a[3][i]){
				best[i]=1;
				snd[i]=2;
				bv[i]=a[1][i];
				dt[i]=a[1][i]-a[2][i];
			}
			else if(a[1][i]>=a[3][i]&&a[3][i]>=a[2][i]){
				best[i]=1;
				snd[i]=3;
				bv[i]=a[1][i];
				dt[i]=a[1][i]-a[3][i];
			}
			else if(a[2][i]>=a[3][i]&&a[3][i]>=a[1][i]){
				best[i]=2;
				snd[i]=3;
				bv[i]=a[2][i];
				dt[i]=a[2][i]-a[3][i];
			}
			else if(a[2][i]>=a[1][i]&&a[1][i]>=a[3][i]){
				best[i]=2;
				snd[i]=1;
				bv[i]=a[2][i];
				dt[i]=a[2][i]-a[1][i];
			}
			else if(a[3][i]>=a[1][i]&&a[1][i]>=a[2][i]){
				best[i]=3;
				snd[i]=1;
				bv[i]=a[3][i];
				dt[i]=a[3][i]-a[1][i];
			}
			else if(a[3][i]>=a[2][i]&&a[2][i]>=a[1][i]){
				best[i]=3;
				snd[i]=2;
				bv[i]=a[3][i];
				dt[i]=a[3][i]-a[2][i];
			}
			tdt[i]=i;
			debug("In "<<i<<": best="<<best[i]<<", snd="<<snd[i]<<", bv="<<bv[i]<<", dt="<<dt[i]);
		}
		//我为啥要写离散化啊……
		//算了懒得改了 
		qsort(tdt+1,n,sizeof(int),cmp);
		For(i,1,n){
			rdt[tdt[i]]=i;
		}
		debug("rdt");
		For(i,1,n){
			debug(rdt[i]);
		}
		debug("end rdt");
//		For each player:
//			if not best full:
//				assign best
//			else:
//				find full.low;
//				if current.dt>low.dt:
//					low.switch_to low.second;
//					assign best
//				else:
//					assign 2nd
		int val=0;
		For(i,0,5){
			low[best[i]]=200000;
		}
		For(i,1,n){
			int bi=best[i];
			debug("89: "<<bi<<' '<<p[bi]);
			if(p[bi]<n/2){
				p[bi]++;
				debug("SSSSSSSS");
				debug(i<<' '<<bi<<' '<<p[bi]);
				val+=bv[i];
				if(low[bi]>rdt[i]){
					low[bi]=rdt[i];
					lp[bi]=i;
					lb[bi][rdt[i]]++;
				}
			}
			else{
				debug(i<<" full trigger");
				debug(rdt[i]);
				debug(low[bi]);
				if(rdt[i]>low[bi]){
					debug("MAN");
					int lll=lp[bi];
					int fl=lp[bi];
					lb[bi][rdt[i]]++;
					val-=dt[lll];
					val+=bv[i];
					debug(val);
					// Find new low
					For(it,low[bi]+1,n){
						if(lb[bi][it]){
							lp[bi]=tdt[it];
							low[bi]=it;
							break;
						}
					}
				}
				else{
					val+=a[snd[i]][i];
				}
			}
		}
		cout<<val<<'\n';
		debug("==============================");
	}
	return 0;
}

