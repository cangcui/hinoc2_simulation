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
//hinoc1.0仿真相关宏定义
//--------------------
# define HM_NUM		4		//HM个数
# define PRIO_NUM	3		//优先级个数
# define BITS_PER_OFDM		//调制格式

# define PD_TIME	1		//PD帧时间
# define PU_TIME	32769	//PU帧时间
# define MAX_MAP_LENGTH		//最大MAP周期长度
# define MIN_MAP_LENGTH		//最小MAP周期长度
# define T_IFG				//倒换长度
# define T_R_IFG			//倒换长度
# define T_MR				//MR间隔
# define T_RM				//RM间隔

//----------------------
//hinoc1.0仿真相关数据结构定义
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

# endif