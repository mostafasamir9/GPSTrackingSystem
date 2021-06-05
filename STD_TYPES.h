/************************************************************************
* 
* Module : common -Platform Types Abstractions
*
* File Nmae : std_types.h
*
* Describtion : std_types for all differnt targets
*
* Author : Hussein Mahmoud - Mohamed Ahmed - Mohamed Fathy - Mohamed Ali - Mostafa Mohsen - Mostafa Samir
*
* Version : V02
*
* Date : 27 JAN 2021
*
***************************************************************************/
#ifndef STD_TYPES_H_
#define STD_TYPES_H_


/* Boolean data type */
typedef unsigned char bool;


/* Boolean Values */
#ifndef    FALSE
#define  FALSE     (0u)
#endif
#ifndef    TRUE
#define  TRUE      (1u)
#endif

#define  LOW      (0u)
#define  HIGH     (1u)


/* NULL_PTR Definition */
#define NULL_PTR   ((void*)0)


/* Standard Types */
typedef unsigned char       uint8;     /*                    0..255                  */
typedef signed   char       sint8;     /*                 -127..128                  */
typedef unsigned short      uint16;    /*                    0..65535                */
typedef signed   short      sint16;    /*               -32767..32768                */
typedef unsigned long       uint32;    /*                    0..4294967295           */
typedef signed   long       sint32;    /*       -2,147,483,647..2,147,483,648        */
typedef unsigned long long  uint64;    /*                    0..18446744073709551615 */
typedef signed   long long  sint64;    /* -1152921504606846976..1152921504606846975  */


#endif  /* STD_TYPES_H_ */
