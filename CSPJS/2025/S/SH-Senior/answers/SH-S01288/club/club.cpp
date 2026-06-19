#include <bits/stdc++.h>
using namespace std;

int n,t;

bool cmp(int x,int y){
	return x>y;
}

int p1[200005],p2[200005],p3[200005];

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n;
		int sum=0;
		int dep1=0,dep2=0,dep3=0;
		for(int i=1;i<=n;i++){
			int a[5],m,mn,flag;
			cin>>a[1]>>a[2]>>a[3];
			m = max(a[1],max(a[2],a[3]));
			if(m==a[1]){
				dep1++;
				flag = 1;
			}
			if(m==a[2]){
				dep2++;
				flag = 2;
			}
			if(m==a[3]){
				dep3++;
				flag = 3;
			}
			sum += m;
			sort(a+1,a+4,cmp);
			mn = a[1]-a[2];
			if(flag==1) p1[dep1] = mn;
			else if(flag==2) p2[dep2] = mn;
			else if(flag==3) p3[dep3] = mn;
		}
		if(dep1>n/2){
			sort(p1+1,p1+dep1+1);
			for(int i=1;i<=dep1-n/2;i++){
				sum -= p1[i];
			}
		}
		else if(dep2>n/2){
			sort(p2+1,p2+dep2+1);
			for(int i=1;i<=dep2-n/2;i++){
				sum -= p2[i];
			}
		}
		else if(dep3>n/2){
			sort(p3+1,p3+dep3+1);
			for(int i=1;i<=dep3-n/2;i++){
				sum -= p3[i];
			}
		}
		cout<<sum<<endl;
	}
	
	
	return 0;
} 
