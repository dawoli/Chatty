#include<bits/stdc++.h>
using namespace std;

string a[500002],judge;
int n,k,now;

struct a0{
	long long a1[500002];
	long long a2[500002];
}a0;

int asw=0;

int dfs(int mi,int asw,int o,int head){
	if(o > head+1){
		return asw;
	}
	if(a0.a1[o]>=mi){
		asw++;
		mi=a0.a2[o];
		o++;
		return dfs(mi,asw,o,head);
	}
	o++;
	return dfs(mi,asw,o,head);
	
}

long long head=0;

void tentotwo(long long am,long long k){
	int i=0;
	while(am!=0){
		if(am%2==1){
			a[k]+="1";
		}else{
			a[k]+="0";
		}
		am/=2;
	}
}

string tentotwo(long long am){
	int i=0;
	string back;
	while(am!=0){
		if(am%2==1){
			back+="1";
		}else{
			back+="0";
		}
		am/=2;
	}
	return back;
}

int twototen(string opop){
	long long hhh=0,nw=1;
	for(int yu=0;yu<opop.length();yu++){
		if(opop[yu]==1){
			hhh+=nw;
		}
		nw*=2;
	}
	return hhh;
}

int yh(string a1,string a2){
	long long mx=max(a1.length(),a2.length()),as;
	string hoho="";
	for(int j=0;j<mx;j++){
		if(a1[j]!=a2[j]){
			hoho+="1";
		}else{
			hoho+="0";
		}
		return twototen(hoho);
	}
	
	return as;
}

int qjyhh(int l,int r){
	string now="0";
	for(int j=l;j<=r;j++){
		now=yh(now,a[j]);
	}
	if(l==r){
		now=a[l];
	}
	if(now == judge){
		a0.a1[head]==l;
		a0.a2[head]==r;
		head++;
	}
}

bool cmp(int a,int b){
	if(a<b){
		return 0;
	}else{
		return 1;
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    long long ans=0;
	cin>>n>>k;
	judge = tentotwo(k);
	for(int i=0;i<n;i++){
		cin>>now;
		tentotwo(now);
	}
	for(int l=0;l<n;l++){
		for(int r=l;r<n;r++){
			qjyhh(l,r);
		}
	}
	int mid;
	for(int q=1;q<head+1;q++){
		for(int p=1;p<head+1;p++){
			if(cmp(a0.a1[p-1],a0.a1[p])){
				mid=a0.a1[p-1];
				a0.a1[p-1]=a0.a1[p];
				a0.a1[p]=mid;
				mid=a0.a2[p-1];
				a0.a2[p-1]=a0.a2[p];
				a0.a2[p]=mid;
			}
		}
	}
	int mi=-1;
	ans=dfs(-1,0,0,head);
	cout<<ans;
	return 0;
}
