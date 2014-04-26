#include <assert.h>
#include "hm.h"

//输入的参数：hm的个数
HM_Node *gen_hm_nodes(int hm_nums)
{	
	int hm_id=0;
	int updown=0;
	int prio_id=0;
	// 根据HM个数动态开辟HM_NODE
	HM_Node *hm_nodes = (HM_Node *)malloc(hm_nums * sizeof(HM_Node));
	assert(hm_nodes != NULL);
	memset(hm_nodes,0,hm_nums * sizeof(HM_Node));
	
	//初始化每个Hm的队列信息
	for(hm_id = 0;hm_id < hm_nums; hm_id++)
	{
		memset(&(hm_nodes[hm_id].hm_queue),0,sizeof(HMQueue));
	}


	return hm_nodes;
}

//释放生成的hm节点
void free_hm_nodes(HM_Node *tar_nodes,int hm_nums)
{

	//最后一步：释放节点
	free(tar_nodes);
}