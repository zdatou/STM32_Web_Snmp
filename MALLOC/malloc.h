#ifndef _MALLOC_H
#define _MALLOC_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
//ALIENTEK STM32F407������
//�ڴ���� ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/7/8
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) �������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 

#ifndef NULL
#define NULL 0
#endif

//���������ڴ��
#define SRAMIN 	0  //�ڲ��ڴ��

#define SRAMBANK  1 //����֧�ֵ�SRAM����


//mem1�ڴ�����趨,mem1��ȫ�����ڲ�SRAM����
#define MEM1_BLOCK_SIZE	32  			//�ڴ���СΪ32�ֽ�
#define MEM1_MAX_SIZE		42*1024 	//�������ڴ� 110k
#define MEM1_ALLOC_TABLE_SIZE MEM1_MAX_SIZE/MEM1_BLOCK_SIZE  //�ڴ����С

//�ڴ����������
struct _m_mallco_dev
{
	void (*init)(u8);  		//��ʼ��
	u8 (*perused)(u8); 		//�ڴ�ʹ����
	u8 *membase[SRAMBANK]; //�ڴ��,����SRAMBANK��������ڴ�
	u16 *memmap[SRAMBANK];  //�ڴ�״̬��
	u8 memrdy[SRAMBANK];   //�ڴ�����Ƿ����
};
extern struct _m_mallco_dev mallco_dev;  //��malloc.c���涨��

void mymemset(void *s,u8 c,u32 count);	 //�����ڴ�
void mymemcpy(void *des,void *src,u32 n);//�����ڴ�     
void mymem_init(u8 memx);					 //�ڴ������ʼ������(��/�ڲ�����)
u32 mymem_malloc(u8 memx,u32 size);		 //�ڴ����(�ڲ�����)
u8 mymem_free(u8 memx,u32 offset);		 //�ڴ��ͷ�(�ڲ�����)
u8 mem_perused(u8 memx);				 //����ڴ�ʹ����(��/�ڲ�����) 
////////////////////////////////////////////////////////////////////////////////
//�û����ú���
void myfree(u8 memx,void *ptr);  			//�ڴ��ͷ�(�ⲿ����)
void *mymalloc(u8 memx,u32 size);			//�ڴ����(�ⲿ����)
void *myrealloc(u8 memx,void *ptr,u32 size);//���·����ڴ�(�ⲿ����)
#endif

