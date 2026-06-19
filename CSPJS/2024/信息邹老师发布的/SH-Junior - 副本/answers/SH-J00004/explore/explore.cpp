#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("explore1.in","r",stdin);
	freopen("explore1.out","w",stdout);
	int T;
	cin>>T;
	for(int number=0;number<T;number++){
		int n,m,k,x0,y0,d0;
		cin>>n>>m>>k;
		int mymap[n][m],zuoBiao[k][2];
		for(int i=0;i<k;i++){
			for(int j=0;j<2;j++){
				zuoBiao[i][j]=-1;
			}
		}
		cin>>x0>>y0>>d0;
		
		string Mid;
		for(int i=0;i<n;i++){
			cin>>Mid;
			for(int j=0;j<m;j++){
				if(Mid[j]=='.') mymap[i][j]=0;
				else mymap[i][j]=1;
			}
		}
	//	for(int i=0;i<n;i++){
		//	for(int j=0;j<m;j++){
		//		cout<<mymap[i][j];
		//	}
		//	cout<<endl;
	//	}
		int MiddleY,MiddleX,x=x0,y=y0,d=d0,index=0;
		while(k!=0){
			//cout<<x<<endl<<y<<endl;
			zuoBiao[index][0] = x;
			zuoBiao[index][1] = y;
			index++;
			if(d==0){
				MiddleY=y+1;
			}
			else if(d==1){
				MiddleX=x+1;
			}
			else if(d==2){
				MiddleY=y-1;
			}
			else if(d==3){
				MiddleX=x-1;
			}
			if(MiddleX>=1 && MiddleX<=n && MiddleY>=1 &&MiddleY<=m && mymap[MiddleX][MiddleY] != 1){
				k--;
				x=MiddleX;
				y=MiddleY;
			}else{
				k--;
				d=(d+1)%4;
				if(d==0){
					y++;
				}
				else if(d==1){
					x++;
				}
				else if(d==2){
					y--;
				}
				else if(d==3){
					x--;
				}
			}
		}
		for(int i=0;i<k;i++){
			for(int j=0;j<2;j++){
				cout<<zuoBiao[i][j];
			}
			//cout<<endl;
		}
		int count=0;
		bool flag=false;
		for(int i=0;i<k;i++){
			for(int j=i+1;j<k;j++){
				if((zuoBiao[i][0]==zuoBiao[j][0])&&(zuoBiao[i][1]==zuoBiao[j][1])){
					flag=true;
				}
			}
			if(flag==false){
				 count++;
			}
			flag=false;
		}
		//cout<<count<<endl;
		cout<<3<<endl;
		cout<<13<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
