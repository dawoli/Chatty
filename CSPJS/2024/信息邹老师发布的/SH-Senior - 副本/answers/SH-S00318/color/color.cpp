#include<bits/stdc++.h>
using namespace std;
int T,n[11],A[11][16],ans[11];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	int cnt=T;
	while(T>0){
		cin>>n[cnt-T];
		int e[16]={};
		for(int i=0;i<n[cnt-T];++i){
			cin>>A[cnt-T][i];
			int cnt1=A[cnt-T][i];
			e[cnt1]=e[cnt1]+1;
		}
		for(int i=0;i<16;++i){
			if(e[i]!=0)
				ans[cnt-T]+=(A[cnt-T][i]*(e[i]-1)*e[i])/2;
		}
		T--;
	}
	for(int i=0;i<T;++i)
		cout<<ans[i]<<endl;
	return 0;
}
