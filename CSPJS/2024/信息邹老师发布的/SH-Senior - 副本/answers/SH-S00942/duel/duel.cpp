#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,ans;
int r[maxn],atk[maxn];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
bool cmp(int a,int c){
	return a<c;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	memset(atk,1,sizeof(atk));
	n=read();
	ans=n;
	for(int i=1;i<=n;i++) r[i]=read();
	sort(r+1,r+1+n,cmp);
	for(int i=1;i<n;i++){
		int j=i+1;
		while((r[j]<=r[i] || atk[j]==0) && j<n) j++;
		if(r[j]>r[i]){
			if(atk[j]){
				ans--;
				atk[j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
