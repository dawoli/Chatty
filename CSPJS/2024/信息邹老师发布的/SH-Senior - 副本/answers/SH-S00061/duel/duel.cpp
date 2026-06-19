#include<bits/stdc++.h>
using namespace std;
int n,r[100000],k[100000],ik,m;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&r[i]);
	}
	sort(r,r+n,cmp);
	k[0]=r[0];ik++;
	for(int j=1;j<n;j++){
		m=ik-1;
		while(k[m]>=r[j]&&m>=0){
			m--;
		}
		if(m>=0){
			k[m]=r[j];
		}
		
		else k[ik++]=r[j];
		
	}
	printf("%d",ik);
	return 0;
}
