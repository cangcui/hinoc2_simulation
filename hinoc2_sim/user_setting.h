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
//hinoc2.0������غ궨��
//--------------------
# define PRIO_NUM	3		//���ȼ�����
# define BITS_PER_OFDM		//���Ƹ�ʽ

# define PD_TIME	1		//PD֡ʱ��
//----------------------
//hinoc2.0����������ݽṹ����
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


//----�������صĲ���-----
#define CNT_OFDM_PER_MAP	146							//ÿMAP������OFDM���ŵĸ���
enum OfdmType {DOWN_DATA = 1,MAP,T_R_IFG,UP_DATA,R};		//OFDM���ŵ�����
typedef struct ofdmusage
{
	enum OfdmType	usage;		//�����OFDM���ŵ���;
	int			tar_hm;		//��OFDM����Ҫ�ָ��ĸ�Hm�����OFDM������;���ֵΪ-1(Ȼ�����usage�ж���;)
}OfdmUsage;

typedef struct mapframe
{
	OfdmUsage	ssc_map[CNT_OFDM_PER_MAP];
	int*		arq_flag;
}MAPFrame;					//MAP֡�ṹ

typedef struct schedulecell
{
	int	down_ofdm;
	int	up_ofdm;
}ScheduleResCell;				//��һ��HM��������з����������з�������ָOFDM���ŵ���Ŀ�����������Ӧ���ĸ�OFDM���Ÿ��ĸ�HM�ã�


# endif