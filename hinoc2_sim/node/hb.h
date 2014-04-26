#ifndef _HB_H_
#define _HB_H_
#include "../queue/queue_mng.h"

// ȫ��ֻ��1��HB�ڵ��ʵ��
typedef struct hb_node{
	int			related_hm_nums;			//���hb��Ӧ��Hm�Ľڵ����
	HBQueue		hb_queue;
	MAPFrame	map_frame[2];				//���ɵ�MAP֡��ƹ�Ҳ�����

	ScheduleResCell	*pSchedule_res;			//��ÿ��HM����OFDM���ŵ���Ŀ�Ľ��
}HB_Node;

extern HB_Node *global_hb_node;				//�ṩ��ȫ�ֵ�HB�ڵ�ӿ�

HB_Node *gen_hb_node(int hm_nums);		//����һ��hb�ڵ㣬����Ĳ���Ϊ��hb��Ӧ��Hm�ڵ�ĸ���
void free_hb_node(HB_Node *tar_node);	//freeһ��hb�ڵ�

#endif