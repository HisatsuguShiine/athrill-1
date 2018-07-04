/*
 *  TOPPERS/HRP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      High Reliable system Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004-2012 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ��������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ��������Ȥ����դ��뤳�ȡ�
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ��������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ��������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 * 
 *  @(#) $Id: logtask.h 837 2012-12-26 15:09:59Z ertl-hiro $
 */

/*
 *		�����ƥ����������
 */

#ifndef TOPPERS_LOGTASK_H
#define TOPPERS_LOGTASK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <extsvc_fncode.h>
#include "target_syssvc.h"

/*
 *  �����ƥ������������Ϣ������Υǥե�����ͤ����
 */ 
#ifndef LOGTASK_PRIORITY
#define LOGTASK_PRIORITY	3		/* ���ͥ���� */
#endif /* LOGTASK_PRIORITY */

#ifndef LOGTASK_STACK_SIZE
#define LOGTASK_STACK_SIZE	1024	/* �����å��ΰ�Υ����� */
#endif /* LOGTASK_STACK_SIZE */

#ifndef LOGTASK_PORTID
#define LOGTASK_PORTID		1		/* �����ƥ�����ѤΥ��ꥢ��ݡ����ֹ� */
#endif /* LOGTASK_PORTID */

#ifndef LOGTASK_INTERVAL
#define LOGTASK_INTERVAL	10U		/* �����ƥ������������ư��ֳ֡ʥߥ��á�*/
#endif /* LOGTASK_INTERVAL */

#ifndef LOGTASK_FLUSH_WAIT
#define LOGTASK_FLUSH_WAIT	1U		/* �ե�å����Ԥ���ñ�̻��֡ʥߥ��á�*/
#endif /* LOGTASK_FLUSH_WAIT */

/*
 *  �����ƥ�����������γ�ĥ�����ӥ�������Υ����å�������
 */ 
#ifndef SSZ_LOGTASK_FLUSH
#define SSZ_LOGTASK_FLUSH	1024
#endif /* SSZ_LOGTASK_FLUSH */

/*
 *  �����ƥ����������������
 */
extern void	logtask_main(intptr_t exinf) throw();

/*
 *  �����ƥ�����������ν�λ����
 */
extern void	logtask_terminate(intptr_t exinf) throw();

/*
 *  �����ƥ�����������γ�ĥ�����ӥ�������ˤ��ƽФ����󥿥ե�����
 */
#ifndef TOPPERS_SVC_CALL

/*
 *  �����ƥ�������Ϥ��Ԥ���碌
 *
 *  �����Хåե���Υ����ο���count�ʲ��ˤʤ�ޤ��Ԥġ�count��0�ξ���
 *  �ϡ����ꥢ��Хåե������ˤʤ�Τ��Ԥġ�
 */
Inline ER
logtask_flush(uint_t count)
{
	return((ER) cal_svc(TFN_LOGTASK_FLUSH, (intptr_t) count, 0, 0, 0, 0));
}

#endif /* TOPPERS_SVC_CALL */

/*
 *  �����ƥ�����������δؿ��ƽФ��ˤ��ƽФ����󥿥ե�����
 */
extern ER	_logtask_logtask_flush(uint_t count) throw();

#ifdef TOPPERS_SVC_CALL
#define logtask_flush	_logtask_logtask_flush
#endif /* TOPPERS_SVC_CALL */

/*
 *  �����ƥ�������������ĥ�����ӥ�������Ȥ�����Ͽ���뤿������
 */
extern ER_UINT	extsvc_logtask_flush(intptr_t count, intptr_t par2,
									intptr_t par3, intptr_t par4,
									intptr_t par5, ID cdmid) throw();

#ifdef __cplusplus
}
#endif

#endif /* TOPPERS_LOGTASK_H */