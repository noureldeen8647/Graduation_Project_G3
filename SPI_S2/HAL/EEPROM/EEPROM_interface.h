
////////***************^~^**************************//////
////////*********Name:NOURELDEEN*********************//////
////////*********PROJECT_NAME:SMART_HOME*************//////
///////*GITHUB : https://github.com/noureldeen8647/Graduation_Project_G3 ****///////

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8DataByte);

u8 EEPROM_u8ReadDataByte(u16 Copy_u16LocationAddress);

#endif
