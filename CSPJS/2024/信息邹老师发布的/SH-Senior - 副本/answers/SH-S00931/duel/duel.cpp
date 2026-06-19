#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a;
long long la,sa=1;
int t[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}sort(t+1,t+1+n);
	for(int i=2;i<=n;i++){
		//cout<<t[i]<<la<<" "<<sa<<endl;
		if(t[i]==t[i-1]&&la==0){
			sa++;
			continue;
		}
		if(t[i]==t[i-1]&&la>0){
			la--;
			sa++;
			continue;
		}
		if(t[i]>t[i-1]){//大于时la
			la+=sa;
			sa=1;
			if(la>0) la=la-1;//死了 
		}else if(la==0)sa++;
	}cout<<la+sa;
	return 0;
}/* 10
136 136 136 2417 136 136 2417 136 136 136

 5
1 2 3 1 2*/
