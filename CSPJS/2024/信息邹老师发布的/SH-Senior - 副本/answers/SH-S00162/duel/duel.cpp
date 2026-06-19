#include<bits/stdc++.h>
using namespace std;

const int N=1e7+2;
int n;
int a[N];
int kill_num;

bool cmp(int a,int b){
	return a<b;
}

void duel(int i,int j,int r1,int r2){
	if(r2==0) return;
	if(r2>r1){
		kill_num+=1;
		duel(i+1,j+1,a[i+1],a[j+1]);
	}
	else{
		duel(i,j+1,a[i],a[j+1]);
	}
}

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1,cmp);

	duel(1,2,a[1],a[2]);
	cout<<n-kill_num<<endl;
	return 0;
}
