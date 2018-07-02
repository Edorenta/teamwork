/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_def.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:38:48 by fmadura           #+#    #+#             */
/*   Updated: 2018/07/02 04:14:04 by jyildiz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_DEF_H
# define ASM_DEF_H

# define TOKEN_COM	0x02
# define TOKEN_LAB	0x04
# define TOKEN_INS	0x06
# define TOKEN_HEA	0x08
# define TOKEN_SPA	0x0A

# define INS_REG	0x02
# define INS_DIR	0x04
# define INS_DIL	0x05
# define INS_IND	0x06
# define INS_SEP	0x08
# define INS_COM	0x0A
# define INS_END	0x0B
# define INS_ERR	0x0C
# define INS_ERR0	0x8e

# define HEAD_NAME	0x02
# define HEAD_COMT	0x04
# define HEAD_ERR0	0x0e
# define HEAD_ERR1	0x3e
# define HEAD_ERR2	0x4e
# define HEAD_ERR3	0x5e
# define NAME_ERR0	0x6e
# define NAME_ERR1  0xce
# define COMT_ERR0	0x7e
# define ENDLI_ERR  0x1e

# define LABEL_ERR2 0x2e
# define PAR_ERR0	0x9e
# define PAR_ERR1	0xae
# define PAR_ERR2	0xbe
#endif
