//---------------------
//名称：用户参数、宏定义
//说明：作为整个仿真平台的用户定义部分使用，
//		针对不同的仿真以及用户仿真需求，统一
//		在此头文件添加仿真中用到的常量和各种
//		数据结构。
//---------------------

# ifndef _USER_SETTING_H_
# define _USER_SETTING_H_

//--------------------
//头文件
//--------------------
# include "core\core_event.h"
# include "queue\basic_queue.h"

//--------------------
//hinoc2.0仿真相关宏定义
//--------------------
# define PRIO_NUM	3		//优先级个数
# define BITS_PER_OFDM		//调制格式

# define PD_TIME	1		//PD帧时间
//----------------------
//hinoc2.0仿真相关数据结构定义
//----------------------
//业务路径参数
typedef struct PATH {
	char *(*up_path_ptr)[PRIO_NUM];
	char *(*down_path_ptr)[PRIO_NUM];
}Path;

//HINOC帧扩展信息
typedef struct FRAME_INFO {
	int gen_time;		//帧生成开始时间
	int end_time;		//帧生成结束时间
	int first_packet;	//帧中第一个数据包
	int packet_num;		//帧中包个数
}FrameInfo;

//HINOC帧
typedef Packet Frame;


//----与调度相关的参数-----
#define CNT_OFDM_PER_MAP	146							//每MAP周期中OFDM符号的个数
enum OfdmType {DOWN_DATA = 1,MAP,T_R_IFG,UP_DATA,R};		//OFDM符号的类型
typedef struct ofdmusage
{
	enum OfdmType	usage;		//代表该OFDM符号的用途
	int			tar_hm;		//该OFDM符号要分给哪个Hm，如果OFDM特殊用途则该值为-1(然后根据usage判断用途)
}OfdmUsage;

typedef struct mapframe
{
	OfdmUsage	ssc_map[CNT_OFDM_PER_MAP];
	int*		arq_flag;
}MAPFrame;					//MAP帧结构

typedef struct schedulecell
{
	int	down_ofdm;
	int	up_ofdm;
}ScheduleResCell;				//给一个HM分配的上行符号数和下行符号数（指OFDM符号的数目，并不具体对应到哪个OFDM符号给哪个HM用）


# endif