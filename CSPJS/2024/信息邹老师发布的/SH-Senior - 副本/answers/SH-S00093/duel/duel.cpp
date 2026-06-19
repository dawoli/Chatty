#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int n;
int a[N];
int d[N];
int cnt=0;
vector<int>t;
int Lower_bound(int l,int r,int val){
	while(l<r){
		int mid=(l+r)/2;
		if(t[mid]==val)return mid;
		if(t[mid]>val)r=mid-1;
		if(t[mid]<val)l=mid+1;
	}
	return r;
}
void descretization(){
	t.assign(a+1,a+1+n);
	sort(t.begin(),t.end());
	t.erase(unique(t.begin(),t.end()),t.end());
	for(int i=1;i<=n;i++){
		d[i]=Lower_bound(0,t.size()-1,a[i])+1;
	}
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	descretization();
	sort(d+1,d+1+n);
	int l=lower_bound(d+1,d+1+n,2)-d;
	int i=1;
	while(l<=n){
		if(d[i]<d[l]){
			cnt++;
			i++,l++;
		}
		if(d[i]==d[l]){
			if(d[l]==d[n])break;
			else l=lower_bound(d+1+l,d+1+n,d[l]+1)-d;
		}
	}
	cout<<n-cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
