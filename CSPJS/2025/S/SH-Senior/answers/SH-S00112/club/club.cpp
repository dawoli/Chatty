#include<bits/stdc++.h>
using namespace std;
int a[100002][4];
struct Node{
	int a,b,c;
	int maxval;
	int maxtyp;
	int sedval;
	int sedtyp;
}aa[100002];
bool cmp(Node a,Node b){
	if(a.maxval!=b.maxval){
		return a.maxval>b.maxval;
	}else{
		return a.sedval>b.sedval;
	}
	
}
int maxx=0;
int n;
void dfs(int x,int i,int j,int k,int value){
	if(x==n+1){
		maxx=max(maxx,value);
		return ;
	}
	if(i<n/2)
		dfs(x+1,i+1,j,k,value+a[x][1]);
		
	if(j<n/2)
		dfs(x+1,i,j+1,k,value+a[x][2]);
		
	if(k<n/2)
		dfs(x+1,i,j,k+1,value+a[x][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		maxx=0;
		cin>>n;
		if(n>=1e5){
				for(int i=1;i<=n;i++){
				cin>>aa[i].a>>aa[i].b>>aa[i].c;
				aa[i].maxval=max(aa[i].a,max(aa[i].b,aa[i].c));
				if(aa[i].a>=aa[i].b&&aa[i].a>=aa[i].c){
					aa[i].maxtyp=1;
					if(aa[i].b>=aa[i].c){
						aa[i].sedval=aa[i].b;
						aa[i].sedtyp=2;
					}else{
						aa[i].sedval=aa[i].c;
						aa[i].sedtyp=3;
					}
				}else if(aa[i].b>=aa[i].a&&aa[i].b>=aa[i].c){
					aa[i].maxtyp=2;
					if(aa[i].a>=aa[i].c){
						aa[i].sedval=aa[i].a;
						aa[i].sedtyp=1;
					}else{
						aa[i].sedval=aa[i].c;
						aa[i].sedtyp=3;
					}
				}else{
					aa[i].maxtyp=3;
					if(aa[i].a>=aa[i].b){
						aa[i].sedval=aa[i].a;
						aa[i].sedtyp=1;
					}else{
						aa[i].sedval=aa[i].b;
						aa[i].sedtyp=2;
					}
				}
			}
			long long ans[4]={};
			long long cnt[4]={};
			sort(aa+1,aa+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(cnt[aa[i].maxtyp]<n/2){
					cnt[aa[i].maxtyp]++;
					ans[aa[i].maxtyp]+=aa[i].maxval;
				}else{
					cnt[aa[i].sedtyp]++;
					ans[aa[i].sedtyp]+=aa[i].sedval;
				}
			}
			long long anss=0;
			for(int i=1;i<=3;i++){
				anss+=ans[i];
			}
			cout<<anss<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0,0,0,0);
		cout<<maxx<<endl;
	}
	return 0;
}

