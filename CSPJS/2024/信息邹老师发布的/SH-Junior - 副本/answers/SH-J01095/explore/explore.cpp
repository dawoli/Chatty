#include<iostream>
#include<cstring>
using namespace std;
int main(){
	/*思路：
	1.输入整数T（组数）
	2.每一组数据{
		1.读入大小
		2.读入次数
		3.读入位置、方向（d=0表示下，d=1表示右，d=2表示上，d=3表示左）
		4.设置步数为sum、格子数x 
		5.如果机器人走了一步， 则x+1 
	}
	3.依次输出每组结果
	*/
	freopen("explore.in","r",stdin); 
	freopen("explore.out","w",stdout); 
	//int t;
	//cin>>t;
	int t;
	cin>>t;
	int blocks[t]={};
	for(int i=0;i<t;i++){
	int a,b,step;//长、宽、步数
	int x,y,d;//x坐标，y坐标，方向 
	cin>>a>>b>>step;
	cin>>x>>y>>d;
	char map[a+2][b+2];//设置二维数组
	int map2[a+2][b+2]={};//判断各个点是否走到 
	map2[x][y]=1;
	/*test
	[[..x.x],
	 [.x...],
	 [...x.]]
	*/
	for(int j=0;j<a+2;j++){
		for(int k=0;k<b+2;k++){
			if(j==0 || j==a+1 || k==0 || k==b+1){
				map[j][k]='x';
				continue;
			}
			cin>>map[j][k];
		}
	}
	/*for(int j=0;j<a+2;j++){
		for(int k=0;k<b+2;k++){
			cout<<map[j][k];
		}
		cout<<endl;
	}
	*/
	//int blocks=0;
	int k=0;
	while(step>k){
		//cout<<"("<<x<<","<<y<<")\n";
		k++;
		if(d==0){
			if(map[x][y+1]=='x'){
				d++;
				//cout<<"Turn Right0\n";
			}
			else{
				y++;
				blocks[i]+=1-map2[x][y];
				map2[x][y]=1;
				//cout<<"East\n";
			}
			continue;
		}
		if(d==1){
			if(map[x+1][y]=='x'){
				d++;
				//cout<<"Turn Right1\n";
			}
			else{
				x++;
				blocks[i]+=1-map2[x][y];
				map2[x][y]=1;
				//cout<<"South\n";
			}
			continue;
		}
		if(d==2){
			if(map[x][y-1]=='x'){
				d++;
				//cout<<"Turn Right2\n";
			}
			else{
				y--;
				blocks[i]+=1-map2[x][y];
				map2[x][y]=1;
				//cout<<"West\n";
			}
			continue;
		}
		if(d==3){
			if(map[x-1][y]=='x'){
				d=0;
				//cout<<"Turn Right3\n";
			}
			else{
				x--;
				blocks[i]+=1-map2[x][y];
				map2[x][y]=1;
				//cout<<"North\n";
			}
			continue;
		}
	}
	//cout<<"End\n\n\n";
	//for(int j=0;j<a+2;j++){
		//for(int k=0;k<b+2;k++){
			//cout<<map2[j][k]<<" ";
		//}
		//cout<<endl;
	//}
	//cout<<blocks<<endl;
	}
	for(int i=0;i<t;i++){
		cout<<blocks[i]+1<<endl;
	}
	return 0;
}
