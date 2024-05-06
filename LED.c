/******************************************************************************/
/*                                                                            */
/*                   RTX_EX1.C:  The first RTX-51 Program                     */
/*                                                                            */
/******************************************************************************/

#include <rtx51tny.h>                 /* RTX-51 tiny functions & defines      */
#include <reg52.h>
unsigned char NT[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
unsigned char NNT[] = {7,1,2,3,4,5,6,7};
long counter0;                        /* counter for task 0                   */
long counter1;                        /* counter for task 1                   */
long counter2;                        /* counter for task 2                   */

sbit P2_0 = P2^0;
sbit P2_1 = P2^1;
sbit P2_2 = P2^2;
sbit P2_3 = P2^3;
sbit P2_4 = P2^4;

/******************************************************************************/
/*       Task 0 'job0':  RTX-51 tiny starts execution with task 0             */
/******************************************************************************/

NIXIE () _task_ 0  {                  
  os_create_task (1);                 /* start task 1                         */
  os_create_task (2);                 /* start task 2                         */

  while (1)  {                        /* endless loop                         */
                     /* increment counter 0                  */
		os_wait2(K_TMO, 1);
		switch(counter0+1)
    {
        case 1:P2_4=1;P2_3=1;P2_2=1;break;
        case 2:P2_4=1;P2_3=1;P2_2=0;break;
        case 3:P2_4=1;P2_3=0;P2_2=1;break;
        case 4:P2_4=1;P2_3=0;P2_2=0;break;
        case 5:P2_4=0;P2_3=1;P2_2=1;break;
        case 6:P2_4=0;P2_3=1;P2_2=0;break;
        case 7:P2_4=0;P2_3=0;P2_2=1;break;
        case 8:P2_4=0;P2_3=0;P2_2=0;break;
    }
    P0=NT[NNT[counter0]];
		counter0++;  
		counter0=counter0%8;
  }
}

/******************************************************************************/
/*    Task 1 'job1':  RTX-51 tiny starts this task with os_create_task (1)    */
/******************************************************************************/
job1 () _task_ 1  {
  while (1)  {                        /* endless loop                         */
    counter1++;                       /* increment counter 1                  */
		os_wait2(K_TMO, 200);

  }
}

/******************************************************************************/
/*    Task 2 'job2':  RTX-51 tiny starts this task with os_create_task (2)    */
/******************************************************************************/
job2 () _task_ 2  {
  while (1)  {                        /* endless loop                         */
    counter2++;                       /* increment counter 2                  */
		os_wait2(K_TMO, 200);

  }
}
