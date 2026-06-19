#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int svv[N]={0},atb[N]={0};
int n,asw=0,mxc=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	asw=n;
	for(int i=0;i<n;i++){
		int c;
		cin>>c;
		mxc=max(c,mxc);
		svv[c]++;atb[c]++;
	}
	for(int i=1;i<=mxc;i++){
		for(int j=i+1;j<=mxc&&svv[i]!=0&&asw!=svv[i];j++){
			if(svv[j]!=0){
				if(atb[j]>=svv[i]){
					atb[j]-=svv[i];
					asw-=svv[i];
					svv[i]=0;atb[i]=0;
				}
				else{
					svv[i]-=atb[j];atb[i]-=atb[j];
					asw-=atb[j];
					atb[j]=0;
				}
			}
		} 
	}
	cout<<asw;
	return 0;
}

