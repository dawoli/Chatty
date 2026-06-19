#include<bits/stdc++.h>
using namespace std;
int score[109];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>score[i];
	}
	int aa=score[1];int jj=1;
	sort(score+1,score+n*m+1);
	for(int j=n*m;j>=1;j--){
		if(score[j]==aa){
			jj=n*m-j+1;break;
		}
	}
	if(jj%m==0){
		int kk=jj/m;
		if(kk%2==0){
			cout<<kk<<" "<<1;
		}
		else{
			cout<<kk<<" "<<n;
		}
	}
	else{
		int kk=jj/m+1;
		if(kk%2==0){
			cout<<kk<<" "<<(n-jj%m+1);
		}
		else{
			cout<<kk<<" "<<(jj%m);
		}
	}
	return 0;
} 
