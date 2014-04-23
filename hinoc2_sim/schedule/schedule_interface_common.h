/*****************************************************************
** ���ƣ��ŵ��滮
** ˵�������ݲ�ͬЭ��ľ���Ҫ��ʵ���ŵ��滮�Ĳ�ͬ�㷨
*****************************************************************/
#ifndef SCHEDULE_INTERFACE_COMMON_H
#define SCHEDULE_INTERFACE_COMMON_H

//--------------------------
//ͷ�ļ�
//--------------------------
# include "../user_setting.h"

//--------------------------

/*****************************************************************
** Function name: get_queue_len
** Input argv:
**      int hm_id
**      int dir: 0: down link; 1: up link
** Return:
**       �Ǹ�ֵ: ��Ӧ���Ķ��г��ȣ��ֽڣ�
**       -1: ��������
** Function Description:  ���ڷ��ض�Ӧ���Ķ��г���
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
**       �Ǹ�ֵ: ��Ӧ����ռ�ձȣ���Чhimac֡�� * 100 / ��֡����
**       -1: ��������
** Function Description:  ���ڷ��ض�Ӧ����ռ�ձ�
** Version: 1.0
** Be careful: ����driver���޷���ʾС����Ӧ�����*100����
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
**       �Ǹ�ֵ: ��Ӧ���ı�֤���������У�
**       -1: ��������
** Function Description:  ���ڷ��ض�Ӧ���ı�֤����
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
**       �Ǹ�ֵ: ��Ӧ���ķ�ֵ���������У�
**       -1: ��������
** Function Description:  ���ڷ��ض�Ӧ���ķ�ֵ����
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
**       �Ǹ�ֵ: ��Ӧ���ľ�����Ϣ
**       -1: ��������
** Function Description:  ���ڷ��ض�Ӧ��������ҵ�������Ϣ
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
**     �Ǹ�ֵ: ��Ӧ���ķ�������
**     -1: ��������
** Function Description:  ���ڷ��ض�Ӧ��ÿ�������ܹ����ص�bit��
** Version: 1.0
** Be careful: 
** Change log:
** Author:
*****************************************************************/
int get_ofdm_bits(int hm_id,int dir);

/*****************************************************************
** Function name: get_ru_ofdm_num
** Input argv:
**		��
** Return:
**      ����ֵ��ru֡��һ��MAP��������ռOFDM������
**      -1: �쳣
** Function Description:  ���ڷ���ru֡��һ��MAP��������ռOFDM������
** Version: 1.0
** Be careful: driver��Ҫ��֤�䷵��ֵΪ��0����
** Change log:
** Author:
*****************************************************************/
int get_ru_ofdm_num(void);

/*****************************************************************
** Function name: get_schedule_len
** Input argv:
**		��
** Return:
**      ����ֵ��һ�ι滮��MAP������
**      -1: �쳣
** Function Description:  ���ڷ���һ�ι滮��MAP������
** Version: 1.0
** Be careful: �Ϸ�ֵΪ1,2,3,4����ֵ������������
** Change log:
** Author:
*****************************************************************/
int get_schedule_len(void);

# endif