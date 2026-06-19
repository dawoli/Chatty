#include<bits/stdc++.h>
/*
3 2 45
3 65875 21964 1
14 199234 1 75574 199234 1 157742 1 65875 65875 65875 137022 137022 1 66279
3 104830 1 1
3 65875
3 75574
5 157742
5 137022
4 157742
3 21964
1 157742
4 104830
1 199234
1 21964
5 1
4 137022
2 21964
1 65875
2 104830
1 104830
2 199234
5 10604
1 66279
3 157742
3 157742
4 66279
4 75574
3 66279
4 1
3 137022
5 65875
2 66279
5 104830
3 1
3 199234
2 157742
5 66279
2 65875
2 75574
5 75574
4 65875
2 137022
1 75574
5 199234
4 21964
1 1
1 66279
3 104830
2 1
*/
using /**/ namespace std;
int T;
int n,k,q,si[2010][2010],l[2010],ri,ci,mr=0,ok[1010];
vector<int> pr[10][200010]; 
void dfs(int p,int np,int nr){
	if(pr[nr-1][p].size()>=1){
		for(auto i:pr[nr-1][p])ok[i]=1;
		//cout<<"ACCOMP "<<pr[nr-1][p]<<": "<<nr-1<<","<<p<<'\n';
	}
	if(nr>mr)return;
	for(int i=1;i<=n;i++){
		if(i==np)continue;
		int pt=-1919810;
		for(int j=1;j<=l[i];j++){
			//printf("R%d: %d.%d->%d.%d-%d\n",nr,np,p,i,p,si[i][j]);
			if(j-pt+1>=2&&j-pt+1<=k){
				//if(si[i][j]==66279)cout<<nr<<"BRUH\n";
				if(si[i][j]==p)pt=j;
				dfs(si[i][j],i,nr+1);
			}
			if(si[i][j]==p)pt=j;
			//if(si[i][j]==p&&si[i][j+1]==66279)cout<<"BRAVO\n";
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	mr=0;
	cin>>T;
	while(T--){
		mr=0;
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++){
				cin>>si[i][j];
			}
		}
		for(int i=1;i<=q;i++){
			cin>>ri>>ci;
			//cout<<ri<<" "<<ci<<endl;
			mr=max(ri,mr);
			pr[ri][ci].push_back(i);
		}//cout<<">>>>"<<pr[1][66279];
		dfs(1,0,1);
		for(int i=1;i<=q;i++)cout<<ok[i]<<'\n';
		//memset(lt,0,sizeof(lt));
		memset(ok,0,sizeof(ok));
		memset(pr,0,sizeof(pr));
	}
	return 0;
}
