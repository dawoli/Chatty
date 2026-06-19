#include<cstdio>
#include<cstring>
int n,b[10][20];
char str[15];
int answer;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		memset(str,0,sizeof(str));
		scanf("%s",str);
		int q1,q2;
		q1=0;q2=0;
		switch(str[0]){
			case 'D':{
				q1=1;
				break;
			}
			case 'C':{
				q1=2;
				break;
			}
			case 'H':{
				q1=3;
				break;
			}
			case 'S':{
				q1=4;
				break;
			}
		}
		if(str[1]>='2' && str[1]<='9'){
			q2=str[1]-'0';
		}
		else if(str[1]=='A'){
			q2=1;
		}
		else if(str[1]=='T'){
			q2=10;
		}
		else if(str[1]=='J'){
			q2=11;
		}
		else if(str[1]=='Q'){
			q2=12;
		}
		else if(str[1]=='K'){
			q2=13;
		}
		b[q1][q2]=1;
	}
	answer=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(b[i][j]==0){
				answer++;
			}
		}
	}
	printf("%d\n",answer);
	fclose(stdin);fclose(stdout);
	return 0;
}
