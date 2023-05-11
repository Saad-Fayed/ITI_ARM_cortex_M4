




#ifndef RCC_BIT_MATHS_H
#define RCC_BIT_MATHS_H

#define SET_BIT(REG,Index)  (REG |= (1 << Index))
#define CLR_BIT(REG,Index)	(REG &= ~(1 << Index))
#define TGL_BIT(REG,Index)  (REG ^= (1 << Index))
#define GET_BIT(REG,Index)  ((REG >> Index) & 1)

#define WRT_BIT(REG,Index,Value)  ( REG = ( REG & (~(1<<Index)) ) | (Value<<Index) )

#endif
