#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Student1{
	int fst,sec,trd;
	friend operator < (const Student1 &a,const Student1 &b){
		return min((a.fst-a.sec),(a.fst-a.trd))>min((b.fst-b.sec),(b.fst-b.trd));
	}
}a[N];
struct Student2{
	int fst,sec,trd;
	friend operator < (const Student2 &a,const Student2 &b){
		return min((a.sec-a.fst),(a.sec-a.trd))>min((b.sec-b.fst),(b.sec-b.trd));
	}
};
struct Student3{
	int fst,sec,trd;
	friend operator < (const Student3 &a,const Student3 &b){
		return min((a.trd-a.fst),(a.trd-a.sec))>min((b.trd-b.fst),(b.trd-b.sec));
	}
};
bool cmp1(Student1 a,Student1 b){
	return min((a.fst-a.sec),(a.fst-a.trd))>min((b.fst-b.sec),(b.fst-b.trd));
}
bool cmp2(Student1 a,Student1 b){
	return min((a.sec-a.fst),(a.sec-a.trd))>min((b.sec-b.fst),(b.sec-b.trd));
}
bool cmp3(Student1 a,Student1 b){
	return min((a.trd-a.fst),(a.trd-a.sec))>min((b.trd-b.fst),(b.trd-b.sec));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		
		int n;
		cin>>n;
		int mxn=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i].fst);
			scanf("%d",&a[i].sec);
			scanf("%d",&a[i].trd);
		}
		sort(a+1,a+n+1,cmp1);
//		for(int i=1;i<=n;i++){
//			cout<<a[i].fst<<" "<<a[i].sec<<" "<<a[i].trd<<'\n';
//		}
		long long ans=0;int scnt=0;
		priority_queue<Student1>qf;
		priority_queue<Student2>qs;
		priority_queue<Student3>qt;
		for(int i=1;i<=n;i++){
			if(a[i].fst-max(a[i].sec,a[i].trd)>=0){
				//cout<<a[i].fst<<" "<<a[i].sec<<" "<<a[i].trd<<'\n';
				ans+=a[i].fst;
				qf.push({a[i].fst,a[i].sec,a[i].trd});
			}
			else{
				sort(a+i,a+n+1,cmp2);
				for(int j=i;j<=n;j++){
					//cout<<a[j].fst<<" "<<a[j].sec<<" "<<a[j].trd<<'\n';
					if(a[j].sec-max(a[j].fst,a[j].trd)>=0){
						ans+=a[j].sec;
						qs.push({a[j].fst,a[j].sec,a[j].trd});
					}
					else{
						sort(a+j,a+n+1,cmp3);
						for(int k=j;k<=n;k++){
							//cout<<a[k].fst<<" "<<a[k].sec<<" "<<a[k].trd<<'\n';
							ans+=a[k].trd;
							qt.push({a[k].fst,a[k].sec,a[k].trd});
						}
						break;	
					}	
				}
				break;	
			}
		}
		while(qf.size()>n/2){
			if(qf.top().sec>=qf.top().trd){
				if(qs.size()<n/2){
					ans-=qf.top().fst-qf.top().sec;
					qs.push({qf.top().fst,qf.top().sec,qf.top().trd});
				}
				else{
					ans-=qf.top().fst-qf.top().trd;
					qt.push({qf.top().fst,qf.top().sec,qf.top().trd});
				}
			}
			else{
				if(qt.size()<n/2){
					ans-=qf.top().fst-qf.top().trd;
					qt.push({qf.top().fst,qf.top().sec,qf.top().trd});
				}
				else{
					ans-=qf.top().fst-qf.top().sec;
					qs.push({qf.top().fst,qf.top().sec,qf.top().trd});
				}
			}
			qf.pop();
		}
		while(qs.size()>n/2){
			if(qs.top().fst>=qs.top().trd){
				if(qf.size()<n/2){
					ans-=qs.top().sec-qs.top().fst;
					qf.push({qs.top().fst,qs.top().sec,qs.top().trd});
				}
				else{
					ans-=qs.top().sec-qs.top().trd;
					qt.push({qs.top().fst,qs.top().sec,qs.top().trd});
				}
			}
			else{
				if(qt.size()<n/2){
					ans-=qs.top().sec-qs.top().trd;
					qt.push({qs.top().fst,qs.top().sec,qs.top().trd});
				}
				else{
					ans-=qs.top().sec-qs.top().fst;
					qf.push({qs.top().fst,qs.top().sec,qs.top().trd});
				}
			}
			qs.pop();
		}
		while(qt.size()>n/2){
			if(qt.top().sec>=qt.top().fst){
				if(qs.size()<n/2){
					ans-=qt.top().trd-qt.top().sec;
					qs.push({qt.top().fst,qt.top().sec,qt.top().trd});
				}
				else{
					ans-=qt.top().trd-qt.top().fst;
					qf.push({qt.top().fst,qt.top().sec,qt.top().trd});
				}
			}
			else{
				if(qf.size()<n/2){
					ans-=qt.top().trd-qt.top().fst;
					qf.push({qt.top().fst,qt.top().sec,qt.top().trd});
				}
				else{
					ans-=qt.top().trd-qt.top().sec;
					qs.push({qt.top().fst,qt.top().sec,qt.top().trd});
				}
			}
			qt.pop();
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
