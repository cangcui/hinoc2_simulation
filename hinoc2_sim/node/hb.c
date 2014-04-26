#include <stdlib.h>
#include <assert.h>
#include "hb.h"

//输入的参数：系统中hm的个数
HB_Node *gen_hb_node(int hm_nums)
{
	int hm_id	=	0;
	int updown	=	0;
	int prio_id	=	0;
	
	//为一个HB节点分配内存
	HB_Node *hb_node	=	(HB_Node *)malloc(sizeof(HB_Node));
	assert(hb_node != NULL);
	memset(hb_node,0,sizeof(HB_Node));

	hb_node->related_hm_nums	=	hm_nums;

	//分配队列内存并初始化
	hb_node->hb_queue.origin_queue = (Queue (*)[2][3])malloc(hm_nums*sizeof(Queue [2][3]));
	hb_node->hb_queue.cache_queue = (Queue (*)[2][3])malloc(hm_nums*sizeof(Queue [2][3]));
	hb_node->hb_queue.sending_queue = (Queue (*)[2][3])malloc(hm_nums*sizeof(Queue [2][3]));
	hb_node->hb_queue.received_queue = (Queue (*)[2][3])malloc(hm_nums*sizeof(Queue [2][3]));
	for(hm_id = 0;hm_id < hm_nums;hm_id++)
	{
		memset(hb_node->hb_queue.origin_queue[hm_id],0,sizeof(Queue [2][PRIO_NUM]));
		memset(hb_node->hb_queue.cache_queue[hm_id],0,sizeof(Queue [2][PRIO_NUM]));
		memset(hb_node->hb_queue.sending_queue[hm_id],0,sizeof(Queue [2][PRIO_NUM]));
		memset(hb_node->hb_queue.received_queue[hm_id],0,sizeof(Queue [2][PRIO_NUM]));
	}

	//Schedule_res(OFDM符号数目的分配结果)
	hb_node->pSchedule_res	=	(ScheduleResCell*)malloc(hm_nums * sizeof(ScheduleResCell));
	assert(hb_node->pSchedule_res != NULL);
	memset(hb_node->pSchedule_res,0,hm_nums * sizeof(ScheduleResCell));



	return hb_node;
}

//释放生成的hb节点
void free_hb_node(HB_Node *tar_node)
{
	//free队列
	free(tar_node->hb_queue.origin_queue);		tar_node->hb_queue.origin_queue	=	NULL;
	free(tar_node->hb_queue.cache_queue);		tar_node->hb_queue.cache_queue	=	NULL;
	free(tar_node->hb_queue.sending_queue);		tar_node->hb_queue.sending_queue	=	NULL;
	free(tar_node->hb_queue.received_queue);	tar_node->hb_queue.received_queue	=	NULL;

	//释放Schedule_res
	free(tar_node->pSchedule_res);


	//最后一步free节点
	free(tar_node);
}