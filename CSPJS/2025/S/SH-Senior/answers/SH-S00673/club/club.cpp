#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
struct ott{
	int bianhao,manyidu;
	friend bool operator<(ott a,ott b){
		return a.manyidu>b.manyidu;
	}
};
struct node{
	int diff1,diff2,cl1,cl2,id;
	//int bs;
	friend bool operator<(node a,node b){
		//if(a.bs!=b.bs)
		    //return a.maxs<b.maxs;
		if(a.diff1==b.diff1)
		    return a.diff2>b.diff2;
		return a.diff1>b.diff1;
	}
};
void solve(){
	int n,a[MAXN][4],sum=0;
	priority_queue<node> pq1,pq2,pq3;
	cin>>n;
	for(int i=1;i<=n;i++){
	    cin>>a[i][1]>>a[i][2]>>a[i][3];
	    //int b=0;
	    vector<ott> paixv;
	    paixv.push_back({1,a[i][1]});
	    paixv.push_back({2,a[i][2]});
	    paixv.push_back({3,a[i][3]});
	    sort(paixv.begin(),paixv.end());
	    //if(a[i][1]==a[i][2]&&a[i][1]==a[i][3])
	        //b=2;
	    //else if(a[i][1]==a[i][2]||a[i][1]==a[i][3]||a[i][2]==a[i][3])
	        //b=1;
	    int diff1=paixv[0].manyidu-paixv[1].manyidu;
	    int diff2=paixv[0].manyidu-paixv[2].manyidu;
	    int cl1=paixv[1].bianhao,cl2=paixv[2].bianhao;
	    sum+=paixv[0].manyidu;
	    if(paixv[0].bianhao==1)
	        pq1.push({diff1,diff2,cl1,cl2,i});
	    if(paixv[0].bianhao==2)
	        pq2.push({diff1,diff2,cl1,cl2,i});
	    if(paixv[0].bianhao==3)
	        pq3.push({diff1,diff2,cl1,cl2,i});
	}
	while(pq1.size()>n/2){
	    node f=pq1.top();
		pq1.pop();
		sum-=f.diff1;
	}
	while(pq2.size()>n/2){
	    node f=pq2.top();
		pq2.pop();
		sum-=f.diff1;
	}
	while(pq3.size()>n/2){
	    node f=pq3.top();
		pq3.pop();
		sum-=f.diff1;
	}
	cout<<sum<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	    solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
