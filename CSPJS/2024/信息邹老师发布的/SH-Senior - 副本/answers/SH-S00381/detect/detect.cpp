#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V;//数据组数 车辆数量 测速仪数量 主干道长度 道路限速 
int d[100005],v[100005],a[100005];//距离 初速度 加速度 
int p[100005];//测速器位置 
int f[101][101];
int ans1 = 0,ans2 = 0;
bool check()
{
//	cout << "///////////////\n";
	for(int i=1;i<=ans1;i++){
		int t=0;
		for(int j=1;j<=m;j++){
//			cout << f[i][j] << " ";
			t+=f[i][j];
		}
//		cout << endl;
		if(t==0) return false; 
	}
	return true;
}
void dfs(int num,int del)//遍历到了第num个测速器 已经删了del个测速器 
{
	if(num==m+1) ans2 = max(ans2,del);
	if(num==m+1) return;
	int c[114];
	for(int i=1;i<=ans1;i++){
		c[i] = f[i][num];
		f[i][num]=0;
	}//删了第num个 
	if(check()) dfs(num+1,del+1);
	for(int i=1;i<=ans1;i++){
		f[i][num] = c[i];
	}
	dfs(num+1,del);//不删num个 
	return;
} 
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> T;
	while(T--)
	{
		int flagA =true,lastp=0;//特殊性质a 
		int flagB =true;//特殊性质b 
		ans1 = 0;//超速个数 
		cin >> n >> m >> L >> V;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&d[i],&v[i],&a[i]);
			if(a[i]!=0) flagA = false;
			if(a[i]<=0) flagB = false; 
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&p[i]);
		}
		if(flagA){//性质A 
			for(int i=1;i<=n;i++){
				if(v[i]>V&&d[i]<=p[m]) ans1++;
			}
			if(ans1==0) m++;
			cout << ans1 << " " << m-1 << endl;
			continue;
		}
		if(flagB){//性质B 
			for(int i=1;i<=n;i++){
				if(v[i]*v[i]+2*a[i]*(p[m]-d[i])>V*V&&d[i]<=p[m]) ans1++;
			}
			if(ans1==0) m++;
			cout << ans1 << " " << m-1 << endl;
			continue;
		} 
		for(int i=1;i<=100;i++) for(int j=1;j<=100;j++) f[i][j] = 0;
		for(int i=1;i<=n;i++){
			bool cs = false;//不超速 
			for(int j=1;j<=m;j++){
				if(p[j]<d[i]) continue;
				else{
					if(v[i]*v[i]+2*a[i]*(p[j]-d[i])>V*V){//超速 
						if(cs==false){
							ans1++;
						}
						cs = true;
						f[ans1][j]=1;//第i辆车在第j号超速 
//						cout << "i:" << i << endl;
//						cout << "j:" << j << endl;
//						cout << "V^2:" << v[i]*v[i]+2*a[i]*(p[j]-d[i]) << endl;
					}
				}
			}
		}
		ans2 = n-ans1;
		dfs(1,0); 
		cout << ans1 << " " << ans2 << endl;
	} 
	return 0;
}
