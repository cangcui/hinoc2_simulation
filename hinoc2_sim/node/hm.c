#include <assert.h>
#include "hm.h"

//����Ĳ�����hm�ĸ���
HM_Node *gen_hm_nodes(int hm_nums)
{	
	int hm_id=0;
	int updown=0;
	int prio_id=0;
	// ����HM������̬����HM_NODE
	HM_Node *hm_nodes = (HM_Node *)malloc(hm_nums * sizeof(HM_Node));
	assert(hm_nodes != NULL);
	memset(hm_nodes,0,hm_nums * sizeof(HM_Node));
	
	//��ʼ��ÿ��Hm�Ķ�����Ϣ
	for(hm_id = 0;hm_id < hm_nums; hm_id++)
	{
		memset(&(hm_nodes[hm_id].hm_queue),0,sizeof(HMQueue));
	}


	return hm_nodes;
}

//�ͷ����ɵ�hm�ڵ�
void free_hm_nodes(HM_Node *tar_nodes,int hm_nums)
{

	//���һ�����ͷŽڵ�
	free(tar_nodes);
}