#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
long long mn=LLONG_MAX; 
long long ct,rd,tw;
long long **tab;
struct road{
	long long st,ed,w;
};
long long ** cp(long long ** src){
	long long ** r=new long long*[ct];
	for(long long i=0;i<ct;i++){
		r[i]=new long long[ct];
		for(long long j=0;j<ct;j++)r[i][j]=src[i][j];
	}
	return r;
}
bool cmp(road a,road b){
	return a.w<b.w;
}
long long qf(long long n,long long ft[]){
	if(n==ft[n])return n;
	else return ft[n]=qf(ft[n],ft);
}
void calc(long long **nt,long long add){
	vector<road> f;
	for(long long i=0;i<ct;i++){
		for(long long j=i+1;j<ct;j++){
			if(nt[i][j]!=1e9+1)f.push_back({i,j,nt[i][j]});
		}
	}
	sort(f.begin(),f.end(),cmp);
	long long ft[ct];
	for(long long i=0;i<ct;i++)ft[i]=i;
	for(road i:f){
		if(qf(i.st,ft)==qf(i.ed,ft))continue;
		else{
			ft[i.st]=i.ed;
			add+=i.w;
		}
	}
	mn=min(mn,add);
}
void ubiz(long long **nt,pair<long long,long long *> tn[],long long idx,long long add){
	if(idx==tw){
		calc(nt,add);
		for(long long i=0;i<ct;i++)delete[] nt[i];
		delete[] nt;
		return;
	}
	ubiz(cp(nt),tn,idx+1,add);
	for(long long i=0;i<ct;i++){
		for(long long j=i+1;j<ct;j++){
			nt[i][j]=min(nt[i][j],tn[idx].second[i]+tn[idx].second[j]);
		}
	}
	ubiz(cp(nt),tn,idx+1,add+tn[idx].first);
	for(long long i=0;i<ct;i++)delete[] nt[i];
	delete[] nt;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>ct>>rd>>tw;
	tab=new long long *[ct];
	for(long long i=0;i<ct;i++){
		tab[i]=new long long[ct];
		for(long long j=i+1;j<ct;j++)tab[i][j]=1e9+1;
	}
	long long st,ed,w;
	while(rd--){
		cin>>st>>ed>>w;
		if(st>ed)swap(st,ed);
		tab[st-1][ed-1]=w;
	}
	pair<long long,long long *> tn[tw];
	for(long long i=0;i<tw;i++){
		cin>>tn[i].first;
		tn[i].second=new long long[ct];
		for(long long j=0;j<ct;j++)cin>>tn[i].second[j];
	}
	ubiz(tab,tn,0,0);
	cout<<mn;
	return 0;
}

