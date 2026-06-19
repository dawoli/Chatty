#include<bits/stdc++.h>
using namespace std;
int n,ans;
struct monster{
	int r;
	bool at;
}a[100005];
bool cc(monster a,monster b){
	return a.r<b.r;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].r;
		a[i].at=1;
	}
	sort(a,a+n,cc);
	while(true){
		int i=0,j=0;
		while(a[j].r==-1&&j<n)j++;
		while((a[i].r==-1||a[i].at==0||i==j||a[i].r<=a[j].r)&&i<n)i++;
		if(j>=n||i>=n)break;
		//cout<<a[i].r<<" attacked "<<a[j].r<<endl;
		a[i].at=0;
		a[j].r=-1;
		
	}
	for(int i=0;i<n;i++){
		if(a[i].r!=-1)ans++;
	}
	cout<<ans;
	return 0;
} 
