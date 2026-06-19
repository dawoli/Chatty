#include<bits/stdc++.h>
using namespace std;
ifstream fin("club.in");
ofstream fout("club.out");
int n;
int fa[100005];
int a[100005][5];
int b1[100005],b2[100005];
int num1,num2;
map<pair<int,pair<int,int>>,long long> f;
bool cmp1(int x,int y){
	return a[x][1]<a[y][1];
}
bool cmp2(int x,int y){
	return a[x][2]<a[y][2];
}
long long dfs(int i,int n1,int n2,int n3){
	if(i==n+1){return 0;}
	if(f[{i,{n1,n2}}]> 0) return f[{i,{n1,n2}}];
	long long res=0;
	if(n1<n/2){
		res=max(res,dfs(i+1,n1+1,n2,n3)+a[i][1]);
	}
	if(n2<n/2){
		res=max(res,dfs(i+1,n1,n2+1,n3)+a[i][2]);
	}
	if(n3<n/2){
		res=max(res,dfs(i+1,n1,n2,n3+1)+a[i][3]);
	}
	return f[{i,{n1,n2}}]=res;
}
void solve(){
	fin>>n;
	f.clear();
	int flaga=1,flagb=1;
	for(int i=1;i<=n;++i){
		fin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]!=0 or a[i][3]!=0){
			flaga=0;
		}
		if(a[i][3]!=0){
			flagb=0;
		}
	}
	if(flaga==1){
		for(int i=1;i<=n;++i){
			fa[i]=a[i][1];
		}
		sort(fa+1,fa+n+1);
		long long ans=0;
		for(int i=n;i>n/2;--i){
			ans+=fa[i];
		}
		fout<<ans<<"\n";
	}
	else if(flagb==1 and false){
		num1=num2=0;
		for(int i=1;i<=n;++i){
			if(a[i][1]>a[i][2]){
				num1++;
				b1[num1]=i;
			}
			else{
				num2++;
				b2[num2]=i;
			}
		}
		sort(b1+1,b1+num1+1,cmp1);
		sort(b2+1,b2+num2+1,cmp2);
		long long ans=0;
		for(int i=1;i<=min(num1,n/2);++i){
			ans+=a[b1[i]][1];
		}
		for(int i=1;i<=min(num2,n/2);++i){
			ans+=a[b2[i]][2];
		}
		for(int i=n/2+1;i<=num1;++i){
			ans+=a[b1[i]][2];
		}
		for(int i=n/2+1;i<=num2;++i){
			ans+=a[b2[i]][1];
		}
		cout<<ans<<"\n";
	}
	else fout<<dfs(1,0,0,0)<<"\n";
}
int t;
int main(){
	fin>>t;
	for(int i=1;i<=t;++i){
		solve();
	}
}

