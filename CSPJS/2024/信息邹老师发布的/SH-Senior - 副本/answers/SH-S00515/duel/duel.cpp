#include<iostream>
using namespace std;
int l[1000000]={-1};
int n,ji=0,mx=0;
int z[100000]={0};
int zheng(int xz){
	if(xz<0){
		return 0;
	}
	return xz;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l[i];
		if(l[i]>mx)mx=l[i];
		z[l[i]]++;
	}
	ji=z[1];
	for(int i=2;i<mx+1;i++){
		ji=zheng(ji-z[i])+z[i];
	}	
	cout<<ji;
	fclose(stdin);
	fclose(stdout);
	return 0;
}



