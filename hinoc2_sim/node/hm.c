#include "hm.h"

HM_Node *hm_node;

HM_Node *gen_hm_nodes(int hm_num)
{
	
	int hm_id=0;
	int updown=0;
	int prio_id=0;
	// 根据HM个数动态开辟HM_NODE
	HM_Node *hm_nodes = (HM_Node *)malloc(hm_num*sizeof(HM_Node));
	// 初始化每个HM的对头信息
	for(hm_id=0; hm_id < hm_num; hm_id++)
		for(updown=0; updown<2; updown++)
			for(prio_id=0; prio_id<PRIO_NUM; prio_id++)
			{
				// TODO: memset优化
				memset(&(hm_nodes[hm_id].hm_queue.orign_queue[updown][prio_id]), 0 ,sizeof(Queue));
				memset(&(hm_nodes[hm_id].hm_queue.cache_queue[updown][prio_id]), 0 ,sizeof(Queue));
				memset(&(hm_nodes[hm_id].hm_queue.sending_queue[updown][prio_id]), 0 ,sizeof(Queue));
				memset(&(hm_nodes[hm_id].hm_queue.received_queue[updown][prio_id]), 0 ,sizeof(Queue));
			}
	return hm_nodes;
}