#include "simulation.h"
#include "core/core_event.h"
#include "schedule/map.h"
#include "business/business.h"
#include "node/hm.h"

HB_Node *global_hb_node;		//提供给全局的节点接口
HM_Node *global_hm_nodes;		//提供给全局的节点接口


//生成固定的事件
static void init()
{

	//设置仿真时长
	set_time(65536);


	//Map帧初始化
	init_map();

	gen_business(BUSINESS_CUSTOM);

}


int simulation(int argc, const char **argv)
{
	int hm_nums	=	64;					//要生成的hm节点的个数，hb节点默认为1个

	global_hm_nodes	=	gen_hm_nodes(hm_nums);
	global_hb_node	=	gen_hb_node(hm_nums);


	//初始化
	init();
	//运行仿真
	run();
	//统计分析
	//statistic();

	return 0;
}