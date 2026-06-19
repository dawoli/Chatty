#include<bits\stdc++.h>
using namespace std;


//int t,n,t1,t2,t3;
//int r[4];
//long long res=0;
//
//
//struct vvv{
//	int ma,cl;
//};
//
//struct vv{
//	vvv v[4];
//}a[100050];
//
//bool cmp1(vvv v1,vvv v2){
//	return v1.ma>v2.ma;
//}
//
//bool cmp2(vv v1,vv v2){
//	if(v1.v[2].ma==0 and v1.v[3].ma==0){
//		if(v2.v[2].ma==0 and v2.v[3].ma==0) return v1.v[1].ma>v2.v[1].ma;
//		return 1;
//	}
//		
//	
//	
//	if(v1.v[1].ma==v2.v[1].ma){
//		if(v1.v[2].ma==v2.v[2].ma){
//			return v1.v[3].ma>v2.v[3].ma;
//		}
//		return v1.v[2].ma>v2.v[2].ma;
//	}
//	return v1.v[1].ma>v2.v[1].ma;
//}
//
//int main(){
//	
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
//	
//	cin>>t;
//	for(int x=1;x<=t;x++){
//		cin>>n;
//		for(int i=1;i<=n;i++){
//			cin>>a[i].v[1].ma>>a[i].v[2].ma>>a[i].v[3].ma;
//			a[i].v[1].cl=1;a[i].v[2].cl=2;a[i].v[3].cl=3;
//			sort(a[i].v+1,a[i].v+4,cmp1);
//		}
//		sort(a+1,a+1+n,cmp2);
//		
//		
//		r[1]=r[2]=r[3]=res=0;
//		for(int i=1;i<=n;i++){
//			if(r[a[i].v[1].cl]==n/2){
//				if(r[a[i].v[2].cl]==n/2){
//					r[a[i].v[3].cl]++;
//					res+=a[i].v[3].ma;
//					continue;
//				}
//				r[a[i].v[2].cl]++;
//				res+=a[i].v[2].ma;
//				continue;			
//			}
//			r[a[i].v[1].cl]++;
//			res+=a[i].v[1].ma;
//		}
//		
//		cout<<res<<endl;
//	}
//	
//	
//
//	fclose(stdin);
//	fclose(stdout);
//	
//	return 0;
//}





int t,n,res;
int a[100050][4];

void dfs(int x,int tr,int t1,int t2,int t3){
	if(x==n+1){
		res=max(res,tr);
		return;
	}
	
	if(t1<=n/2-1){
		dfs(x+1,tr+a[x][1],t1+1,t2,t3);
	}
	if(t2<=n/2-1){
		dfs(x+1,tr+a[x][2],t1,t2+1,t3);
	}
	if(t3<=n/2-1){
		dfs(x+1,tr+a[x][3],t1,t2,t3+1);
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		res=0;
		dfs(1,0,0,0,0);
		cout<<res<<endl;
	}
	

	fclose(stdin);
	fclose(stdout);	
	return 0;
}
