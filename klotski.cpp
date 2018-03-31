/*
*	���ߣ����
*	���䣺nblianyan@qq.com
*	���ڣ�2018-3-31
*	����������ʹ��������������������ֻ��ݵ�
*/



#include "klotski.h"
#include "stdlib.h"
#include "stdio.h"
#include "assert.h"

int PUBLIC_KlotskiNodeID = 0;
short PUBLIC_TargetArray[3][3] = {1,2,3,4,5,6,7,8,0};
int PUBLIC_TreeDepth = 0;
int PUBLIC_KlotskiInputArray[3][3];
Type_KlotskiNode  InputNode ;
int PUBLIC_IsFinDCorret = 0;  //1:�ҵ���0:û��

int klotski_tree_create_child_node(Type_KlotskiNode * FatherNode)
{
	printf("***********************************************************\n");
	printf("���ڵ�ID:%d, ��һ��ִ�еĲ�����%d \n ��ʼ�����ӽڵ�\n",FatherNode->NodeID,FatherNode->lastOperation);
	int i,j,PositionX,PositionY;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(FatherNode->Array[i][j] == 0)
			{
				PositionX = i;
				PositionY = j;
			};
	switch(PositionX)
	{
	case 0:
		{
			if(PositionY == 0)
			{
				if(FatherNode->lastOperation == OperationNone)
				{
					for(i=0;i<2;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					for(i=2;i<4;i++)
						FatherNode->nextNode[i] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0],
						PositionX,PositionY,OperationRight);
					klotski_tree_init_node(FatherNode->nextNode[1],
						PositionX,PositionY,OperationDown);
				}
				else if(FatherNode->lastOperation == OperationLeft)
				{
					FatherNode->nextNode[0] = klotski_tree_malloc_2_child_node();
					FatherNode->nextNode[0]->preNode = FatherNode;
					for(i=1;i<4;i++)
						FatherNode->nextNode[i] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationDown);
				}
				else if(FatherNode->lastOperation == OperationUp)
				{
					FatherNode->nextNode[0] = klotski_tree_malloc_2_child_node();
					FatherNode->nextNode[0]->preNode = FatherNode;
					for(i=1;i<4;i++)
						FatherNode->nextNode[i] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationRight);
				}
			}
			else if(PositionY == 1)
			{
				if(FatherNode->lastOperation == OperationNone)
				{
					for(i=0;i<3;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					FatherNode->nextNode[3] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationDown);
					klotski_tree_init_node(FatherNode->nextNode[1], PositionX,
						PositionY, OperationLeft);
					klotski_tree_init_node(FatherNode->nextNode[2], PositionX,
						PositionY, OperationRight);
				}
				else if(FatherNode->lastOperation == OperationLeft)
				{
					for(i=0;i<2;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					for(i=2;i<4;i++)
						FatherNode->nextNode[i] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0],PositionX,
						PositionY, OperationDown);
					klotski_tree_init_node(FatherNode->nextNode[1],PositionX,
						PositionY, OperationLeft);
				}
				else if(FatherNode->lastOperation == OperationRight)
				{
					for(i=0;i<2;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					for(i=2;i<4;i++)
						FatherNode->nextNode[i] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0],PositionX,
						PositionY, OperationRight);
					klotski_tree_init_node(FatherNode->nextNode[1],PositionX,
						PositionY, OperationDown);
				}
				else if(FatherNode->lastOperation == OperationUp)
				{
					for(i=0;i<2;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					for(i=2;i<4;i++)
						FatherNode->nextNode[i] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0],PositionX,
						PositionY, OperationLeft);
					klotski_tree_init_node(FatherNode->nextNode[1],PositionX,
						PositionY, OperationRight);
				}
			}
			else if(PositionY == 2)
			{
				if(FatherNode->lastOperation == OperationNone)
				{
					for(i=0;i<2;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					for(i=2;i<4;i++)
						FatherNode->nextNode[i] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0],PositionX,
						PositionY, OperationDown);
					klotski_tree_init_node(FatherNode->nextNode[1],PositionX,
						PositionY, OperationLeft);
				}
				else if(FatherNode->lastOperation == OperationRight)
				{
					FatherNode->nextNode[0] = klotski_tree_malloc_2_child_node();
					FatherNode->nextNode[0]->preNode = FatherNode;
					for(i=1;i<4;i++)
						FatherNode->nextNode[i] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0],PositionX,
						PositionY, OperationDown);
				}
				else if(FatherNode->lastOperation == OperationUp)
				{
					FatherNode->nextNode[0] = klotski_tree_malloc_2_child_node();
					FatherNode->nextNode[0]->preNode = FatherNode;
					for(i=1;i<4;i++)
						FatherNode->nextNode[i] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0],PositionX,
						PositionY, OperationLeft);
				}
			}
			break;
		}
	case 1:
		{
			if(PositionY == 0)
			{
				if(FatherNode->lastOperation == OperationNone)
				{
					for(i=0;i<3;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					FatherNode->nextNode[3] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0],PositionX,
						PositionY, OperationDown);
					klotski_tree_init_node(FatherNode->nextNode[1],PositionX,
						PositionY, OperationRight);
					klotski_tree_init_node(FatherNode->nextNode[2],PositionX,
						PositionY, OperationUp);
				}
				else if(FatherNode->lastOperation == OperationLeft)
				{
					for(i=0;i<2;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					for(i=2;i<4;i++)
						FatherNode->nextNode[i] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationDown);
					klotski_tree_init_node(FatherNode->nextNode[1], PositionX,
						PositionY, OperationUp);
				}
				else if(FatherNode->lastOperation == OperationDown)
				{
					for(i=0;i<2;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					for(i=2;i<4;i++)
						FatherNode->nextNode[i] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationRight);
					klotski_tree_init_node(FatherNode->nextNode[1], PositionX,
						PositionY, OperationDown);
				}
				else if(FatherNode->lastOperation == OperationUp)
				{
					for(i=0;i<2;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					for(i=2;i<4;i++)
						FatherNode->nextNode[i] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationRight);
					klotski_tree_init_node(FatherNode->nextNode[1], PositionX,
						PositionY, OperationUp);
				}
			}
			else if(PositionY == 1)
			{
				if(FatherNode->lastOperation == OperationNone)
				{
					for(i=0;i<4;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationDown);
					klotski_tree_init_node(FatherNode->nextNode[1], PositionX,
						PositionY, OperationLeft);
					klotski_tree_init_node(FatherNode->nextNode[2], PositionX,
						PositionY, OperationRight);
					klotski_tree_init_node(FatherNode->nextNode[3], PositionX,
						PositionY, OperationUp);
				}
				else if(FatherNode->lastOperation == OperationLeft)
				{
					for(i=0;i<3;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					FatherNode->nextNode[3] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationDown);
					klotski_tree_init_node(FatherNode->nextNode[1], PositionX,
						PositionY, OperationLeft);
					klotski_tree_init_node(FatherNode->nextNode[2], PositionX,
						PositionY, OperationUp);
				}
				else if(FatherNode->lastOperation == OperationRight)
				{
					for(i=0;i<3;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					FatherNode->nextNode[3] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationDown);
					klotski_tree_init_node(FatherNode->nextNode[1], PositionX,
						PositionY, OperationRight);
					klotski_tree_init_node(FatherNode->nextNode[2], PositionX,
						PositionY, OperationUp);
				}
				else if(FatherNode->lastOperation == OperationUp)
				{
					for(i=0;i<3;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					FatherNode->nextNode[3] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationUp);
					klotski_tree_init_node(FatherNode->nextNode[1], PositionX,
						PositionY, OperationLeft);
					klotski_tree_init_node(FatherNode->nextNode[2], PositionX,
						PositionY, OperationUp);
				}
				else if(FatherNode->lastOperation == OperationDown)
				{
					for(i=0;i<3;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					FatherNode->nextNode[3] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationDown);
					klotski_tree_init_node(FatherNode->nextNode[1], PositionX,
						PositionY, OperationLeft);
					klotski_tree_init_node(FatherNode->nextNode[2], PositionX,
						PositionY, OperationDown);
				}
			}
			else if(PositionY ==2)
			{
				if(FatherNode->lastOperation == OperationNone)
				{
					for(i=0;i<3;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					FatherNode->nextNode[3] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationDown);
					klotski_tree_init_node(FatherNode->nextNode[1], PositionX,
						PositionY, OperationLeft);
					klotski_tree_init_node(FatherNode->nextNode[2], PositionX,
						PositionY, OperationUp);
				}
				else if(FatherNode->lastOperation == OperationDown)
				{
					for(i=0;i<2;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					FatherNode->nextNode[3] = NULL;
					FatherNode->nextNode[2] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationDown);
					klotski_tree_init_node(FatherNode->nextNode[1], PositionX,
						PositionY, OperationLeft);
				}
				else if(FatherNode->lastOperation == OperationUp)
				{
					for(i=0;i<2;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					FatherNode->nextNode[3] = NULL;
					FatherNode->nextNode[2] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationUp);
					klotski_tree_init_node(FatherNode->nextNode[1], PositionX,
						PositionY, OperationLeft);
				}
				else if(FatherNode->lastOperation == OperationRight)
				{
					for(i=0;i<2;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					FatherNode->nextNode[3] = NULL;
					FatherNode->nextNode[2] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationDown);
					klotski_tree_init_node(FatherNode->nextNode[1], PositionX,
						PositionY, OperationUp);
				}
			}
			break;
		}
	case 2:
		{
			if(PositionY == 0)
			{
				if(FatherNode->lastOperation == OperationNone)
				{
					for(i=0;i<2;i++)
						{
							FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
							FatherNode->nextNode[i]->preNode = FatherNode;
						}
						FatherNode->nextNode[3] = NULL;
						FatherNode->nextNode[2] = NULL;
						klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
							PositionY, OperationUp);
						klotski_tree_init_node(FatherNode->nextNode[1], PositionX,
							PositionY, OperationRight);
				}
				else if(FatherNode->lastOperation == OperationLeft)
				{
					FatherNode->nextNode[0] = klotski_tree_malloc_2_child_node();
					FatherNode->nextNode[0]->preNode = FatherNode;
					for(i=1;i<4;i++)
						FatherNode->nextNode[i] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationUp);
				}
				else if(FatherNode->lastOperation == OperationDown)
				{
					FatherNode->nextNode[0] = klotski_tree_malloc_2_child_node();
					FatherNode->nextNode[0]->preNode = FatherNode;
					for(i=1;i<4;i++)
						FatherNode->nextNode[i] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationRight);

				}
			}
			else if(PositionY == 1)
			{
				if(FatherNode->lastOperation == OperationNone)
				{
					for(i=0;i<3;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					FatherNode->nextNode[3] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationLeft);
					klotski_tree_init_node(FatherNode->nextNode[1], PositionX,
						PositionY, OperationRight);
					klotski_tree_init_node(FatherNode->nextNode[2], PositionX,
						PositionY, OperationUp);
				}
				else if(FatherNode->lastOperation == OperationDown)
				{
					for(i=0;i<2;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					FatherNode->nextNode[3] = NULL;
					FatherNode->nextNode[2] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationRight);
					klotski_tree_init_node(FatherNode->nextNode[1], PositionX,
						PositionY, OperationLeft);
				}
				else if(FatherNode->lastOperation == OperationLeft)
				{
					for(i=0;i<2;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					FatherNode->nextNode[3] = NULL;
					FatherNode->nextNode[2] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationUp);
					klotski_tree_init_node(FatherNode->nextNode[1], PositionX,
						PositionY, OperationLeft);
				}
				else if(FatherNode->lastOperation == OperationRight)
				{
					for(i=0;i<2;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					FatherNode->nextNode[3] = NULL;
					FatherNode->nextNode[2] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationUp);
					klotski_tree_init_node(FatherNode->nextNode[1], PositionX,
						PositionY, OperationRight);
				}
			}
			else if(PositionY == 2)
			{
				if(FatherNode->lastOperation ==OperationNone)
				{
					for(i=0;i<2;i++)
					{
						FatherNode->nextNode[i] = klotski_tree_malloc_2_child_node();
						FatherNode->nextNode[i]->preNode = FatherNode;
					}
					FatherNode->nextNode[3] = NULL;
					FatherNode->nextNode[2] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationUp);
					klotski_tree_init_node(FatherNode->nextNode[1], PositionX,
						PositionY, OperationLeft);

				}
				else if(FatherNode->lastOperation == OperationRight)
				{
					FatherNode->nextNode[0] = klotski_tree_malloc_2_child_node();
					FatherNode->nextNode[0]->preNode = FatherNode;
					for(i=1;i<4;i++)
					{
						FatherNode->nextNode[i] = NULL;
					}
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationUp);
				}
				else if(FatherNode->lastOperation == OperationDown)
				{
					FatherNode->nextNode[0] = klotski_tree_malloc_2_child_node();
					FatherNode->nextNode[0]->preNode = FatherNode;
					for(i=1;i<4;i++)
						FatherNode->nextNode[i] = NULL;
					klotski_tree_init_node(FatherNode->nextNode[0], PositionX,
						PositionY, OperationLeft);
				}
			}
			break;
		}
	}
	klotski_check_child_node(FatherNode);
	return 0;
}

int klotski_tree_init_node(Type_KlotskiNode * node, int Position_X, int Position_Y, Enum_Operate Operate)
{
	int i,j;
	PUBLIC_KlotskiNodeID++;
	node->NodeID = PUBLIC_KlotskiNodeID;
	node->TreeDepth = node->preNode->TreeDepth +1;
	node->lastOperation = Operate;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			node->Array[i][j] = node->preNode->Array[i][j];
		node->nextNode[i] = NULL;
	}
	short Temp = node->Array[Position_X][Position_Y];
	if(node == NULL)
		return 0;
	else
	{
		switch (Operate)
		{
		case OperationDown:	node->Array[Position_X][Position_Y]
							= node->Array[Position_X+1][Position_Y];
							node->Array[Position_X+1][Position_Y] = 0;
							break;

		case OperationLeft:	node->Array[Position_X][Position_Y]
							= node->Array[Position_X][Position_Y-1];
							node->Array[Position_X][Position_Y-1] = 0;
							break;

		case OperationRight:node->Array[Position_X][Position_Y] 
							= node->Array[Position_X][Position_Y+1];
							node->Array[Position_X][Position_Y+1] = 0;
							break;

		case OperationUp:	node->Array[Position_X][Position_Y]
							= node->Array[Position_X-1][Position_Y];
							node->Array[Position_X-1][Position_Y] = 0;
							break;

		default:			
							break;
		}
	}
	printf("��ǰ�ӽڵ��ʼ����ϣ��ڵ�IDΪ�� %d, �ڵ����Ϊ��%d , ���ڵ�ID: %d \n",node->NodeID,node->TreeDepth,node->preNode->NodeID);
	printf("  ��ǰ�ڵ����Ϊ��\n");
	printf("    %d %d %d \n",node->Array[0][0],node->Array[0][1],node->Array[0][2]);
	printf("    %d %d %d \n",node->Array[1][0],node->Array[1][1],node->Array[1][2]);
	printf("    %d %d %d \n",node->Array[2][0],node->Array[2][1],node->Array[2][2]);
	if(klotski_compare_node2target(node))
	{
		printf("\n\n   �ýڵ㼴ΪĿ��ڵ�,�ҽ��Ե�����ʽ����չʾ�ýڵ��γɹ���\n");
		print_succeful_path(node);
		PUBLIC_IsFinDCorret = 1;

	}
	return 0;
}

Type_KlotskiNode * klotski_tree_malloc_2_child_node(void)
{
	Type_KlotskiNode * pReturn = new Type_KlotskiNode;
	if((pReturn == NULL)||(pReturn == (Type_KlotskiNode *)0xCDCDCDCD))
		printf("Err:Ϊ �ӽڵ� �����ڴ�ʧ�ܣ�����\n ��ַΪ�� %d\n",pReturn);
	else 
		printf("Ϊ�ڵ������ڴ�ɹ� %d \n",pReturn);
	return pReturn;

}

void klotski_check_child_node(Type_KlotskiNode * FatherNode)
{
	int i=0;
	for(i=0;i<4;i++)
	{
		if(FatherNode->nextNode[i] == (Type_KlotskiNode *)0xCDCDCDCD)
		{
			printf("\n\n\n");
			printf("Err:���ڵ���ӽڵ�������⣺\n");
			printf("    ���ڵ�ID: %d , ��%d���ӽڵ��ڴ����,�ӽڵ��ַΪ�� %d \n",FatherNode->NodeID,
					i,FatherNode->nextNode[i]);
			printf("    ���ڵ����״̬Ϊ��\n");
			printf("        %d %d %d \n",FatherNode->Array[0][0],FatherNode->Array[0][1],
					FatherNode->Array[0][2]);
			printf("        %d %d %d \n",FatherNode->Array[1][0],FatherNode->Array[1][1],
					FatherNode->Array[1][2]);
			printf("        %d %d %d \n",FatherNode->Array[2][0],FatherNode->Array[2][1],
					FatherNode->Array[2][2]);
			FatherNode->nextNode[i] = NULL;
		}

	}
}

int klotski_tree_create_tree(Type_KlotskiNode * TreeHead, int TreeDepth)
{
	int i;
	if(PUBLIC_IsFinDCorret)
		return 0;
	if(TreeDepth <= 1)
	{
		for(i=0;i<4;i++)
		{
			TreeHead->nextNode[i] = NULL;
		}
		return 0;
	}
	else
	{
		klotski_tree_create_child_node(TreeHead);
		for(i=0;i<4;i++)
		{
			if(TreeHead->nextNode[i] != NULL)
			{
				if(TreeHead->TreeDepth >= 16 )
				{
					if(klotski_seek_same_node(TreeHead,TreeHead->preNode) == 0)
						klotski_tree_create_tree(TreeHead->nextNode[i],TreeDepth-1);
					else 
						return 0; 
				}
				else 
					klotski_tree_create_tree(TreeHead->nextNode[i],TreeDepth-1);
			}

		}
		return 0;
	}
}

int klotski_compare_node2target(Type_KlotskiNode * Node)
{
	int i,j,IsEqualFlag = 1;  //1 ��ȣ�0 �����
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(Node->Array[i][j] != PUBLIC_TargetArray[i][j])
			{
				IsEqualFlag = 0;
				break;
			}
		}
		if(!IsEqualFlag )
				break;
	}
	return IsEqualFlag;
}

void print_succeful_path(Type_KlotskiNode * TailNode)
{
	Type_KlotskiNode * pPrintNode = TailNode;
	while(pPrintNode->preNode != NULL)
	{
		print_node(pPrintNode);
		pPrintNode = pPrintNode->preNode;
	}
	printf("��������");
}
void print_node(Type_KlotskiNode * Node)
{
	int i,j;
	printf("ID:%d\n",Node->NodeID);
	printf("���ڲ���:%d\n",Node->TreeDepth);
	for(i=0;i<3;i++)
	{
		printf(" ");
		for(j=0;j<3;j++)
			printf(" %d",Node->Array[i][j]);
		printf("\n");
	}
	printf("\n   A\n");
	//printf("  A A\n");
	printf("   |\n");
	printf("   |\n\n");
}

int klotski_compare_node2node(Type_KlotskiNode * NowNode, Type_KlotskiNode * LastNode)
{
	int i,j;
	int IsSameFlag = 1;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			if(NowNode->Array[i][j] != LastNode->Array[i][j])
			{
				IsSameFlag = 0;
				break;
			}
		if(!IsSameFlag)
			break;
	}
	return IsSameFlag;
}

int klotski_seek_same_node(Type_KlotskiNode * NowNode, Type_KlotskiNode * FatherNode) //1:���� 2��������
{
	if(klotski_compare_node2node(NowNode ,FatherNode ))
		return 1;
	else 
	{
		if(FatherNode->preNode != NULL)
			klotski_seek_same_node(NowNode,FatherNode->preNode);
		else 
			return 0;
	}
}

void klotski_get_input(void)
{
	int i,j;
	printf("�������������õ� ����������� ��������(����):");
	scanf("%d",&PUBLIC_TreeDepth);
	printf("���������ľ���ʾ�����£�\n");
	printf("�����������ľ���Ϊ��\n");
	printf("				1 2 3\n");
	printf("				4 5 6\n");
	printf("				7 8 0\n");
	printf("��ô��Ӧ�����룺 1,2,3,4,5,6,7,8,0\n");
	printf("\n  ���������ľ���: \n");
	scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d",
		PUBLIC_KlotskiInputArray[0],PUBLIC_KlotskiInputArray[0] +1,PUBLIC_KlotskiInputArray[0] +2,
		PUBLIC_KlotskiInputArray[1],PUBLIC_KlotskiInputArray[1] +1,PUBLIC_KlotskiInputArray[1] +2,
		PUBLIC_KlotskiInputArray[2],PUBLIC_KlotskiInputArray[2] +1,PUBLIC_KlotskiInputArray[2] +2);
	printf("����������:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			InputNode.Array[i][j] = PUBLIC_KlotskiInputArray[i][j];
			printf(" %d",InputNode.Array[i][j]);
		}
		printf("\n");
	}
	InputNode.lastOperation = OperationNone;
	InputNode.NodeID = 0;
	InputNode.preNode = NULL;
	InputNode.TreeDepth = 0;
	PUBLIC_KlotskiNodeID = 0;

}


void klotski_start(void)
{

	klotski_get_input();
	klotski_tree_create_tree(&InputNode,PUBLIC_TreeDepth);
	if(PUBLIC_IsFinDCorret)
		PUBLIC_IsFinDCorret = 0;
	else 
		printf("Warring:    ��ǰ�����δ�ҵ�����·��   \n");
}