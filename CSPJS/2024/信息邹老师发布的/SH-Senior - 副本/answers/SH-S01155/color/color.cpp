#include<bits/stdc++.h>
using namespace std;
int mr(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0'; 
		ch=getchar();
	}
	return x;
}
const int N=1e5+5,M=1e6+5; 
int n,a[N],la[N],vis[M],f[N][N];
priority_queue<int>q[2];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i]=mr();
		vis[a[i]]=min(vis[i],i); 
	}
	for(int i=1;i<=n;i++){
		la[i]=vis[i];
		vis[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				
			}
		}
	}
}
int main(){
	int T;
	cin>>T;
	while(T--)cout<<0;
} 
