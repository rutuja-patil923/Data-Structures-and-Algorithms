node *pre=NULL;
void populateNext(struct node* root)
{
	if(root==NULL) 
		return;
	populateNext(root->left);
	if(pre) 
		pre->next=root;
	pre=root;
	populateNext(root->right);
}