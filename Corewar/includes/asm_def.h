/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_def.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:38:48 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/14 19:43:02 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_DEF_H
# define ASM_DEF_H
# define CHK_LIVE(x)	(x == 0x6012)
# define CHK_LD(x)		(x ^ 0x602486)
# define CHK_ST(x)		(x ^ 0x603686)
# define CHK_ADD(x)		(x & 0x604)
# define CHK_SUB(x)		(x & 0x605)
# define CHK_AND(x)		(x & 0x606)
# define CHK_OR(x)		(x & 0x607)
# define CHK_XOR(x)		(x & 0x608)
# define CHK_ZJMP(x)	(x & 0x609)	
# define CHK_LDI(x)		(x & 0x60A)
# define CHK_STI(x)		(x & 0x60B)
# define CHK_FORK(x)	(x & 0x60C)
# define CHK_LLD(x)		(x & 0x60D)
# define CHK_LLDI(x)	(x & 0x60E)
# define CHK_LFORK(x)	(x & 0x60F)
# define CHK_AFF(x)		(x & 0x610)

# define TOKEN_COM	0x02
# define TOKEN_LAB	0x04
# define TOKEN_INS	0x06
# define TOKEN_HEA	0x08
# define TOKEN_SPA	0x0A

# define INS_DIR	0x02
# define INS_IND	0x04
# define INS_REG	0x06
# define INS_SEP	0x08
# define INS_COM	0x0A

# define HEAD_NAME	0x02
# define HEAD_COMT	0x04
# define HEAD_ERRR	0x06
#endif
