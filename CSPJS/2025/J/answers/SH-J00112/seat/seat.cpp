#include<bits/stdc++.h>
using namespace std;
int n,m,b[15][15],stu[105],t,mp;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int k=1;
	cin>>n>>m;
	mp=n*m;
	for(int i=1;i<=mp;i++){
		cin>>stu[i];
		if(i==1) t=stu[i];
	}
	for(int i=1;i<=mp;i++){
		if(stu[i]<stu[i+1]) swap(stu[i],stu[i+1]);
	}
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				b[i][j]=stu[k];
				if(stu[k]==t){
					cout<<i<<" "<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				k++;
			}
		}
		else{
			for(int l=m;l>=1;l--){
				b[i][l]=stu[k];
				if(stu[k]==t){
					cout<<i<<" "<<l;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				k++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
