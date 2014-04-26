#include "hb.h"

HB_Node *hb_node;

HB_Node *gen_hb_node(int hm_num)
{
	int hm_id=0;
	int updown=0;
	int prio_id=0;
	// TODO: 记得依次释放
	HB_Node *hb_node=(HB_Node *)malloc(sizeof(HB_Node));
	// 初始化数组指针
	(*hb_node).hb_queue.orign_queue = (Queue (*)[2][3])malloc(hm_num*sizeof(Queue (*)[2][3]));
	(*hb_node).hb_queue.cache_queue = (Queue (*)[2][3])malloc(hm_num*sizeof(Queue (*)[2][3]));
	(*hb_node).hb_queue.sending_queue = (Queue (*)[2][3])malloc(hm_num*sizeof(Queue (*)[2][3]));
	(*hb_node).hb_queue.received_queue = (Queue (*)[2][3])malloc(hm_num*sizeof(Queue (*)[2][3]));

	for(hm_id=0; hm_id < hm_num; hm_id++)
		for(updown=0; updown<2; updown++)
			for(prio_id=0; prio_id<PRIO_NUM; prio_id++)
			{
				// TODO: memset优化
				memset(&((*hb_node).hb_queue.orign_queue[hm_id][updown][prio_id]), 0 ,sizeof(Queue));
				memset(&((*hb_node).hb_queue.cache_queue[hm_id][updown][prio_id]), 0 ,sizeof(Queue));
				memset(&((*hb_node).hb_queue.sending_queue[hm_id][updown][prio_id]), 0 ,sizeof(Queue));
				memset(&((*hb_node).hb_queue.received_queue[hm_id][updown][prio_id]), 0 ,sizeof(Queue));
			}

	return hb_node;
}