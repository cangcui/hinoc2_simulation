#include "simulation.h"
#include "core/core_event.h"
#include "schedule/map.h"
#include "business/business.h"
#include "node/hm.h"
//����pd֡��pu֡����Զ������¼�
static int init_static_events()
{
	return 0;
}

//���ɹ̶����¼�
static void init()
{

	//���÷���ʱ��
	set_time(65536);

	//����pd֡��pu֡����Զ������¼�
	init_static_events();

	//Map֡��ʼ��
	init_map();

	gen_business(BUSINESS_CUSTOM);

}


int simulation(int argc, const char **argv)
{
	hm_node=gen_hm_nodes(64);
	hb_node=gen_hb_node(64);


	//��ʼ��
	init();
	//���з���
	run();
	//ͳ�Ʒ���
	//statistic();
	return 0;
}