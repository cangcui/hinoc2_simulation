#ifndef _HB_H_
#define _HB_H_
#include "../queue/queue_mng.h"

// ȫ��ֻ��1��HB�ڵ��ʵ��
typedef struct HB_Node{
	HBQueue hb_queue;
}HB_Node;

HB_Node *gen_hb_node(int hm_num);

extern HB_Node *hb_node;
#endif