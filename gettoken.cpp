#include <string.h>
char u[18000] = {};
char ans[8000] = {};
char *gettoken(char *str, const char *sep)
{
	int len = strlen(str) , len2 = strlen(sep);
	
	int idx = 0;
	
	for(int i=0;i<len;i++)
	{
		int ok = 1;
		for(int k=0;k<len2;k++)
		{
			if( str[i] == sep[k] ) ok = 0;
		}
		
		if( ok == 0 )
		{
			if( idx == 0 ) continue;
			idx = 0;
			
			printf("%s\n",u);
			strcpy(u,"");
		}
		else
		{
			char add[2] = {};
			add[0] = str[i];
			strcat(u,add);
			idx++;
		}
	}
	
	//printf("%s",ans);
	
	return NULL;
}