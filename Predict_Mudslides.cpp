#include <stdio.h>

int a[1005][1005],b[1005][1005],v[10][10],c[10][10];

int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	x++ , y++;
	for(int i=1;i<=5;i++)
	{
		for(int k=1;k<=5;k++)
		{
			scanf("%d",&a[i][k]);
		}
	}
	
	b[x][y] = 1;
	
	int ans  = 0;
	
	for(int t=0;t<30;t++)
	{
		for(int k=1;k<=5;k++)
		{
			for(int j=1;j<=5;j++)
			{
				if( a[k][j] == 2 && b[k][j] == 1 && v[k][j] == 0 )
				{
					//printf("%d %d\n",k,j);
					ans++;
					v[k][j] = 1;
				}
				else if( a[k][j] == 1 && b[k][j] == 1 ) b[k][j] = 0;
			}
		}
		
		for(int i=1;i<=5;i++)
		{
			for(int k=1;k<=5;k++)
			{
				c[i][k] |= b[i+1][k];
				c[i][k] |= b[i-1][k];
				c[i][k] |= b[i][k+1];
				c[i][k] |= b[i][k-1];
			}
		}
		
		for(int i=1;i<=5;i++) for(int k=1;k<=5;k++) b[i][k] = c[i][k] , c[i][k] = 0;
	}
	
	printf("%d\n",ans);
}