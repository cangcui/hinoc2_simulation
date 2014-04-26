#include "business.h"

#define HB_NODE 0
#define HM_NODE 1

static void gen_CBR_business()
{
	// TODO: 完成CBR业务的生成
	// 在business文件夹下新建文件cbr_bussiness(.c|.h)
}

static void gen_CUSTOM_queue(const char *path, Queue *queue, int node_id, int prio_id)
{
	Packet *temp_packet = NULL;
	FILE *fp = NULL;
	char orgin_data[30] = {0};
	char search_data[15] = {0};
	int index = 0;
	int cnt = 0;

	//无此数据路径
	if (!path)
	{
		printf("there is no path for hm_%d prio_%d.\n", node_id+1, prio_id);
		return;
	}

	//路径不合法
	if (!(fp = fopen(path,"r")))
	{
		printf("there is a path for hm_%d prio_%d, but maybe it is wrong path!\n", node_id+1, prio_id);
		return;
	}

	//每次读取一行
	while (fgets(orgin_data, 30, fp))
	{
		//为此packet申请空间
		if (!(temp_packet=(Packet*)malloc(sizeof(Packet))))
		{
			printf("there is no memory for packet!\n");
			return;
		}

		//包信息清零
		memset(temp_packet, 0, sizeof(Packet));

		//载入包序号
		temp_packet->serial_num = ++cnt;

		//获取包到达时刻
		while(orgin_data[index] != '\t')
			index++;
		memcpy(search_data, orgin_data, index);

		//载入包到达时刻
		temp_packet->arrive_time = atoi(search_data);
		memset(search_data, 0, 15);

		//获取包长信息
		strcpy(search_data, &orgin_data[index+1]);

		//载入包长信息
		temp_packet->length = atoi(search_data)<<3;

		//数据包入队
		enque(queue, temp_packet);

		//清空缓存
		memset(orgin_data, 0, 30);
		memset(search_data, 0, 15);
	}

	fclose(fp);
}

static void gen_CUSTOM_bussiness()
{
	int hm_id = 0;
	int prio_id = 0;

	for (hm_id = 0; hm_id < HM_NUM; hm_id++)
	{
		for (prio_id = 0; prio_id < PRIO_NUM; prio_id++)
		{
			gen_CUSTOM_queue("./custom.txt", &(hm_node[hm_id].hm_queue.orign_queue[UP][prio_id]), hm_id, prio_id);
			gen_CUSTOM_queue("./custom.txt", &((*hb_node).hb_queue.orign_queue[hm_id][UP][prio_id]), hm_id, prio_id);
		}
	}
	
}

// 外部接口
void gen_business(int type)
{
	switch(type)
	{
	case BUSINESS_CBR:
		gen_CBR_business();
		break;

	case BUSINESS_CUSTOM:
		gen_CUSTOM_bussiness();
		break;

	default:
		break;
	}
}

