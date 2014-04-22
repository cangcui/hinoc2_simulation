//------------------------
//名称：统计
//说明：为整个仿真提供数据源，同时
//		针对不同的要求提供采集相关
//		信息的接口，例如时延统计、
//		队长统计等。
//------------------------

# ifndef _SYS_STAT_H_
# define _SYS_STAT_H_

//------------------------
//头文件
//------------------------
# include "user_setting.h"

//------------------------
//全局声明
//------------------------
extern char *packet_up_path[HM_NUM][PRIO_NUM];
extern char *packet_down_path[HM_NUM][PRIO_NUM];
extern Queue orgin_up_queue[HM_NUM][PRIO_NUM];
extern Queue orgin_down_queue[HM_NUM][PRIO_NUM];

//------------------------
//函数声明
//------------------------
void packet_load(Event *e);
void packet_free(Event *e);

# endif