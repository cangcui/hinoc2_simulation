#include <stdlib.h>
#include <assert.h>
#include "hb.h"

//����Ĳ�����ϵͳ��hm�ĸ���
HB_Node *gen_hb_node(int hm_nums)
{
	int hm_id	=	0;
	int updown	=	0;
	int prio_id	=	0;
	
	//Ϊһ��HB�ڵ�����ڴ�
	HB_Node *hb_node	=	(HB_Node *)malloc(sizeof(HB_Node));
	assert(hb_node != NULL);
	memset(hb_node,0,sizeof(HB_Node));

	hb_node->related_hm_nums	=	hm_nums;

	//��������ڴ沢��ʼ��
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

	//Schedule_res(OFDM������Ŀ�ķ�����)
	hb_node->pSchedule_res	=	(ScheduleResCell*)malloc(hm_nums * sizeof(ScheduleResCell));
	assert(hb_node->pSchedule_res != NULL);
	memset(hb_node->pSchedule_res,0,hm_nums * sizeof(ScheduleResCell));



	return hb_node;
}

//�ͷ����ɵ�hb�ڵ�
void free_hb_node(HB_Node *tar_node)
{
	//free����
	free(tar_node->hb_queue.origin_queue);		tar_node->hb_queue.origin_queue	=	NULL;
	free(tar_node->hb_queue.cache_queue);		tar_node->hb_queue.cache_queue	=	NULL;
	free(tar_node->hb_queue.sending_queue);		tar_node->hb_queue.sending_queue	=	NULL;
	free(tar_node->hb_queue.received_queue);	tar_node->hb_queue.received_queue	=	NULL;

	//�ͷ�Schedule_res
	free(tar_node->pSchedule_res);


	//���һ��free�ڵ�
	free(tar_node);
}