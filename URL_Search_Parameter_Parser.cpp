search_t *get_param_by_key(char *url, char *key)
{
	search_t* ans;
	ans = (search_t*)calloc(1,sizeof (search_t) );
	
	ans -> key = (char*)calloc(5000,sizeof (char));
	ans -> value = (char*)calloc(5000,sizeof (char));
	
	char u[5000] = {};
	int index = 0;
	
	int len = strlen(url) , c = 0;
	for(int i=0;i<len;i++)
	{
		if( url[i] == '?' )
		{
			c = 1;
			continue;
		}
		if( i + strlen(key) - 1 < len )
		{
			int len2 = strlen(key) , total = 0 , idx = 0;
			for(int k=0;k<len2;k++)
			{
				if( url[i+k] == key[k] ) total++;
			}			
			
			if( total == len2 && c == 1 )
			{
				for(int k=i+len2+1;k<len;k++)
				{
					if( url[k] == '/' || url[k] == ':' || url[k] == '?' || url[k] == '#' ) break;
					if( url[k] == '&' ) break;
					u[index++] = url[k];
				}
				strcpy(ans->key,key);
				strcpy(ans->value,u);
				return ans;
			}
		}
	}	
	
	return NULL;
}