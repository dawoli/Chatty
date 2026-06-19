#include<iostream>
#include<cmath>
#include<map>
using namespace std;
long long a[500005];
map<long long,long long> mp;
long long Xor(long long a1,long long b1){
	long long aa=a1,bb=b1;
	long long sum=0;
	for(int y=20;y>=0;y--){
		long long p=pow(2,y);
		if(aa>=p||bb>=p){
			bool aal=(aa>=p);
			aa-=aal*p;
			bool bbl=(bb>=p);
			bb-=bbl*p;
			if(!(aal&&bbl))sum+=p;
		}
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int sum=0;
	long long n,k;cin>>n>>k;
	for(int n1=0;n1<n;n1++){
		cin>>a[n1];
	}
	for(long long r=1;r<=n;r++){
		for(long long re=0;re<=n-r;re++){
			int end=re+r-1;
			long long toto=0;
			for(int u=re;u<=end;u++)toto=Xor(toto,a[u]);
			if(toto==k){
				mp.insert(make_pair(re+1,end+1));
				sum++;
			}
		}
	}
	long long all=0;
	long long beg=-1,en=-1;
	for(map<long long,long long>::iterator e=mp.begin();e!=mp.end();e++){
		if(e->first>en){
			all++;
			en=e->second;
		}
	}
	cout<<all;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
