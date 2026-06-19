#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
int n;
int a[1000010],b[1000010];
void solve(int ql,int qr,int hl,int hr){
	if(ql==qr){
		ans.push_back(a[ql]);
		return;
	}
	int lroot=a[ql+1],rroot=b[hr-1];// lr zuozishu root;;rr youzishugen 
	int qianxulr,houxull=hl,houxulr,qianxurr=qr,qianxurl,houxurl;
	for(int i=ql+1;i<=qr;i++){
		if(a[i]==rroot){
			qianxulr=i-1;
			qianxurl=i;
			break;
		}
	}
	for(int i=hr-1;i>=hl;i--){
		if(b[i]==lroot){
			houxulr=i;
			houxurl=i+1;
			break;
		}
	}
	solve(ql+1,qianxulr,houxull,houxulr);
	ans.push_back(a[ql]);
	solve(qianxurl,qianxurr,houxurl,hr-1);
	//b=b.reverse(b.begin(),b.end());
	return;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	} 
	solve(1,n,1,n);
	for(int i=0;i<n;i++)printf("%d ",ans[i]); 
	return 0;
}
