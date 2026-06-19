#include<stdio.h>

int main()
{
	char my_map[1024][1024]={},in,d,dx[4]={0,1,0,-1},
								  	dy[4]={1,0,-1,0};
	long n,m,i,x,y,cnt=0,startx,starty,t,k;
	FILE * fp_in=fopen("explore.in","r"),*fp_out=fopen("explore.out","w");
	fscanf(fp_in,"%ld",&t);
	for(;t>0;t--)
	{
		cnt=1;
		fscanf(fp_in,"%ld %ld %ld\n%ld %ld %c\n",&n,&m,&k,&startx,&starty,&d);
		d-=48;
		for(x=0;x<=n+1;x++)
		{
			for(y=0;y<=m+1;y++)
			{
				if(x==0||y==0||x==n+1||y==m+1)
					my_map[x][y]=-1;
				else
				{
					fscanf(fp_in,"%c",&in);
					if(in=='.')
						my_map[x][y]=0;
					else if(in=='x')
						my_map[x][y]=-1;
				}
			}
			fscanf(fp_in,"\n");
		}
		x=startx;
		y=starty;
		my_map[x][y]=1;
		for(i=0;i<k;i++)
		{
			if(my_map[x+dx[d]][y+dy[d]]>-1)
			{
				x+=dx[d];
				y+=dy[d];
				if(my_map[x][y]==0)
					cnt++,
					my_map[x][y]=1;
			}
			else
				d=(d+1)%4;
		}
		fprintf(fp_out,"%ld\n",cnt);
	}
	fclose(fp_out);
	fclose(fp_in);
	return(0);	
}
