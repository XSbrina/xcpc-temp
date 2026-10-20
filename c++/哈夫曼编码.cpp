#include<stdio.h>
#include<string.h>
struct jkl{
	char c;
	int data;
	int parent;
	int l,r;
}f[200];  //足够存储哈夫曼树节点
char s[100];     //待编码的报文
char code[100005];  //存储编码结果
int n;           //字符个数
void init(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf(" %c",&f[i].c);  //空格自动跳过空白符
		f[i].parent=-1;
		f[i].l=-1;
		f[i].r=-1;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&f[i].data);
	}
	scanf("%s",s);  //读取报文
}
//构建哈夫曼树
void build(){
	int m=2*n-1;  //哈夫曼树总节点数
	int i,j;
	//初始化所有非叶子节点
	for(i=n;i<m;i++){
		f[i].parent=-1;
		f[i].l=-1;
		f[i].r=-1;
		f[i].c=0;  //非叶子节点无字符
	}
	// 循环构建：每次选两个权值最小的节点合并
	for(i=n;i<m;i++){
		//找到最小的两个节点,未被合并 parent=-1
		int min1=-1,min2=-1;
		for(j=0;j<i;j++){
			if(f[j].parent==-1){
				if(min1==-1||f[j].data<f[min1].data){
					min2=min1;
					min1=j;
				}
				else if(min2==-1||f[j].data<f[min2].data){
					min2=j;
				}
			}
		}
		//小权值放左，大权值放右
		if(f[min1].data>f[min2].data){
			int t=min1;
			min1=min2;
			min2=t;
		}
		//建立父子关系
		f[min1].parent=i;
		f[min2].parent=i;
		f[i].l=min1;   //左孩子（小）
		f[i].r=min2;   //右孩子（大）
		f[i].data=f[min1].data+f[min2].data;
	}
}
// 生成每个字符的哈夫曼编码
void get_code(){
	// 临时存储编码
	char temp[100];
	int k,pos,p;
	for(int i=0;i<n;i++){
		pos=0;
		k=i;
		// 从叶子向上遍历到根
		while(f[k].parent != -1){
			p=f[k].parent;
			// 左孩子=0，右孩子=1
			if(f[p].l==k) temp[pos++]='0';
			else temp[pos++]='1';
			k=p;
		}
		// 反转得到正确编码
		for(int j=0;j<pos/2;j++){
			char t=temp[j];
			temp[j] = temp[pos-j-1];
			temp[pos-j-1] = t;
		}
		temp[pos] ='\0';
		// 存入编码表（用字符对应编码）
		strcat(code + (f[i].c * 100), temp);
	}
}
// 编码函数：将报文转为二进制串
void encode(char *res){
	res[0]='\0';
	for(int i=0;s[i]!='\0';i++){
		strcat(res,code+(s[i]*100));
	}
}
// 解码函数：二进制串还原报文
void decode(char *res,char*bin_str){
	int root=2*n-2; //根节点下标
	int cur=root;
	int idx=0;	
	res[0]='\0';
	for(int i=0;bin_str[i]!='\0';i++){
		//0走左,1走右
		if(bin_str[i]=='0') cur=f[cur].l;
		else cur=f[cur].r;
		//到达叶子节点，取出字符
		if(f[cur].l==-1&&f[cur].r==-1){
			res[idx++]=f[cur].c;
			cur=root;
		}
	}
	res[idx]='\0';
}

int main(){
	memset(code,0,sizeof(code));  //初始化编码表
	init();     // 输入初始化
	build();    // 构建哈夫曼树
	get_code(); // 生成编码
	//编码
	char bin_code[100005]={0};
	encode(bin_code);
	//解码
	char decode_msg[100]={0};
	decode(decode_msg,bin_code);
	printf("%s\n",bin_code);
	printf("%s\n",decode_msg);
	return 0;
}
