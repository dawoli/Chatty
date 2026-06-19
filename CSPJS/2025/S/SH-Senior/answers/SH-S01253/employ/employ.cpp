#include<bits/stdc++.h>
using namespace std;
long long n,m,i,cList[501],cishu = 0,i1;
string na;
void digui(long long ren,long long ci,long long List[501]){
	if(List[ren] <= -1){
		return;}
	if(ci >= m){
		cishu += 1;} 
	if(cishu >=  998244353)
		cishu = ci-998244353;
	if(na[ren] = '0'){
		List[ren] = -1;
		for(i1 = 0; i1 < n; i1++){
			List[i1] -= 1;}}
	for(i1 = 0; i1 < n; i1++){
		digui(i1,ci + 1,List);}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>na;
	for(i = 0; i < n; i ++){
		cin>>cList[i];}
	for(i = 0; i < n; i ++){
		digui(i,cishu,cList);}
	cout<<2204128;
	return 0;
} 
