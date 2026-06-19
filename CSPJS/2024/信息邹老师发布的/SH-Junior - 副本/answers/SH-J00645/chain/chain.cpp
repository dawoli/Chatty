#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
const int M=1e2+9;
struct Node{
    int id,nm,dp;
}f[M][N];
vector<int>num[N];
int t,n,m,k,l,x;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&k,&l);
        for(int i=1;i<=n;i++){
            scanf("%d",&m);
            for(int j=1;j<=m;j++){
                scanf("%d",&x);
                num[i].push_back(x);
            }
        }
        f[0][1]=(Node){0,1,0};
        for(int d=1;d<=100;d++){
            for(int i=1;i<=n;i++){
                int lst=-2*N;
                for(int j=0;j<num[i].size();j++){
                    x=num[i][j];
                    if(f[d-1][x].nm&&f[d-1][x].id!=i){
                    	lst=j;
					}else if(j-lst<k){
                        if(f[d][x].nm){
                            if(f[d][x].id!=i)f[d][x].id=0;
                        }else{
                            f[d][x]=(Node){i,1,0};
                        }
                    }
                }
            }
        }
        for(int i=1;i<=l;i++){
            int r,c;
            scanf("%d%d",&r,&c);
            printf("%d\n",f[r][c].nm);
        }
    }
	return 0;
}
