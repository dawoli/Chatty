#include <iostream>
#include <string>
using namespace std;
int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	int T,n,m,k,x,y,d,cnt;
	
	cin>>T;
	int ans[T];
	for(int i=0;i<T;i++){
		cnt=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		x-=1;
		y-=1;
		string map[n];
		for(int j=0;j<n;j++) cin>>map[j];
		map[x][y]='o';
		for(int l=0;l<k;l++){
			if(d==0){
				if(y+1<m && map[x][y+1] != 'x') y+=1;
				else d=1;
			}
			else if(d==1){
				if(x+1<n && map[x+1][y] != 'x') x+=1;
				else d=2;
			}
			else if(d==2){
				if(y>0 && map[x][y-1] != 'x') y-=1;
				else d=3;
			}
			else{
				if(x>0 && map[x-1][y] != 'x') x-=1;
				else d=0;
			};
			map[x][y]='o';
		};
		for(int a=0;a<n;a++)
			for(int b=0;b<m;b++)
				if(map[a][b]=='o') cnt+=1;
		ans[i]=cnt;
	};
	for(int c=0;c<T;c++) cout<<ans[c]<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
