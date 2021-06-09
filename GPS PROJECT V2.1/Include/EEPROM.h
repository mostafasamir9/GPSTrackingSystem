/************************************************************************
* 
* Module      : EEPROM
*
* File Nmae   : EEPROM.h
*
* Describtion : Header file for "EEPROM Module" containing the function prototypes for EEPROM driver
*
* Author      : Hussein Mahmoud - Mohamed Ahmed - Mohamed Fathy - Mohamed Ali - Mostafa Mohsen - Mostafa Samir
*
* Version     : V01
*
* Date        : 8 June 2021
*
***************************************************************************/
#ifndef EEPROM_H_
#define EEPROM_H_

#include"stdint.h"
#include"tm4c123gh6pm.h"

void EEPROM_reset(void);
void EEPROM_init(void);
void EEPROM_write(uint32_t data, uint32_t address_block, uint8_t address_offset);//, uint32_t address);
uint32_t EEPROM_read(uint32_t address_block, uint8_t address_offset);//uint32_t address);

#endif

