#include<bits/stdc++.h>
using namespace std;
long long t,n,i,i1,i2;
long long nList[100001][3];
long long aList[100001],bList[10001],cList[10001],mList [5];
long long renshu[3],d,rs,as,za;
void qiongju(long long rs,long long ans,long long a,long long b,long long c){
	if((a > n / 2 or b > n / 2 )or c > n / 2){
		return;}
	if (rs == n){
		if(ans >= za)
			za = ans;
		return;}
	if (nList[rs][0] >= nList[rs][1] or nList[rs][0] >= nList[rs][2])
	qiongju(rs + 1,ans + nList[rs][0],a+1,b,c);
	if (nList[rs][1] >= nList[rs][0] or nList[rs][0] >= nList[rs][2])
	qiongju(rs + 1,ans + nList[rs][1],a,b+1,c);
	if (nList[rs][2] >= nList[rs][1] or nList[rs][2] >= nList[rs][0])
	qiongju(rs + 1,ans + nList[rs][2],a,b,c+1);
	return; 
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(i = 0; i < t; i ++){
		za = 0;
		as = 0;
		cin>>n;
		for(i1 = 0; i1 < n; i1 ++){
			cin>>nList[i1][0]>>nList[i1][1]>>nList[i1][2];}// ‰»Î 
		qiongju(0,0,0,0,0);          
		mList[i] = za;}
	for(i = 0; i < t-1; i ++){
		cout<<mList[i]<<endl;
}
	cout<<mList[t-1];
	return 0;
	} 
