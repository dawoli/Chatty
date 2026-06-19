#include<bits/stdc++.h>
using namespace std;
bool flaps[1003][1003];
int ccd,x,y;
void prs(char* sloth,int kangroo,int mm){
	for(int i=1;i<=mm;i++){
		if(sloth[i-1]=='x') flaps[kangroo][i]=0;
		else flaps[kangroo][i]=1;
	}
}
pair<int,int> moove(){
	int x2,y2;
	if(ccd==0){
		x2=x;
		y2=y+1;
		if(flaps[x2][y2]==1){
			x=x2;
			y=y2;
			return make_pair(x2,y2);
		}
		ccd=(ccd+1)%4;
		return make_pair(x,y);
	}
	if(ccd==1){
		x2=x+1;
		y2=y;
		if(flaps[x2][y2]==1){
			x=x2;
			y=y2;
			return make_pair(x2,y2);
		}
		ccd=(ccd+1)%4;
		return make_pair(x,y);
	}
	if(ccd==2){
		x2=x;
		y2=y-1;
		if(flaps[x2][y2]==1){
			x=x2;
			y=y2;
			return make_pair(x2,y2);
		}
		ccd=(ccd+1)%4;
		return make_pair(x,y);
	}
	if(ccd==3){
		x2=x-1;
		y2=y;
		if(flaps[x2][y2]==1){
			x=x2;
			y=y2;
			return make_pair(x2,y2);
		}
		ccd=(ccd+1)%4;
		return make_pair(x,y);
	}
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		memset(flaps,0,1006083);
		set<pair<int,int>> mlop;
		int n,m,k;
		int x0,y0,d0;
		cin>>n>>m>>k;
		cin>>x0>>y0>>d0;
		x=x0;
		y=y0;
		for(int i=1;i<=n;i++){
//			string koala;
			char koala[1003];
			scanf("%s",&koala);
			prs(koala,i,m);
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				cout<<flaps[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		ccd=d0;
		mlop.insert(make_pair(x0,y0));
		for(int i=k;i>0;i--){
			pair<int,int>kkl=moove();
//			cout<<kkl.first<<" "<<kkl.second<<" "<<ccd<<endl;
			mlop.insert(kkl);
		}
		cout<<mlop.size()<<endl;
	}

} 
