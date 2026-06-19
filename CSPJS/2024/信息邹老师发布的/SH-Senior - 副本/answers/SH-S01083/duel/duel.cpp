#include<bits/stdc++.h>
using namespace std;
int n,i,i2,cnt;
long long t;
struct g{
	long long r;
	bool at;
	bool d;
}a[100005];
bool check(){
	for(int i=0;i<n;i++) if((!a[i].at and !a[i].d) or a[i].r<=a[i+1].r) return true;
	return false;
}
bool cmp(const g &a,const g &b){
	return a.r<b.r;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
    cin>>n;
    for(int l=0;l<n;l++) cin>>a[l].r;
    sort(a,a+n,cmp);
    while(check()){
    	t++;
    	if(a[i].r<a[i2].r and !a[i2].at and !a[i].d){
    		a[i].d=true;
    		a[i2].at=true;
    		i++;
    		i2=i+1;
		}
		i2++;
	}
	for(int i=0;i<n;i++) if(!a[i].d) cnt++;
	cout<<cnt;
	return 0;
}
