#ifndef _HM_H_
#define _HM_H_
#include "../queue/queue_mng.h"

//全局只有HM_NUM个HM节点的实体
typedef struct hm_node{

	HMQueue hm_queue;

} HM_Node;

HM_Node *gen_hm_nodes(int hm_nums);						//生成hm_nums个hm节点
void free_hm_nodes(HM_Node *tar_nodes,int hm_nums);		//释放生成的Hm节点

extern HM_Node *global_hm_nodes;		//提供给全局的HM节点接口

#endif