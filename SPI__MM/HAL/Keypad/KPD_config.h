



#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_PORT   PORTC

#define KPD_R1     PIN0
#define KPD_R2     PIN1
#define KPD_R3     PIN2
#define KPD_R4     PIN3

#define KPD_C1     PIN4
#define KPD_C2     PIN5
#define KPD_C3     PIN6
#define KPD_C4     PIN7

const u8 KeyPadArr[4][4]={{7,8,9,'/'},
					      {4,5,6,'*'},
					      {1,2,3,'-'},
					      {'#',0,'=','+'}};


#endif
