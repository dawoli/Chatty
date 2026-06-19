#include<stdio.h>
using namespace std;
char grid[1005][1005]={0};
int checknxt(int x,int y,int row,int col)
{
	if((0<=x)&&(x<row))
	{
		if((0<=y)&&(y<row))
		{
			if (grid[x][y]!=2)
			return 1;
		}
	}
	return 0;
}
int printgrid(int row,int col)
{
	//debug
	printf("\n   ");
	for(int r=0;r<row;r++)printf("%3d",r);
	for(int c=0;c<col;c++)
	{
		printf("\n%3d",c);
		for(int r=0;r<row;r++)
		{
			switch(grid[c][r]) 
			{
				case 0:printf(" . ");break;
				case 1:printf(" p ");break;
				case 2:printf(" X ");break;
			}
		}
	}
	printf("\n");
	return 0;
}
int main()
{
	FILE* inpfile=fopen("explore.in","r");
	FILE* outfile=fopen("explore.out","w");
	int tns;
	fscanf(inpfile,"%d\n",&tns);
	for(int t=0;t<tns;t++)
	{
		int row,col,opn,x,y,d;
		fscanf(inpfile,"%d %d %d\n%d %d %d\n",&col,&row,&opn,&x,&y,&d);
		for(int c=0;c<col;c++)
		{
			for(int r=0;r<row;r++)
			{
				char tmp;
				if(r==row-1)fscanf(inpfile,"%c\n",&tmp);
				else fscanf(inpfile,"%c",&tmp);
				if(tmp=='x')grid[c][r]=2;
				else grid[c][r]=0;
			}
		}
		x--;
		y--;
		for(int op=0;op<opn;op++)
		{
			int nx,ny;
			switch(d)
			{
				case 0:nx=x;ny=y+1;break;
				case 1:nx=x+1;ny=y;break;
				case 2:nx=x;ny=y-1;break;
				case 3:nx=x-1;ny=y;break;
			}
			if(checknxt(nx,ny,row,col)){
				grid[x][y]=1;
				x=nx;y=ny;
				grid[x][y]=1;
			}
			else
			{
				d=(d+1)%4;
			}
			//printgrid(row,col);
			//printf("%d x:%d y:%d d:%d op:%d\n",t,x,y,d,op);
			//printf("nx%d ny%d v%d\nr%d c%d\n",nx,ny,(int)grid[nx][ny],row,col);
			
		}
		int cnt=0;
		for(int r=0;r<row;r++)
		{
			for(int c=0;c<col;c++)
			{
				if(grid[c][r]==1)cnt++; 
			} 
		}
		fprintf(outfile,"%d\n",cnt);
	}
	return 0;
}
