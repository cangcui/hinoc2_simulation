#ifndef _HB_H_
#define _HB_H_
#include "../queue/queue_mng.h"

// 全局只有1个HB节点的实体
typedef struct hb_node{
	int			related_hm_nums;			//与该hb对应的Hm的节点个数
	HBQueue		hb_queue;
	MAPFrame	map_frame[2];				//生成的MAP帧（乒乓操作）

	ScheduleResCell	*pSchedule_res;			//给每个HM分配OFDM符号的数目的结果
}HB_Node;

extern HB_Node *global_hb_node;				//提供给全局的HB节点接口

HB_Node *gen_hb_node(int hm_nums);		//生成一个hb节点，输入的参数为与hb对应的Hm节点的个数
void free_hb_node(HB_Node *tar_node);	//free一个hb节点

#endif