//--------------------
//���ƣ�ͳ��ģ��
//���ߣ�
//���ڣ�
//˵������ɷ��������Ϣ�Ĳɼ�
//�汾��
//--------------------

//--------------------
//ͷ�ļ�
//--------------------
# include "sys_stat.h"

//--------------------
//ȫ�ֲ���
//--------------------
char *packet_up_path[HM_NUM][PRIO_NUM] = {{"123.txt"}};
char *packet_down_path[HM_NUM][PRIO_NUM] = {NULL};
Queue orgin_up_queue[HM_NUM][PRIO_NUM];
Queue orgin_down_queue[HM_NUM][PRIO_NUM];

//--------------------
//���ƣ����ݰ�����
//���룺e---�¼�ָ��
//�������
//˵����
//--------------------
void packet_load(Event *e)
{
	//·��
	char *path = NULL;
	Path *temp = NULL;

	//��ȡ
	temp = (Path *)e->src_data;

	path = temp->up_path_ptr[0][0];

	path = path;

}

void packet_free(Event *e)
{

}