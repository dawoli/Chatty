#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,num[100001],t,ext[100001],w[100001],wl;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d0",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		num[t]++;
		if(ext[t]==0){
			ext[t]++;
		}
	}
	int l=0,r=n;
	for(int i=0;i<100001;i++){
		if(ext[i]){
			w[wl]=num[i];
			wl++;
		}
	}
	sort(w,w+wl);
//	for(int i=0;i<5;i++){
//		cout<<w[i]<<endl;
//	}
	for(int i=0;i<wl-1;i++){
		l+=w[i];
		r-=w[i];
		if(w[i+1]>=l){
			l=0;
			w[i+1]-=l;
		}
		else{
			w[i+1]=0;
			l-=w[i+1];
		}
	}
	printf("%d",r);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//   5 1 2 3 1 2
