#include<bits/stdc++.h>
using namespace std;
int t,n;
long long ans;
struct mem{ //成员信息 
	pair <int,int> a,b,c;
}s[100005];
bool cmp(mem q,mem p){
	if(q.a==p.a){
		if(q.b==p.b) return q.c>p.c;
		return q.b>p.b;
	}
	return q.a>p.a;
}
int num[4]; //部门成员量（按最满意 
bool cmp1(int x,int y){
	return min(s[x].a.first-s[x].b.first,s[x].a.first-s[x].c.first)<min(s[y].a.first-s[y].b.first,s[y].a.first-s[y].c.first);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		//
//		cout<<"t="<<t<<endl;
		//
		ans=0;
		num[1]=num[2]=num[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			pair<int,int> A[4];//内部123排序 
			cin>>A[1].first>>A[2].first>>A[3].first;
			A[1].second=1,A[2].second=2,A[3].second=3;
			sort(A,A+4);
			s[i].a=A[3];
			s[i].b=A[2];
			s[i].c=A[1];
			
		}
		sort(s+1,s+1+n,cmp);//综合排序 
		vector <int> m[4]; //部门成员编号 
		for(int i=1;i<=n;i++){//按最高意愿安排 
			num[s[i].a.second]++;
			ans+=s[i].a.first;
			m[s[i].a.second].push_back(i);
		}
		//
//		for(int i=1;i<=n;i++) cout<<s[i].a.first<<' '<<s[i].b.first<<' '<<s[i].c.first<<endl;
		//
		for(int k=1;k<=3;k++){//提出代价最小的成员 
			//
//			for(int j=0;j<m[k].size();j++) cout<<m[k][j]<<' ';
//			cout<<endl;
			//
			if(num[k]>n/2){
				int m2[100005],l;
				for(l=0;l<m[k].size();l++){
					m2[l]=m[k][l]; 
				}
				
//				for(int i=0;i<l;i++) cout<<"#"<<s[m2[i]].a.first<<' '<<max(s[m2[i]].b.first,s[m2[i]].c.first)<<endl;
			
				sort(m2,m2+l,cmp1);//按换取代价由低到高排序 
				
//				for(int i=0;i<l;i++) cout<<"@"<<s[m2[i]].a.first<<' '<<max(s[m2[i]].b.first,s[m2[i]].c.first)<<endl;
				
				for(int i=0;i<l-n/2;i++){
					ans-=s[m2[i]].a.first;
					ans+=max(s[m2[i]].b.first,s[m2[i]].c.first);
					//
//					cout<<"*"<<s[m2[i]].a.first<<' '<<max(s[m2[i]].b.first,s[m2[i]].c.first)<<endl;
					//
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
