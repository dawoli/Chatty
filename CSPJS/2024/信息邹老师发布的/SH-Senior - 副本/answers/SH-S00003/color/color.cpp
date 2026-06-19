#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int n;
int a[200010];
vector<int>vec[1000010];
int vpos[1000010];
pair<int,int> duan[1000010];
int pos;
int col[200010];
mt19937 rnd(time(NULL));
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(n<=15){
			int ans=0;
			for(int i=0;i<(1<<n);i++){
				int base=1,col[16];
				for(int j=1;j<=n;j++){
					if(base&i){
						col[j]=1;
					}else{
						col[j]=0;
					}
					base*=2;
				}
				int cur=0;
				for(int j=1;j<=n;j++){
					int have=0,num=0;
					for(int k=j-1;k>=1;k--){
						if(col[k]==col[j]){
							have=1;
							num=a[k];
							break;
						}
					}
					if(have&&num==a[j]){
						cur+=a[j];
					}
				}
				ans=max(ans,cur);
			}
			printf("%lld\n",ans);
		}else if(n<=100){/*
			memset(vpos,-1,sizeof(vpos));
			for(int i=1;i<=n;i++){
				vec[a[i]].push_back(i);
			}*/
			int st=clock();
			int ans=0;
			int tmp=0;
			for(int i=2;i<=n;i++){
				if(a[i]==a[i-1]){
					tmp+=a[i];
				}
			}
			ans=tmp;
			int maxseed=0;
			int tmes=1000;
			while(tmes--){
				for(int i=1;i<=n;i++){
					if(a[i]==a[i-1]){
						col[i]=col[i-1];
					}else if(a[i]==a[i-2]){
						col[i]=col[i-2];
					}else{
						col[i]=rnd()%2;	
					}
				}
				int curmax=0;
				for(int i=1;i<=n;i++){
					for(int j=i-1;j>=1;j--){
						if(col[j]==col[i]){
							if(a[j]==a[i]){
								curmax+=a[j];
							}
							break;
						}
					}
				}	
				maxseed=max(maxseed,curmax);
			}
			while(clock()-st<=(0.7/10)*CLOCKS_PER_SEC){
				//int seed=1+10000000/(n*n);
				while(clock()-st<=(0.7/10)*CLOCKS_PER_SEC){
					for(int i=1;i<=n;i++){
						if(a[i]==a[i-1]){
							col[i]=col[i-1];
						}else if(a[i]==a[i-2]){
							col[i]=col[i-2];
						}else{
							col[i]=rnd()%2;	
						}
					}
					int curmax=0;
					for(int i=1;i<=n;i++){
						for(int j=i-1;j>=1;j--){
							if(col[j]==col[i]){
								if(a[j]==a[i]){
									curmax+=a[j];
								}
								break;
							}
						}
					}
					if(curmax<maxseed-1000)continue;
					maxseed=max(maxseed,curmax);
					//cout<<curmax<<"a"<<endl;
					int times=n,lastmax=n;
					while(times--){
						if(lastmax-times>=10){
							break;
						}
						int maxn=0,maxp=0;
						for(int i=1;i<=n;i++){
							int orgi=col[i],orgim1=col[i-1],orgim2=col[i-2],orgip1=col[i+1];
							if(a[i]==a[i-1]){
								col[i]=1-col[i];
								col[i-1]=col[i];
							}else if(a[i]==a[i-2]){
								col[i]=1-col[i];
								col[i-2]=col[i];
							}else{
								col[i]=rnd()%2;	
							}
							int cur=0;
							for(int k=1;k<=n;k++){
								for(int j=k-1;j>=1;j--){
									if(col[j]==col[k]){
										if(a[j]==a[k]){
											cur+=a[k];
										}
										break;
									}
								}
							}
							if(cur>maxn){
								maxn=cur;
								maxp=i;
							}
							col[i]=orgi;
							col[i-1]=orgim1;
							col[i-2]=orgim2;
							col[i+1]=orgip1;
						}
						if(a[maxp]==a[maxp-1]){
							col[maxp]=1-col[maxp];
							col[maxp-1]=col[maxp];
						}else if(a[maxp]==a[maxp-2]){
							col[maxp]=1-col[maxp];
							col[maxp-2]=col[maxp];
						}else{
							col[maxp]=rnd()%2;	
						}
						if(maxn>curmax){
							curmax=maxn;
							lastmax=times;
						}
						ans=max(ans,maxn);
					}
					ans=max(ans,curmax);
				}
			}
			printf("%lld\n",ans);
			/*
			pos=0;
			for(int i=1;i<=n;i++){
				if(vpos[a[i]]==-1){
					vpos[a[i]]=0;
					continue;
				}else{
					int to=vpos[a[i]];
					duan[++pos]={to,i};
					vpos[a[i]]++;
				}
			}
			sort(duan+1,duan+pos+1);
			if(pos==0){
				printf("%lld\n",0);
				for(int i=1;i<=n;i++){
					vec[a[i]].pop_back();
				}
				continue;
			}
			for(int i=1;i<=n;i++){
				vec[a[i]].pop_back();
			}*/
		}else{
			for(int i=2;i<=n;i++){
				if(a[i]==a[i-1]){
					tmp+=a[i];
				}
			}
			ans=tmp;
			cout<<ans<<endl;
		}
	}
}
/*
3
15
5 3 7 2 4 13 11 6 5 5 3 5 12 8 13
15
1 12 11 11 7 11 15 6 4 6 3 15 7 5 2
100
17 18 18 19 17 19 20 20 18 19 18 19 18 19 19 19 18 17 19 17 40 40 40 37 40 39 39 39 38 39 38 40 37 40 38 40 38 39 39 40 59 60 58 60 59 58 59 58 60 57 58 60 57 60 57 60 58 60 57 60 80 80 79 80 78 77 80 79 79 80 79 79 79 77 80 77 77 80 80 78 100 100 98 97 97 99 98 99 100 99 100 98 98 99 98 98 100 100 97 98
*/
