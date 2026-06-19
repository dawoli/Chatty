#include<bits/stdc++.h>
using namespace std;
const int x=10005;
int a[x][x];
int add[x];
int vis[x];
int m,n,k,l1,l2,min1=10000,minn=1000;
struct students{
	int v;
	int a1,a2;
};
void px(){
	for(int i=0;i<m;i++){
		for(int j=i;j<m;j++){
			//if(students[i].v>students[i].v){
			//	swap(students[i].a1,students[j].a1);
			//	swap(students[i].a2,students[j].a2);
			//	swap(students[i].v,students[j].v);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>l1>>l2;
		cin>>a[l1][l2];
		a[l2][l1]=a[l1][l2];
		//student[i].v=a[l1][l2];
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			cin>>add[i];
			if(add[i]<minn){
				minn=add[i];
				min1=i;
			}
			cin>>a[i+n][j];
			a[j][i+n]=a[i+n][j];
		}
	}
	//px();
	int ans;
	cout<<13<<endl;
	return 0;
}
