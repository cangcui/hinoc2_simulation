#ifndef _HM_H_
#define _HM_H_
#include "../queue/queue_mng.h"

//ȫ��ֻ��HM_NUM��HM�ڵ��ʵ��
typedef struct hm_node{

	HMQueue hm_queue;

} HM_Node;

HM_Node *gen_hm_nodes(int hm_nums);						//����hm_nums��hm�ڵ�
void free_hm_nodes(HM_Node *tar_nodes,int hm_nums);		//�ͷ����ɵ�Hm�ڵ�

extern HM_Node *global_hm_nodes;		//�ṩ��ȫ�ֵ�HM�ڵ�ӿ�

#endif