#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[100010];int a1[100010];
int c[100010];
string s[20];
mt19937 rnd(time(NULL));
signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a1[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	int k=0;
	while(1){
		if((1<<k)>=n){
			break;
		}
		k++;
	}
	for(int i=1;i<=k;i++){
		cin>>s[i];
	}
	int T;
	cin>>T;
	int need[100010];
	int A=1;
	for(int i=1;i<=m;i++){
		int bei=0;
		while(1){
			if((1<<bei)>=c[i]){
				if((1<<bei)!=c[i]){
					A=0;
				}
				break;
			}
			bei++;
		}
		need[i]=(1<<bei);
	}
	while(T--){
		int x[5];
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=n;i++){
			a[i]=a1[i]^(x[i%4]);
		}
		if(n<=8&&m<=8){
			int ans=0;
			for(int i=1;i<=m;i++){
				int poss[10];
				memset(poss,0,sizeof(poss));
				if(c[i]==1){
					ans^=i;
					continue;
				}
				int p[10];
				for(int j=1;j<=c[i];j++){
					p[j]=a[j];
				}
				int times=10000;
				while(times--){
					for(int j=c[i]+1;j<=need[i];j++){
						p[j]=(long long)rnd()%4;
					}
					int totr=0;
					if(need[i]==2){
						totr=1;
					}else if(need[i]==4){
						totr=2;
					}else{
						totr=3;
					}
					int ok[10];
					memset(ok,0,sizeof(ok));
					for(int r=1;r<=totr;r++){
						int p1=1,p2=1+(1<<(r-1));
						for(int j=0;j<s[r].size();j++){
							//cout<<p1<<"p"<<p2<<endl;
							int a1,a2;
							for(int k=p1;k<p2;k++){
								if(ok[k]==0){
									a1=k;
									break;
								}
							}
							for(int k=p2;;k++){
								if(ok[k]==0){
									a2=k;
									break;
								}
							}
							if(s[r][j]=='0'){
								if(p[a1]>=r){
									ok[a2]=1;
								}else{
									ok[a1]=1;
								}
							}else{
								if(p[a2]>=r){
									ok[a1]=1;
								}else{
									ok[a2]=1;
								}
							}
							p1+=(1<<(r));
							p2+=(1<<(r));
						}
					}
					for(int j=1;j<=need[i];j++){
						if(ok[j]==0){
							poss[j]=1;
							break;
						}
					}
				}
				int tot=0;
				for(int j=1;j<=need[i];j++){
					if(poss[j]){
						//cout<<j<<"OK";
						tot+=j;
					}
				}
				//cout<<endl;
				ans^=tot*i;
			}
			cout<<ans<<endl;
		}else{
			if(A){
				int ans=0;
				for(int i=1;i<=m;i++){
					if(need[i]==1){
						ans^=i;
						continue;
					}
					int totr=1;
					int curbei=2;
					while(1){
						if(need[i]==curbei){
							break;
						}
						curbei*=2;
						totr++;
					}
					int ok[1010];
					int poss[1010];
					memset(poss,0,sizeof(poss));
					memset(ok,0,sizeof(ok));
					for(int r=1;r<=totr;r++){
						int p1=1,p2=1+(1<<(r-1));
						for(int j=0;j<s[r].size();j++){
							//cout<<p1<<"p"<<p2<<endl;
							int a1,a2;
							for(int k=p1;k<p2;k++){
								if(ok[k]==0){
									a1=k;
									break;
								}
							}
							for(int k=p2;;k++){
								if(ok[k]==0){
									a2=k;
									break;
								}
							}
							if(s[r][j]=='0'){
								if(a[a1]>=r){
									ok[a2]=1;
								}else{
									ok[a1]=1;
								}
							}else{
								if(a[a2]>=r){
									ok[a1]=1;
								}else{
									ok[a2]=1;
								}
							}
							p1+=(1<<(r));
							p2+=(1<<(r));
						}
					}
					for(int j=1;j<=need[i];j++){
						if(ok[j]==0){
							poss[j]=1;
							break;
						}
					}
					int tot=0;
					for(int j=1;j<=need[i];j++){
						if(poss[j]){
							tot+=j;
						}
					}
					ans^=(tot*i);
				}
				cout<<ans<<endl;
			}else{
				int ans=0;
			for(int i=1;i<=m;i++){
				int poss[510];
				memset(poss,0,sizeof(poss));
				if(c[i]==1){
					ans^=i;
					continue;
				}
				int p[510];
				for(int j=1;j<=c[i];j++){
					p[j]=a[j];
				}
				int times=10000;
				while(times--){
					for(int j=c[i]+1;j<=need[i];j++){
						p[j]=(long long)rnd()%4;
					}
					int totr=0;
					if(need[i]==2){
						totr=1;
					}else if(need[i]==4){
						totr=2;
					}else{
						totr=3;
					}
					int ok[510];
					memset(ok,0,sizeof(ok));
					for(int r=1;r<=totr;r++){
						int p1=1,p2=1+(1<<(r-1));
						for(int j=0;j<s[r].size();j++){
							//cout<<p1<<"p"<<p2<<endl;
							int a1,a2;
							for(int k=p1;k<p2;k++){
								if(ok[k]==0){
									a1=k;
									break;
								}
							}
							for(int k=p2;;k++){
								if(ok[k]==0){
									a2=k;
									break;
								}
							}
							if(s[r][j]=='0'){
								if(p[a1]>=r){
									ok[a2]=1;
								}else{
									ok[a1]=1;
								}
							}else{
								if(p[a2]>=r){
									ok[a1]=1;
								}else{
									ok[a2]=1;
								}
							}
							p1+=(1<<(r));
							p2+=(1<<(r));
						}
					}
					for(int j=1;j<=need[i];j++){
						if(ok[j]==0){
							poss[j]=1;
							break;
						}
					}
				}
				int tot=0;
				for(int j=1;j<=need[i];j++){
					if(poss[j]){
						//cout<<j<<"OK";
						tot+=j;
					}
				}
				//cout<<endl;
				ans^=tot*i;
			}
			cout<<ans<<endl;
			}
		}
	}
}
