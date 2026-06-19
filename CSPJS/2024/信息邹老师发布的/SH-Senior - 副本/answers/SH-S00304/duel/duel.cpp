#include<bits/stdc++.h>
#include<fstream>
using namespace std;

ifstream fin("duel.in");
ofstream fout("duel.out");
#define cin fin
#define cout fout

int n;int a[100005];
int sum,maxr=-1e7;
int c[100005];
int temp,l,r,mid,ava;
bool add(int id,int x){
	for(int i=id;i<=maxr;i+=(i&(-i))){
		c[i]+=x;
	}
}
int query(int id){
	int res=0;
	for(int i=id;i;i-=(i&(-i))){
		res+=c[i];
	}
	return res;
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxr=max(maxr,a[i]);
	}
	sum=n;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		add(a[i],1);
	}
	for(int i=1;i<=n;i++){
		temp=query(a[i]);
		ava=sum-temp;
		if(ava<=0){
			cout<<sum<<'\n';
			return 0;
		}
		l=a[i]+1,r=maxr;
		while(l<r){
			mid=(l+r)/2;
			if(query(mid)-temp>0){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		add(l,-1);sum--;
	}
	cout<<sum<<'\n';
	return 0;
}
