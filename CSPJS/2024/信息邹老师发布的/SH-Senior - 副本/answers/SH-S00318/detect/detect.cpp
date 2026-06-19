#include<bits/stdc++.h>
using namespace std;
int t,n[21],m[21],l[21],v1[21],p[100009],ans1[21],ans2[21];
struct node{
	int d;
	int v;
	int a;
}car[100009];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	int cnt=t;
	while(t>0){
		cin>>n[cnt-t]>>m[cnt-t]>>l[cnt-t]>>v1[cnt-t];
		for(int i=0;i<n[cnt-t];++i)
			cin>>car[i].d>>car[i].v>>car[i].a;
		for(int i=0;i<m[cnt-t];++i)
			cin>>p[i];
		if(car[0].a==0){
			for(int i=0;i<n[cnt-t];++i){
				if(car[i].d>=p[m[cnt-t]-1]&&car[i].v>v1[cnt-t])
					ans1[cnt-t]++;
			}
			ans2[cnt-t]=m[cnt-t]-1;
		}
		t--;
	}
	for(int i=0;i<t;++i)
		cout<<ans1[i]<<" "<<ans2[i]<<endl;
	return 0;
}
