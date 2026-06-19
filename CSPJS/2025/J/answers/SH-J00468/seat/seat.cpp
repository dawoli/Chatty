#include<bits/stdc++.h>
using namespace std;
int n,m,score[105],myscor,mypai,wz=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>score[i];
	}
	myscor=score[1];
	sort(score+1,score+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			int j=1;
			for(;j<=n;j++){
				if(score[wz]==myscor){
					cout<<i<<" "<<j<<endl;
					break;
				}
				wz++;
			}
			if(j!=n+1)break;
		}
		else{
			int j=n;
			for(;j>=1;j--){
				if(score[wz]==myscor){
					cout<<i<<" "<<j<<endl;
					break;
				}
				wz++;
			}
			if(j!=0)break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
