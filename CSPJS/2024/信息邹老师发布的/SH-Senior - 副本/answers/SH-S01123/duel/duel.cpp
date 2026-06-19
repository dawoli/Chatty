#include<bits/stdc++.h>
using namespace std;
int n,ans=100005,idx=0;
struct node{
	int r;
	int r_m;
}a[100005];
bool cmp(node g,node h){
	return g.r<h.r;
}
/*
  各不相同的攻击力 
  各不相同的攻击力代表的怪兽数量 
*/ 

//void dfs(int no_attacked_monster,int ans1){
//	if(no_attacked_monster==0){
//		ans=min(ans,ans1);
//		return;
//	}
//	for(int i=1;i<=idx){
//		if(a[i].l_m==0||a[i].a_m==n){
//			continue;
//		}
//		bool z=0;
//		for(int j=1;j<i;j++){
//			if(i==j){
//				continue;
//			}
//			if(a[j].l_m>0){
//				z=1;
//				if(a[i].r>a[j].r){
//					a[j].l_m--;
//					a[i].a_m++;
//					dfs(no_attacked_monster-1,ans1-1);
//					a[j].l_m++;
//					a[i].a_m--;
//				}else{
//					a[i].a_m++;
//					dfs(no_attacked_monster-1,ans1);
//					a[i].a_m--;
//				}
//			}
//		}
//		if(z==0){
//			
//		}
//	}
//	
//}

int main(){
	//删除下面的注释 
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	cin>>n;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		bool f=0;
		for(int j=1;j<=idx;j++){
			if(x==a[j].r){
				a[j].r_m++;
				f=1;
				break;
			}
		}
		if(f==0){
			idx++;
			a[idx].r=x;
			a[idx].r_m++;
		}
	}
	
	if(idx==1){
		cout<<n;
		return 0;
	}
	
	sort(a+1,a+1+idx,cmp);
	
//	dfs(n,n);
//	for(int i=1;i<=idx;i++){
//		cout<<a[i].r<<" "<<a[i].r_m<<endl;
//	}
	ans=n;
	for(int i=2;i<=idx;i++){
		if(a[i].r_m<=a[i-1].r_m){
			ans-=a[i].r_m;
		}else{
			ans-=a[i-1].r_m;
		}
	}
	cout<<ans;
	
	return 0;
}
