void init_node(node_t *node, const char *id, node_t *paths[])
{
	node -> id = malloc(1001*sizeof(char) );
	
	node -> paths = (struct node_s **)malloc(60*sizeof(struct node_s*) );
	for(int i=0;i<32;i++) node -> paths[i] = (struct node_s*)malloc(1*sizeof(struct node_s) );
	
	strcpy(node->id,id);
	
	for(int i=0;i<16;i++) node -> paths[i] = paths[i];
	
	return;
}
void deinit_node(node_t *node)
{
	return;
}
node_t *step_to_next(node_t *curr, int next_idx)
{
	printf("%s\n",curr -> id);
	if( next_idx == -1 ) return NULL;
	return curr -> paths[next_idx];
}