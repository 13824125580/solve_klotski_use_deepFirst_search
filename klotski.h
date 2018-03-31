/*
*	���ߣ����
*	���䣺nblianyan@qq.com
*	���ڣ�2018-3-31
*	����������ʹ��������������������ֻ��ݵ�
*/




#ifndef __KLOTSKI_H
#define __KLOTSKI_H 

typedef struct klotski_struct_1 Type_KlotskiNode;
typedef enum klotski_enum_1 Enum_Operate;


extern int PUBLIC_KlotskiNodeID ;
extern short PUBLIC_TargetArray[3][3];
extern int PUBLIC_TreeDepth;
extern int PUBLIC_KlotskiInputArray[3][3];
extern Type_KlotskiNode InputNode ;

/*
���ƣ�struct klotski_struct_1
���ܣ����������������������ʹ�õġ������еĽڵ�
*/
struct klotski_struct_1	
{
	int NodeID;								//�ڵ�ID��ÿ���ڵ�IDȫ��Ψһ
	int TreeDepth;							//��ǰ�ڵ����ڵ����е�λ�õ����
	Enum_Operate lastOperation;				//��һ�����ɱ��ڵ���ʹ�õĲ���
	short Array[3][3];						//���Ĳ��֣���¼���ڵ�ľ���
	Type_KlotskiNode * preNode;				//ָ�룬ָ�򸸽ڵ�
	Type_KlotskiNode * nextNode[4];			//ָ�����飬����ָ���ӽڵ�
};


/*
���ƣ�enum klotski_enum_1
���ܣ���������ĳ�ڵ������ӽڵ���ִ�еĲ���
*/
enum klotski_enum_1	
{
	OperationDown = 0,						//���֡�0�� �����ƶ�
	OperationUp   = 1,						//���֡�0�� �����ƶ�
	OperationRight= 2,						//���֡�0�� �����ƶ�
	OperationLeft = 3,						//���֡�0�� �����ƶ�
	OperationNone = 4						//���֡�0�� �޲���
};


/*--------------------------------------------------------------------------------------------------------------
���ƣ�klotski_tree_create_child_node
������FatherNode,���������ӽڵ�Ľڵ��ָ��
����ֵ��������
*/
int klotski_tree_create_child_node(Type_KlotskiNode * FatherNode);

/*--------------------------------------------------------------------------------------------------------------
���ƣ�klotski_tree_init_node
������	node����Ҫ��ʼ�����ӽڵ��ָ��
		Position_X,���ڵ�ľ��������֡�0����λ�õ�����
		Position_Y,���ڵ�ľ��������֡�0����λ�õ�����
		Operation����Ҫ���ӽڵ�ִ�еĲ���
����ֵ��������
���ܣ�	����Operation�� node�ڵ��е����ݽ��г�ʼ��
*/
int klotski_tree_init_node(Type_KlotskiNode * node, int Position_X, int Position_Y, Enum_Operate Operate);

/*---------------------------------------------------------------------------------------------------------------
���ƣ�klotski_tree_malloc_2_child_node
��������
����ֵ��ָ������ɹ����ڴ�ĵ�ַ������NULL
���ܣ�Ϊ�ӽڵ�����Type_KlotskiNode���͵ĵ�ַ�ռ�
*/
Type_KlotskiNode * klotski_tree_malloc_2_child_node(void);

/*--------------------------------------------------------------------------------------------------------------
���ƣ�klotski_check_child_node
���������ڵ�ָ��
����ֵ����
���ܣ����FatherNode���ӽڵ�ָ���Ƿ��쳣
*/
void klotski_check_child_node(Type_KlotskiNode * FatherNode);

/*---------------------------------------------------------------------------------------------------------------
���ƣ�klotski_tree_create_tree
������TreeHead,���Ķ���
	  TreeDepth,ϣ�����ɵ��������
����ֵ��������
���ܣ������� TreeHeadΪ���㡢���ΪTreeDepth ����
*/
int klotski_tree_create_tree(Type_KlotskiNode * TreeHead, int TreeDepth);
/*--------------------------------------------------------------------------------------------------------------
���ƣ�klotski_compare_node2target
������Node,��Ҫ���бȽϵĽڵ�
����ֵ�� 0����Ŀ��״̬����ȣ�
		 1����Ŀ��״̬���
���ܣ���Node�ڵ���Ŀ����бȽϣ��ж��Ƿ���ͬ
*/
int klotski_compare_node2target(Type_KlotskiNode * Node);
/*-------------------------------------------------------------------------------------------------------------
���ƣ�print_succeful_path
������TailNode ����ĩ�˽ڵ�
����ֵ����
���ܣ��ڿ���̨��ӡ����Ŀ���������Ľڵ�·��
*/
void print_succeful_path(Type_KlotskiNode * TailNode);
/*------------------------------------------------------------------------------------------------------------
���ƣ�print_node
������Node����Ҫ��ʾ�Ľڵ�
����ֵ����
���ܣ���ָ���ڵ�ľ����ӡ
*/
void print_node(Type_KlotskiNode * Node);
/*------------------------------------------------------------------------------------------------------------
���ƣ�klotski_seed_same_node
������  NowNode,��ҪѰ����ͬ�ڵ��ԭ�ڵ�
		FatherNode,��Ҫ��NowNode���бȽϵĽڵ�����ĩ�˽ڵ�
����ֵ��1��������ͬ�ڵ�
		0����������ͬ�ڵ�
���ܣ���FatherNode�ڵ㼰�丸ϵ���еĽڵ���Ѱ����NowNode�ڵ�ľ�����ͬ�Ľڵ�
*/
int klotski_seek_same_node(Type_KlotskiNode * NowNode, Type_KlotskiNode * FatherNode); //1:���� 2��������

/*-----------------------------------------------------------------------------------------------------------
���ƣ�klotski_compare_node2node
������NowNode����Ҫ���бȽϵ�ԭ�ڵ�
	  LastNode����Ҫ���бȽϵĽڵ�
����ֵ��0������ͬ
		1����ͬ
���ܣ���NowNode�ڵ���LastNode�ڵ�ľ�����бȽ�
*/
int klotski_compare_node2node(Type_KlotskiNode * NowNode, Type_KlotskiNode * LastNode);
/*
���ƣ�klotski_get_input
���ܣ���ȡ������Ϣ
*/
void klotski_get_input(void);
/*
���ܣ���ʼ����
*/
void klotski_start(void);

#endif
