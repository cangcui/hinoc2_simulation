#include "simulation.h"
#include "core/core_event.h"
#include "schedule/map.h"
#include "business/business.h"
#include "node/hm.h"
//生成pd帧和pu帧等永远不变的事件
static int init_static_events()
{
	return 0;
}

//生成固定的事件
static void init()
{

	//设置仿真时长
	set_time(65536);

	//生成pd帧和pu帧等永远不变的事件
	init_static_events();

	//Map帧初始化
	init_map();

	gen_business(BUSINESS_CUSTOM);

}


int simulation(int argc, const char **argv)
{
	hm_node=gen_hm_nodes(64);
	hb_node=gen_hb_node(64);


	//初始化
	init();
	//运行仿真
	run();
	//统计分析
	//statistic();
	return 0;
}