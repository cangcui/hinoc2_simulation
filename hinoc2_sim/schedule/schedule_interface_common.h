/*****************************************************************
** 名称：信道规划
** 说明：根据不同协议的具体要求实现信道规划的不同算法
*****************************************************************/
#ifndef SCHEDULE_INTERFACE_COMMON_H
#define SCHEDULE_INTERFACE_COMMON_H

//--------------------------
//头文件
//--------------------------
# include "../user_setting.h"

//--------------------------

/*****************************************************************
** Function name: get_queue_len
** Input argv:
**      int hm_id
**      int dir: 0: down link; 1: up link
** Return:
**       非负值: 对应流的队列长度（字节）
**       -1: 参数错误
** Function Description:  用于返回对应结点的队列长度
** Version: 1.0
** Be careful:
** Change log:
** Author:
*****************************************************************/
int get_queue_len(int hm_id,int dir);

/*****************************************************************
** Function name: get_duty_ration
** Input argv:
**      int hm_id
**      int dir: 0: down link; 1: up link
** Return:
**       非负值: 对应流的占空比（有效himac帧数 * 100 / 总帧数）
**       -1: 参数错误
** Function Description:  用于返回对应流的占空比
** Version: 1.0
** Be careful: 由于driver中无法表示小数，应将结果*100返回
** Change log:
** Author:
*****************************************************************/
int get_duty_ration(int hm_id,int dir);

int get_min_band(int hm_id);

/*****************************************************************
** Function name: get_grant
** Input argv:
**      int hm_id
** Return:
**       非负值: 对应结点的保证带宽（上下行）
**       -1: 参数错误
** Function Description:  用于返回对应结点的保证带宽
** Version: 1.0
** Be careful: 
** Change log:
** Author:
*****************************************************************/

int get_grant(int hm_id);
/*****************************************************************
** Function name: get_peak
** Input argv:
**      int hm_id
** Return:
**       非负值: 对应结点的峰值带宽（上下行）
**       -1: 参数错误
** Function Description:  用于返回对应结点的峰值带宽
** Version: 1.0
** Be careful: 
** Change log:
** Author:
*****************************************************************/

int get_peak(int hm_id);
/*****************************************************************
** Function name: get_ru_info
** Input argv:
**      int hm_id
** Return:
**       非负值: 对应结点的举手信息
**       -1: 参数错误
** Function Description:  用于返回对应结点的上行业务举手信息
** Version: 1.0
** Be careful: 
** Change log:
** Author:
*****************************************************************/
int get_ru_info(int hm_id);

/*****************************************************************
** Function name: get_ofdm_bits
** Input argv:
**      int hm_id:
**      int dir: 0: down link; 1: up link
** Return:
**     非负值: 对应流的发送能力
**     -1: 参数错误
** Function Description:  用于返回对应流每个符号能够承载的bit数
** Version: 1.0
** Be careful: 
** Change log:
** Author:
*****************************************************************/
int get_ofdm_bits(int hm_id,int dir);

/*****************************************************************
** Function name: get_ru_ofdm_num
** Input argv:
**		无
** Return:
**      正数值：ru帧在一个MAP周期中所占OFDM符号数
**      -1: 异常
** Function Description:  用于返回ru帧在一个MAP周期中所占OFDM符号数
** Version: 1.0
** Be careful: driver需要保证其返回值为非0正数
** Change log:
** Author:
*****************************************************************/
int get_ru_ofdm_num(void);

/*****************************************************************
** Function name: get_schedule_len
** Input argv:
**		无
** Return:
**      正数值：一次规划的MAP周期数
**      -1: 异常
** Function Description:  用于返回一次规划的MAP周期数
** Version: 1.0
** Be careful: 合法值为1,2,3,4，该值可由网管配置
** Change log:
** Author:
*****************************************************************/
int get_schedule_len(void);

# endif