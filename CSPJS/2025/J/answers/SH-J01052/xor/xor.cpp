#include <bits/stdc++.h>
using namespace std;
struct as{
	int l;
	int r;
	int countc;
	vector <int> chx;
};
bool cmp2(as a,as b){
	return a.countc>b.countc;
}bool cmp1(as a,as b){
	return a.l<b.l;
}
bool ch(as a,as b){
	return a.r>b.l;
}
int yihuo(int a,int b){
	bool da[25]={},db[25]={},dc[25]={};
	int cnt=0;
	while(a>0){
		da[cnt]=a%2;
		a-=a%2;
		a=a/2;
		cnt++;
	}
	cnt=0;
	while(b>0){
		db[cnt]=b%2;
		b-=b%2;
		b=b/2;
		cnt++;
	}
	for(int i=0;i<22;i++){
		dc[i]=(da[i]!=db[i]);
	}
	int c=0;
	for(int i=0;i<23;i++){
		c+=pow(2,i)*dc[i];
	}
	return c;
}
int f[1024][1024];
as m[1024];
int g[1024];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	for(int i=0;i<1024;i++){
		for(int j=0;j<1024;j++){
			f[i][j]=-1;
		}
	}
	int n,k;
	int a[1024];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f[i][i]=a[i]; 
	}
	for(int j=1;j<11;j++){
		for(int i=1;i<=n;i+=pow(2,j)){
			int t=pow(2,j);
			f[i][i+t-1]=yihuo(f[i][i+t/2-1],f[i+t/2][i+t-1]);
		}
	}
	int y=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int dl=l,dr=r;
			int ans=f[dl][dl];
			while(dl!=dr){
				if(f[dl][dl+1]==-1){
					ans=yihuo(ans,f[dl+1][dl+1]);
					dl=dl+1;
					continue;
				}
				for(int i=10;i>=0;i--){
					int t=pow(2,i);
					if(f[dl][dl+t-1]!=-1&&dl+t-1<=dr){
						ans=yihuo(ans,f[dl][dl+t-1]);
						ans=yihuo(ans,f[dl][dl]);
						dl=dl+t-1;
						break;
					}
				}
			}
			if(ans==k){
				m[y].l=l;
				m[y].r=r;
				m[y].countc=0;
				y++;
			}
		}
	}
	int u=0;
	for(int i=0;i<y;i++){
		for(int j=i+1;j<y;j++){
			if(ch(m[i],m[j])){
				m[i].countc++;
				m[j].countc++;
				m[i].chx.push_back(j);
				m[j].chx.push_back(i);
				u+=2;
			}
		}
	}
	while(u!=0){
		sort(m,m+y,cmp2);
		y--;
		u-=2*m[0].countc;
		for(int i=0;i<m[0].chx.size();i++){
			m[m[0].chx[i]].countc--;
		}
		m[0].countc=0;
	}
	cout<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
