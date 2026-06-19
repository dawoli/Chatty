#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,m,L,V,p[N],minP,maxP,now,ans1,ans2;
struct Car{
	int d,u,a,tf,begin,end;
}car[N];
bool cmp(Car a,Car b){
//	if(a.end==b.end){
//		a.begin<b.begin;
//	}
	return a.end<b.end;
}
int find(int left,int right,int x){
//	cout<<left<<' '<<right<<' '<<x<<endl;
	if(right-left<=1){
		if(x<p[left]){
			return p[left-1];
		}
		if(x<p[right] || x==p[left]){
			return p[left];
		}
		if(x>p[right] || x==p[right]){
			return p[right];
		}
	}
	int mid=(left+right)/2;
	if(p[mid]>x){
		return find(left,mid,x);
	}
	if(p[mid]<x){
		return find(mid+1,right,x);
	}
	else{
		return p[mid];
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n>>m>>L>>V;
		for(int i=0;i<n;i++){
			cin>>car[i].d>>car[i].u>>car[i].a;
			if(car[i].a==0){
				if(car[i].u>V){
					car[i].begin=car[i].d;
					car[i].end=L;
					car[i].tf=1;
				}
				else{
					car[i].tf=0;
				}
			}
			else if(car[i].a>0){
				if(car[i].u>V){
					car[i].begin=car[i].d;
					car[i].end=L;
					car[i].tf=1;
				}
				else{
					if(car[i].d+(V*V-car[i].u*car[i].u)/(2*car[i].a)+1>L){
						car[i].tf=0;
					}
					else{
						car[i].begin=car[i].d+(V*V-car[i].u*car[i].u)/(2*car[i].a)+1;
						car[i].end=L;
						car[i].tf=1;
					}
				}
			}
			else if(car[i].a<0){
				if(car[i].u>V){
					car[i].begin=car[i].d;
					if(1.0*(V*V-car[i].u*car[i].u)/(2*car[i].a)-(V*V-car[i].u*car[i].u)/(2*car[i].a)>0){
						car[i].end=car[i].d+(V*V-car[i].u*car[i].u)/(2*car[i].a);
					}
					else{
						car[i].end=car[i].d+(V*V-car[i].u*car[i].u)/(2*car[i].a)-1;
					}
					car[i].tf=1;
				}
				if(car[i].u<V){
					car[i].tf=0;
				}
			}
		}
		for(int i=0;i<m;i++){
			cin>>p[i];
		}
		minP=p[0];
		maxP=p[m-1];
		for(int i=0;i<n;i++){
			if(car[i].tf==1 && (car[i].begin>maxP || car[i].end<minP)){
				car[i].tf=0;
			}
		}
		sort(car,car+n,cmp);
		now=-1;
		ans1=0;
		ans2=m;
		for(int i=0;i<n;i++){
			if(car[i].tf==1 && find(0,m-1,car[i].end)>=car[i].begin){
				ans1++;
				if(car[i].begin>now){
//					cout<<car[i].d<<' ';
					now=find(0,m-1,car[i].end);
					ans2--;
				}
			}
		}
		cout<<ans1<<' '<<ans2<<endl;
	}
	return 0;
}
