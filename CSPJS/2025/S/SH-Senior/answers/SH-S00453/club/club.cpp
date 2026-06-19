#include<bits/stdc++.h>
#define int long long
//多组数据记！得！清！空！ 
std::ifstream fin("club.in");
std::ofstream fout("club.out");
using namespace std;
struct nodet{
	int fir,sec,thi;
};
struct node{
	int fr,se,th;
}t[100010]; 
int T,n;
int ans[100010];
int a[100010][4];
nodet func(int a,int b,int c){
	int maxx=max(a,max(b,c));
	int minn=min(a,min(b,c));
	int midd;
	int maxid=1,midid=1;
	if(a==maxx) maxid=1;
	else if(b==maxx) maxid=2;
	else maxid=3;
	if(a!=minn&&a!=maxx){
		midd=a;
		midid=1;
	}
	else if(b!=minn&&b!=maxx){
		midd=b;
		midid=2;
	} 
	else{
		midd=c;
		midid=3;
	} 
	nodet tmp;
	tmp.fir=maxid;
	tmp.sec=midid;
	tmp.thi=maxx-midd;
	return tmp;
}
bool cmp(node tmp1,node tmp2){
	return tmp1.th<tmp2.th;
}
void init(int m){
	for(int i=0;i<=m+1;i++){
		t[i].fr=0;t[i].se=0;t[i].th=0;
		for(int j=0;j<4;j++){
			a[i][j]=0;
		}
	}
} 
signed main(){
	fin>>T;
	while(T--){
		unordered_map<int,int> mp;
		fin>>n;
		init(n);
		int maxt=-1e9,maxxid=1;
		for(int i=1;i<=n;i++){
			fin>>a[i][1]>>a[i][2]>>a[i][3];
			t[i].fr=func(a[i][1],a[i][2],a[i][3]).fir;
			t[i].se=func(a[i][1],a[i][2],a[i][3]).sec;
			t[i].th=func(a[i][1],a[i][2],a[i][3]).thi;
			mp[t[i].fr]++;
			maxt=max(maxt,mp[t[i].fr]);
			if(mp[t[i].fr]==maxt){
				maxxid=t[i].fr;
			}
			ans[i]=a[i][t[i].fr];
			//cout<<t[i].fr<<" "<<t[i].se<<" "<<t[i].th<<endl;
		}
		int res=0;
		for(int i=1;i<=n;i++){
			res+=a[i][t[i].fr];
		}
		if(maxt<=(n/2)){
			fout<<res<<endl;
			continue;
		}
		sort(t+1,t+n+1,cmp);//从小到大
		//fout<<maxt-(n/2)<<" ";
		int j=1;
		for(int i=1;j<=maxt-(n/2);i++){
			if(t[i].fr==maxxid){
				res-=t[i].th; 
				//cout<<"!"<<t[i].th<<endl;
				j++; 
			}
		} 
		fout<<res<<endl;
		//cout<<endl;
		//fout<<t[1].fr<<" "<<t[1].se<<" "<<t[1].th;
	}
	/*int x,y,z;
	fin>>x>>y>>z;
	fout<<func(x,y,z).fir<<" "<<func(x,y,z).sec<<" "<<func(x,y,z).thi;*/ 
}
