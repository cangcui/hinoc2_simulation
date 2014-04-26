#ifndef _HM_H_
#define _HM_H_
#include "../queue/queue_mng.h"

//全局只有HM_NUM个HM节点的实体
typedef struct HM_Node {
	HMQueue hm_queue;
} HM_Node;

HM_Node *gen_hm_nodes(int hm_num);
extern HM_Node *hm_node;
#endif