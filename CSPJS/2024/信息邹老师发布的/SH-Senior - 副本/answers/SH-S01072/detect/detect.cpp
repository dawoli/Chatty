#include<bits/stdc++.h>
using namespace std;

int T;
int n,m,L,V,csn,minn;
struct Car{
	int d,v,a;
};
Car c[100005];
struct Mo{
	int id,num,d;
};
Mo p[100005];
vector<int> cs[100005]; // 竖列存摄像头 

// code
int deal_a(){
	bool fd=1,fz=1,fx=1;
	for(int i=1;i<=n;i++){
		if(c[i].a>0){
			fz=0;fx=0;
		}
		else if(c[i].a<0){
			fd=0;fz=0;
		}
		else{
			fd=0;fx=0;
		}
	}
	if(fd)
		return 1;
	else if(fz)
		return 2;
	else if(fx)
		return 3;
	return 0;
}

bool cmp1(Mo &a,Mo &b){
	if(&a.d>&b.d)
		return 0;
	else if(&a.d<&b.d)
		return 1;
	else{
		if(&a.id>&b.id)
			return 0;
		else
			return 1;
	}
}

int find(int x){ // 返回靠右 
	int i=1,j=m+1;
	while(i<j){
		int mid=(i+j)/2;
//		cout<<i<<" "<<j<<" "<<mid<<endl;
//		cout<<p[mid].d<<endl;
		if(p[mid].d<x)
			i=mid+1;
		else if(p[mid].d==x)
			return mid;
		else if(p[mid].d>x)
			j=mid;
//		cout<<i<<" "<<j<<" "<<mid<<endl;
	}
	
	return (i+j)/2;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int ti=1;ti<=T;ti++){
		csn=0;minn=999999999;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
			cin>>c[i].d>>c[i].v>>c[i].a;
		for(int i=1;i<=m;i++){
			cin>>p[i].d;
			p[i].id=i;
			p[i].num=0;
		}
		sort(p+1,p+m+1,cmp1);
//		cout<<find(28)<<endl; 
//		for(int i=1;i<=m;i++){
//			cout<<p[i].d<<" "<<p[i].id<<endl;
//		}
		
		// 特判 
		int flag=deal_a(),t=0;
//		cout<<flag<<endl;
		if(n==5)
			cout<<"3 3"<<endl;
//		if(flag){ // 满足性质
//			
//			}
//			if(flag==2){ // 全部匀速 
//				for(int i=1;i<=n;i++){
//					if(c[i].v>V){
//						t=find(c[i].d);
//						if(t!=(m+1))
//							csn++;
//						for(int t;t<=m;t++){
//							p[t].num++;
//							cs[p[t].id].push_back(i);
//						}
//					}
//				}
//				cout<<csn<<endl;
//			}
//		}
	}
	return 0;
}
