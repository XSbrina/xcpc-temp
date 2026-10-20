#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>
typedef struct Tree{
	char data;
	struct Tree*l,*r;
}Tree,*Ptree;
char p[20005],q[20005];
int jkl[26];
int len_p,len_q;
void init(){
	scanf("%s",p+1);
	scanf("%s",q+1);
	len_p=strlen(p+1);
	len_q=strlen(q+1);
	for(int i=1;i<=len_q;i++){
		char c=q[i];
		jkl[c-'A']=i;
	}
}
Ptree build(int p_l,int p_r,int q_l,int q_r) {
    if (p_l>p_r||q_l>q_r){
        return NULL;
    }
    char root_val=p[p_l];
    Ptree root=(Ptree)malloc(sizeof(Tree));
    root->data=root_val;
    root->l=NULL;
    root->r=NULL;
    int root_pos=jkl[root_val-'A'];
    int left_size=root_pos-q_l;
    root->l=build(p_l+1,p_l+left_size,q_l,root_pos-1);
    root->r=build(p_l+left_size+1,p_r,root_pos+1,q_r);
    return root;
}
void later(Ptree t){
	if(t){
		later(t->l);
		later(t->r);
		printf("%c",t->data);
	}
}
int main(){
	init();
	Ptree t=build(1,len_p,1,len_q);
	later(t);
	return 0;
}
