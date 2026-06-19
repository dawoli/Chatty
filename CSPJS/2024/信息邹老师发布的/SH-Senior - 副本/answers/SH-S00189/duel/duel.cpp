#include<bits/stdc++.h>
using namespace std;
void fre(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
}
int r[100005];
bool die[100005];
int ans;
int n;
bool cmp(int a,int b){
	return b<a;
}
void sovel1(){
	int m=n-1;
	for(int i=0;i<n;i++){
		if(die[i]==0&&die[m]==0&&i!=m&&r[i]>r[m])die[i]=1,die[m]=1,ans--,m--;
	}
}
void sovel2(){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(r[i]!=r[j]&&die[j]==0){
				ans--,die[j]=1;
				break;
			}
		}
	}
}
int main(){
	fre();
	
	cin>>n;
	bool f=1;
	for(int i=0;i<n;i++){
		cin>>r[i];
		if(r[i]>2)f=0;
	}
	ans=n;
	sort(r,r+n,cmp);
	if(f)sovel1();
	else sovel2();
	cout<<ans;
	return 0;
}
