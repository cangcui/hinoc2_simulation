#include "business.h"

#define HB_NODE 0
#define HM_NODE 1

static void gen_CBR_business()
{
	// TODO: ���CBRҵ�������
	// ��business�ļ������½��ļ�cbr_bussiness(.c|.h)
}

static void gen_CUSTOM_queue(const char *path, Queue *queue, int node_id, int prio_id)
{
	Packet *temp_packet = NULL;
	FILE *fp = NULL;
	char orgin_data[30] = {0};
	char search_data[15] = {0};
	int index = 0;
	int cnt = 0;

	//�޴�����·��
	if (!path)
	{
		printf("there is no path for hm_%d prio_%d.\n", node_id+1, prio_id);
		return;
	}

	//·�����Ϸ�
	if (!(fp = fopen(path,"r")))
	{
		printf("there is a path for hm_%d prio_%d, but maybe it is wrong path!\n", node_id+1, prio_id);
		return;
	}

	//ÿ�ζ�ȡһ��
	while (fgets(orgin_data, 30, fp))
	{
		//Ϊ��packet����ռ�
		if (!(temp_packet=(Packet*)malloc(sizeof(Packet))))
		{
			printf("there is no memory for packet!\n");
			return;
		}

		//����Ϣ����
		memset(temp_packet, 0, sizeof(Packet));

		//��������
		temp_packet->serial_num = ++cnt;

		//��ȡ������ʱ��
		while(orgin_data[index] != '\t')
			index++;
		memcpy(search_data, orgin_data, index);

		//���������ʱ��
		temp_packet->arrive_time = atoi(search_data);
		memset(search_data, 0, 15);

		//��ȡ������Ϣ
		strcpy(search_data, &orgin_data[index+1]);

		//���������Ϣ
		temp_packet->length = atoi(search_data)<<3;

		//���ݰ����
		enque(queue, temp_packet);

		//��ջ���
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

// �ⲿ�ӿ�
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

