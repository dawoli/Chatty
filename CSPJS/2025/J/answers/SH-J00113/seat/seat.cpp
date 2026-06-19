#include<bits/stdc++.h>
using namespace std;
struct Node{
	int v,idx;
}a[102];
bool cmp(Node a,Node b){
	return a.v>b.v;
}
//freopen
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].v;
		a[i].idx=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int id=1;
	for(int i=1;i<=n;i++){
		if(i%2){
			for(int j=1;j<=m;j++){
				if(a[id].idx==1){
					cout<<i<<" "<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				id++;
			}
		}else{
			for(int j=m;j>=1;j--){
				if(a[id].idx==1){
					cout<<i<<" "<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
				id++;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

