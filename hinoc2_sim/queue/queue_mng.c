//--------------------
//���ƣ������շ�ģ��
//���ߣ�
//���ڣ�
//˵������ɷ��������Ϣ�Ĳɼ�
//�汾��
//--------------------

//--------------------
//ͷ�ļ�
//--------------------
# include "queue_mng.h"
#include "../user_setting.h"

/*
	��ģ����Ӧֻ�����й���Ľӿڡ�
	����ҵ���Ĳ�����Ӧ���ɽڵ�ģ����ɡ�
*/

// ������ԭʼ���У�������ԭʼ����
int en_orignal_queue(int updown_flag, Queue (*orign_queue)[2][PRIO_NUM])
{
	//����ҵ��Աģ��
	return 0;
}

// �����뻺����У����������
int en_cache_queue(int updown_flag, Queue (*orign_queue)[2][PRIO_NUM], Queue (*cache_queue)[2][PRIO_NUM])
{

	return 0;
}

// ���������ڷ��Ͷ��У������ݷ���
int en_sending_queue(int updown_flag, Queue (*cache_queue)[2][PRIO_NUM], Queue (*sending_queue)[2][PRIO_NUM])
{

	return 0;
}

// �������ѽ��ܶ��У������ݽ���
int en_received_queue(int updown_flag, Queue (*cache_queue)[2][PRIO_NUM], Queue (*sending_queue)[2][PRIO_NUM])
{

	return 0;
}