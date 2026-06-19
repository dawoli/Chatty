#include<bits/stdc++.h>
#define N 100005
using namespace std;

int a[N],b[N],c[N],tmpx,maxn=-1,s[N];

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
		b[a[i]]++;
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=maxn;++i){
		if(b[i]!=0)
			c[tmpx++]=b[i];
	}
	for(int i=0;i<tmpx;++i){
		s[i]=s[i-1]+c[i];
	}
	for(int i=1;i<n;++i){
		s[i-1]-=c[i];
		for(int j=i;j<n;++j){
			s[j]=s[j-1]+c[j];
		}
	}
	cout<<s[n-1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
