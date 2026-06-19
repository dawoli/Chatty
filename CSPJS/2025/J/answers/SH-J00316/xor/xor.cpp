#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500000];
struct dist{
	int l,r;
} ex[500000];
bool cmp(dist a,dist b){
	if(a.r!=b.r) return a.r>b.r;
	return a.l>b.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	int id=0;
	for(int i=0;i<n;i++){
		int xor_ans=0;
		for(int j=i;j<n;j++){
			xor_ans^=a[j];
			if(xor_ans==k){
				ex[id].l=i;
				ex[id].r=j;
				id++;
			}
		}
	}
	sort(ex,ex+id,cmp);
	int ans=0,st=n;
	for(int i=0;i<id;i++){
		if(ex[i].r<st){
			ans++;
			st=ex[i].l;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
