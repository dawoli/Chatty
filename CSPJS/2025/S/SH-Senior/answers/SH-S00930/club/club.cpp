#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005][5];
int dfs(int i,int anss,int n){
	if(i==n+1) return anss;
	int maxa=max(a[i][1],a[i][2]);
	maxa=max(maxa,a[i][3]);
	anss+=maxa;
	dfs(i+1,anss,n);
}
bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		
		cin>>n;
		int W=n/2;
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}

		//1
		if(n==2){
			int ans1=0;
			for(int i=1;i<=n;i++){
				int j;
				if(i==1||i==2) j=i+1;
				else j=1;
				if(i==1||i==3){
					ans1=max(ans1,a[1][i]+a[2][j]);
					ans1=max(ans1,a[1][i]+a[2][j+1]);
				}
				else if(i==2){
					ans1=max(ans1,a[1][i]+a[2][j]);
					ans1=max(ans1,a[1][i]+a[2][j-2]);
				}
			}
			cout<<ans1<<endl;
			continue;
		}
		
		//A
		int suma[100005];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(a[i][j]==0) suma[j]++;
			}
		}
		
		int f1=0,f2=0;
		for(int i=1;i<=3;i++){
			if(suma[i]!=0&&f1==0) f1=i;
			else if(suma[i]!=0&&f1!=0) f2=i;
		}

		if(f1!=0&&f2!=0){
			int f=0;
			for(int i=1;i<=3;i++){
				if(i!=f1&&i!=f2) f=i;
			}
			int ansa=0;
			int b[100005];
			for(int i=1;i<=n;i++){
				b[i]=a[i][f];
			}
			sort(b+1,b+1+n,cmp);
			
			for(int i=1;i<=W;i++){
				ansa+=b[i];
			}
			cout<<ansa;
			
			continue;
		}
		
		//Ì°ÐÄ
		cout<<dfs(1,0,n)<<endl;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
