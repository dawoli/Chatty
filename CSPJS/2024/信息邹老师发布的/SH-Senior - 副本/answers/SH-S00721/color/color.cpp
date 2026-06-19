#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 2e5+20;

int n;
int a[maxn];
int color[maxn]; //1blue 0red

long long f[maxn][10];

long long anss = 0;
void dfs(int x){
	if(x>n){
//		cout<<x<<" "<<color[x]<<" "<<anss<<endl;
//		for(int i=1;i<=n;i++) cout<<color[i]; cout<<endl;
		anss = max(f[x-1][1],anss);
		anss = max(f[x-1][2],anss);
		return;
	}
	for(int i=x-1;i>=1;i--){
		if(color[x]==color[i]){
			if(a[x]==a[i]){
//				cout<<"X I"<<x<<" "<<i<<endl;
				f[x][color[x]] += a[x];
			}
			break;
		}
	}
	color[x+1]=1;
	f[x+1][color[x+1]] = f[x][color[x]];
	dfs(x+1);
	if(x!=n){
		color[x+1]=0;
		f[x+1][color[x+1]] = f[x][color[x]];
		dfs(x+1);
	}
}

int main(){
//	cout<<"FREOPEN\n";
//	cout<<"SCANF\n";
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T; cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		color[1]=1; dfs(1);
		color[1]=0; dfs(1);
		cout<<anss<<endl;
		anss=0;
		for(int i=1;i<=n;i++){
			f[i][0]=f[i][1]=f[i][2]=0;
			color[i]=0;	
		}
	}
	return 0; 
}
