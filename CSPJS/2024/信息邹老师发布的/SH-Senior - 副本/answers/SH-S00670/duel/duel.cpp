#include<bits/stdc++.h>
using namespace std;
int cd[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n=0,i,cntl=1,ans=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>cd[i];
	}
	sort(cd,cd+n);
	int l=cd[0],m=0;
	for(i=1;i<n;i++){
		if(cd[i]<=l){
			cntl++;
		}
		else{
			if(cntl>0){
				cntl--;
				ans++;
			}
			if(cntl==0){
				l=cd[ans];
				cntl++;
			}
		}
	}
	cout<<n-ans<<endl;
	return 0;
} 
