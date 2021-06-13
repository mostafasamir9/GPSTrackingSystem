/*************************************************************************************
*
* Module      : BitMath Macros
*   
* File Name   : common_macros.h
*
* Description : Header file contains Bit-Math commonly used macros in all targets
*
* Author      : Hussein Mahmoud Fouad
*
* Version     : V03
*
* Date        : 27 JAN 2021
*
**************************************************************************************/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT) REG|=(1<<BIT)

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) REG&=~(1<<BIT)

/* Toggle a certain bit in any register */
#define TOG_BIT(REG,BIT) REG^=(1<<BIT)


/*Check if a certain bit is set in a register */
#define BIT_IS_SET(REG,BIT) ( (REG>>BIT)&1 )

/*Check if a certain bit is cleared in a register */
#define BIT_IS_CLEAR(REG,BIT)  (!((REG>>BIT)&1))


/* Rotate right an 8-bit register with a certain num of bits */
#define ROR_8BIT(REG,NUM) REG=(REG<<NUM)|(REG>>(8-NUM))

/* Rotate left an 8-bit register with a certain num of bits */
#define ROL_8BIT(REG,NUM) REG=(REG>>NUM)|(REG<<(8-NUM))


/* Rotate right an 32-bit register with a certain num of bits */
#define ROR_32BIT(REG,NUM) REG=(REG<<NUM)|(REG>>(32-NUM))

/* Rotate left an 32-bit register with a certain num of bits */
#define ROL_32BIT(REG,NUM) REG=(REG>>NUM)|(REG<<(32-NUM))

/* Make a Certain bit in a register 1 or 0 */
#define MAKE_BIT_VALUE(REG, BIT, VAL) {\
CLEAR_BIT(REG,BIT);\
REG|=(VAL<<BIT);\
}
	


#endif
