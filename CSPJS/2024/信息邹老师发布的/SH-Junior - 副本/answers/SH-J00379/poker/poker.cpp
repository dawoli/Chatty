#include<fstream>
std::ifstream fin("poker.in");
std::ofstream fout("poker.out");
std::string a[53];
bool poker[5][14];
int main(){
	int n;
	fin>>n;
	for(int i=1;i<=n;i++){
		fin>>a[i];
		if(a[i][0]=='D')
		{
			if(a[i][1]=='A')
				poker[1][1]=1;
			else if(a[i][1]=='J')
				poker[1][11]=1;
			else if(a[i][1]=='Q')
				poker[1][12]=1;
			else if(a[i][1]=='K')
				poker[1][13]=1;
			else if(a[i][1]=='T')
				poker[1][10]=1;
			else{
				int s=a[i][1]-'0';
				poker[1][s]=1;
			}
		}
		if(a[i][0]=='C')
		{
			if(a[i][1]=='A')
				poker[2][1]=1;
			else if(a[i][1]=='J')
				poker[2][11]=1;
			else if(a[i][1]=='Q')
				poker[2][12]=1;
			else if(a[i][1]=='K')
				poker[2][13]=1;
			else if(a[i][1]=='T')
				poker[2][10]=1;
			else{
				int s=a[i][1]-'0';
				poker[2][s]=1;
			}
		}
		if(a[i][0]=='H')
		{
			if(a[i][1]=='A')
				poker[3][1]=1;
			else if(a[i][1]=='J')
				poker[3][11]=1;
			else if(a[i][1]=='Q')
				poker[3][12]=1;
			else if(a[i][1]=='K')
				poker[3][13]=1;
			else if(a[i][1]=='T')
				poker[3][10]=1;
			else{
				int s=a[i][1]-'0';
				poker[3][s]=1;
			}
		}
		if(a[i][0]=='S')
		{
			if(a[i][1]=='A')
				poker[4][1]=1;
			else if(a[i][1]=='J')
				poker[4][11]=1;
			else if(a[i][1]=='Q')
				poker[4][12]=1;
			else if(a[i][1]=='K')
				poker[4][13]=1;
			else if(a[i][1]=='T')
				poker[4][10]=1;
			else{
				int s=a[i][1]-'0';
				poker[4][s]=1;
			}
		}
		
	}
	int ans=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(!poker[i][j])
				ans++;
		}
	}
	fout<<ans;
	return 0;
}
