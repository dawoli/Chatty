#include<bits/stdc++.h>
using namespace std;
int total[1000000][1000000];
vector<bool> visited;
const int N = 1e9;
int all[N];
int main(){
	//freopen("club.cpp","r",stdin);
	//freopen("club.cpp","w",stdout);
	int count = 0;
	int minn1;
	int count_a = 0;
	int count_b = 0;
	int count_c = 0;
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){	
		int minn = 10000000;
		int max2;
		int total[10000][10000];
		int m;
		cin>>m;
		for(int j = 0;j<m;j++){
			for(int n = 0;n<3;n++){
				int a;
				cin>>a;
				total[j][n] = a;
			}
			
			for(int y = 0;y<m;y+=3){
				all[y] = max(total[j][0],total[j][1],total[j][2]);
				if(max(total[j][0],total[j][1],total[j][2])==total[j][0])
					count_a += 1;
				if(max(total[j][0],total[j][1],total[j][2])==total[j][1])
					count_b += 1;
				if(max(total[j][0],total[j][1],total[j][2])==total[j][2])
					count_c += 1;
				}
			if(max(count_a,count_b,count_c)<=m/2){
				for(int x = 0;x<m;x++){
					count+=all[x];
			}
			}
			else{
				for(int x= 0;x<m;x++){
					if(minn>=all[j]){
						minn = all[j];
						minn1 = j;
					}
			}
				int max1 = max(total[minn1][0],total[minn1][1],total[minn1][2]);
				int max3 = min(total[minn1][0],total[minn1][1],total[minn1][2]);
				if (max1==total[minn1][0]){
					if(max3==total[minn1][1])
						int max2 = total[minn1][2];
					else{
						int max2 = total[minn1][1];
					}
				}
				if (max1==total[minn1][1]){
					if(max3==total[minn1][0])
						max2 = total[minn1][2];
					else{
						max2 = total[minn1][0];
					}
				}
				if (max1==total[minn1][2]){
					if(max3==total[minn1][1])
						max2 = total[minn1][0];
					else{
						max2 = total[minn1][1];
					}
				}
				all[minn1] =  max2;
				for(int v = 0;v<m;v++){
					count+=all[v];
				}
				
			}
	}
		cout<<count<<endl;
	}
	return 0;
	}
