#include<iostream>
using namespace std;
struct car{
	int pla;
	int spe;
	int add;
};
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	car a[100005]={};
	int road[100005]={};
	cin>>t;
	for(int i=0;i<t;i++){
		long long n,m,l,v;
		cin>>n>>m>>l>>v;
		for(int j=0;j<n;j++){
			cin>>a[j].pla>>a[j].spe>>a[j].add;
		}
		for(int j=0;j<m;j++){
			int z;
			cin>>z;
			road[z]=1;
		}
		int max=-1;
		for(int j=0;j<l;j++){
			if(road[j]==1){
				max=j;
			}
		}
		int s=0;
		for(int j=0;j<n;j++){
			if(a[j].spe>v && a[j].pla<=max){
				s++;
			}
		}
		cout<<s<<' '<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
