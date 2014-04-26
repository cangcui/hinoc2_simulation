//---------------------
//���ƣ��û��������궨��
//˵������Ϊ��������ƽ̨���û����岿��ʹ�ã�
//		��Բ�ͬ�ķ����Լ��û���������ͳһ
//		�ڴ�ͷ�ļ���ӷ������õ��ĳ����͸���
//		���ݽṹ��
//---------------------

# ifndef _USER_SETTING_H_
# define _USER_SETTING_H_

//--------------------
//ͷ�ļ�
//--------------------
# include "core\core_event.h"
# include "queue\basic_queue.h"

//--------------------
//hinoc1.0������غ궨��
//--------------------
# define HM_NUM		4		//HM����
# define PRIO_NUM	3		//���ȼ�����
# define BITS_PER_OFDM		//���Ƹ�ʽ

# define PD_TIME	1		//PD֡ʱ��
# define PU_TIME	32769	//PU֡ʱ��
# define MAX_MAP_LENGTH		//���MAP���ڳ���
# define MIN_MAP_LENGTH		//��СMAP���ڳ���
# define T_IFG				//��������
# define T_R_IFG			//��������
# define T_MR				//MR���
# define T_RM				//RM���

//----------------------
//hinoc1.0����������ݽṹ����
//----------------------
//ҵ��·������
typedef struct PATH {
	char *(*up_path_ptr)[PRIO_NUM];
	char *(*down_path_ptr)[PRIO_NUM];
}Path;

//HINOC֡��չ��Ϣ
typedef struct FRAME_INFO {
	int gen_time;		//֡���ɿ�ʼʱ��
	int end_time;		//֡���ɽ���ʱ��
	int first_packet;	//֡�е�һ�����ݰ�
	int packet_num;		//֡�а�����
}FrameInfo;

//HINOC֡
typedef Packet Frame;

# endif