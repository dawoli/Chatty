#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    short T;
    cin>>T;
    do{
    	int sum=1;
    	T--;
    	int n,m;
    	int k;
    	cin>>n>>m>>k;
    	int d;
    	int x,y;
    	cin>>x>>y>>d;
    	char _map[n][m];
    	for(int i=0;i<n;i++)
		{
    		for(int j=0;j<m;j++){
    			cin>>_map[i][j];
			}
		}
		switch(d%4){
			case 0:
				if(_map[x+1][y]=='.'){
					x++;
					sum++;
				}
			case 1:
				if(_map[x][y+1]=='.'){
					y++;
					sum++;
				}
			case 2:
				if(_map[x-1][y]=='.'){
					x--;
					sum++;
				}
			case 3:
				if(_map[x][y-1]=='.'){
					y--;
					sum++;
				}
		}
	}
	while(T);
	cout<<1;
    return 0;
}
