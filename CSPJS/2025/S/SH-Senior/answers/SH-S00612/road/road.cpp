#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	cin>>n>>m>>k;
	int a[n][n]={0};
	int b[k*(n+1)];
	int w[m]={0};
	int ccnt=0;
	int pf=0;
	for(int i=0;i<m;i++){
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		a[aa][bb]=1;
		a[bb][aa]=1;
		w[cc]=cc;
	}
	for(int i=0;i<k*(n+1);i+=n+1){
		cin>>b[i];
		if(b[i]!=0) pf=1;
		for(int j=0;j<n;j++){
			cin>>b[j];
			if(b[j]!=0) pf=1;
		}
	}
	if(pf==0){
		cout<<0;
		return 0;
	}
	sort(w,w+m,cmp);
	for(int i=0;i<m;i++){
		ccnt+=w[i];
	}
	cout<<ccnt;
	return 0;
}
