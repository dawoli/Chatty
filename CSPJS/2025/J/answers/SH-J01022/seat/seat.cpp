#include<bits/stdc++.h>
using namespace std;
int p[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,cnt=1,ms;
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>p[i];
		if(i==1){
			ms=p[i];
		}
		if(p[i]>ms){
			cnt++;
		}
	}
	int mi;
	if(cnt%m==0){
		mi=cnt/m;
	}
	else{
		mi=cnt/m+1;
	} 
	if(mi%2==1){
		if(cnt%m==0){
			cout<<mi<<' '<<m;
		}
		else{
			cout<<mi<<' '<<cnt%m;
		}
	}
	else{
		if(cnt%m==0){
			cout<<mi<<' '<<1;
		}
		else{
			cout<<mi<<' '<<m-cnt%m+1;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
