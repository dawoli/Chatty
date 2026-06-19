#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n;
int a[N];
int lef,ans;
int f[N];
void input(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		f[a[i]]++;
	}
}
void count(){
	for(int i=100000;i>=1;i--){
		if(f[i]!=0){
			if(f[i]<=lef)
				lef-=f[i];
			else{
				ans+=f[i]-lef;
				lef=0;
			}
			lef+=f[i];
		}
	}
}
void output(){
	printf("%d",ans);
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	input(); 
	count();
	output();
	return 0;
}

