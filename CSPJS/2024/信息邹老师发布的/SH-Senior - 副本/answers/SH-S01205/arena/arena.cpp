#include<iostream>
#include<string>
using namespace std;
#define N 100005
int T,n,m,a[N],ta[N],c[N],x[5],ans;
char k[25][N];
int solve(int p[],int r,int q){
	if(q==1){
		return p[1];
	}
	int na[N];
	for(int i=1;i<=q/2;i++){
		if(k[r][i]==0){
			na[i]=p[2*i-1]>=r?p[2*i-1]:p[2*i];
		}else{
			na[i]=p[2*i]>=r?p[2*i]:p[2*i-1];
		}
	}
	return solve(na,r+1,q/2);
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	for(int i=1;(1<<(i-1))<n;i++){
		cin.getline(k[i],sizeof(k[i]));
	}
	cin>>T;
	for(int w=1;w<=T;w++){
		for(int i=1;i<=4;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			ta[i]=(a[i]^x[i]);
		}
		for(int i=1;i<=m;i++){
			ans=(ans^(i*(solve(ta,1,c[i]))));
		}
		cout<<int(ans)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
