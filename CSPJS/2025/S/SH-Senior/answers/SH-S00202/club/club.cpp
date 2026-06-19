#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x,y,z;
}p[100000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		int ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>p[i].x>>p[i].y>>p[i].z;
		}
		if(n==2){
			cout<<max(p[0].x+p[1].y,max(p[0].x+p[1].z,p[0].y+p[1].z));
		}                                                                                                                                             
	}
	return 0;
}
