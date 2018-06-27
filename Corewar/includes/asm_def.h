/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_def.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:38:48 by fmadura           #+#    #+#             */
/*   Updated: 2018/06/27 15:49:13 by fmadura          ###   ########.fr       */
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
# define INS_IND	0x06
# define INS_SEP	0x08
# define INS_COM	0x0A
# define INS_END	0x0B
# define INS_ERR	0x0C

# define HEAD_NAME	0x02
# define HEAD_COMT	0x04
# define HEAD_ERRR	0x06

#endif
