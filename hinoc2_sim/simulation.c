#include "simulation.h"
#include "core/core_event.h"
#include "schedule/map.h"
#include "business/business.h"
#include "node/hm.h"

HB_Node *global_hb_node;		//�ṩ��ȫ�ֵĽڵ�ӿ�
HM_Node *global_hm_nodes;		//�ṩ��ȫ�ֵĽڵ�ӿ�


//���ɹ̶����¼�
static void init()
{

	//���÷���ʱ��
	set_time(65536);


	//Map֡��ʼ��
	init_map();

	gen_business(BUSINESS_CUSTOM);

}


int simulation(int argc, const char **argv)
{
	int hm_nums	=	64;					//Ҫ���ɵ�hm�ڵ�ĸ�����hb�ڵ�Ĭ��Ϊ1��

	global_hm_nodes	=	gen_hm_nodes(hm_nums);
	global_hb_node	=	gen_hb_node(hm_nums);


	//��ʼ��
	init();
	//���з���
	run();
	//ͳ�Ʒ���
	//statistic();

	return 0;
}