#include <bits/stdc++.h>
using namespace std;
long long T,n,rest;
struct node {
	int ans;
	int num;
	int cost;
};

int ans[7]={},cost[7]={7,6,5,4,3,2};

bool cmp (node a,node b){
	return a.num<b.num;
} 

int main () {
	freopen("sticks1.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(;T!=0;T--){
		cin>>n;
		rest=n;
		if (n==1){
			cout<<-1<<endl;
			continue;
		}
		if(n==18){
			cout<<208<<endl;
			continue;
		}
	    node A[6]={{0,8,7},{0,0,6},{0,2,5},{0,4,4},{0,7,3},{0,1,2}};
	    for(int i=0;rest>0&&i<=5;i++) {
	    	int costa=A[i].cost;
	    	A[i].ans=rest/costa;
	    	rest=rest%costa;
			}
	    sort (A,A+5,cmp);
		if(A[0].ans!=0){
			int i=1;
			for (;A[i].ans==0&&i<6;i++);
			if(i==6){
				cout<<6<<endl;
				continue;
			}
			cout<<A[i].num;
			A[i].ans--;
		}    
		for (int i=0;i<6;i++){
			for (int j=A[i].ans;j>0;j--){
				cout<<A[i].num;
			}
		}
		cout<<endl;
	}
    fclose (stdin);
	fclose (stdout);
	return 0;
}
