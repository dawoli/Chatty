#include<bits/stdc++.h>
using namespace std;
int p[100005],n,Max,a[100005]={},End;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i];
		End=max(End,p[i]);}
	sort(p,p+n);
	for(int i=0;i<n;i++){
		a[p[i]]++;}
	for(int i=0;i<=End;i++){
		if(a[i]==0){continue;}
		Max=max(Max,a[i]);}
	cout<<Max<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
			
}
