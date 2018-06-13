/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 23:42:49 by jjourne           #+#    #+#             */
/*   Updated: 2018/04/10 06:17:04 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>
# include "libft.h"

# define BUF_SIZE 4096
# define SPECIFIER "sSpdouxcCiDOUX"
# define FLAG "0-+ #hhjlzL.123456789"

enum {flag_zero = (1 << 0), flag_neg = (1 << 1), flag_plus = (1 << 2),
	flag_space = (1 << 3), flag_hash = (1 << 4), flag_hh = (1 << 5),
	flag_h = (1 << 6), flag_j = (1 << 7), flag_l = (1 << 8), flag_z = (1 << 9),
	flag_L = (1 << 10), flag_pre = (1 << 11), flag_width = (1 << 12)};

typedef enum				e_bool
{
	false = 0,
	true
}							t_bool;

typedef union				u_type
{
	char					c;
	unsigned char			uc;
	unsigned int			u;
	unsigned long int		ul;
	unsigned long long int	ull;
	long long				ll;
	long double				ldb;
	long					l;
	float					f;
	int						d;
	char					*s;
	wchar_t					lc;
	wchar_t					*ls;
}							t_type;

/*
** structure qui sert de node pour la liste chainée(queue):
** on enregistre le resultat traité de la chaine de format au fur et a mesure
** dans buf, et si le buffer n'est pas assez gros on creer un nouveau maillon.
** buf: stockage du resultat de printf.
*/

typedef struct				s_result
{
	char					buf[BUF_SIZE + 1];
	struct s_result			*next;
}							t_result;

/*
** structure general de la fonction:
** format: chaine de caractere de ft_printf a traiter
** t_result begin/end: pointeurs vers la liste chainée
** int flag[3]:
** flag[0] -> tous les flags à activés ou non
** flag[1] -> la largeur de champ
** flag[2] -> la precision
*/

typedef struct				s_printf
{
	t_result				*result_start;
	t_result				*result_end;
	char					*format;
	int						result_i;
	int						format_i;
	int						len_final;
	int						flag[3];
	char					*str_prefix;
	int						val_prefix;
	int						effective_pre;
	int						effective_fw;
}							t_printf;

typedef	int					(*t_ptr_get_spec)(t_printf *, va_list, t_type,
	char **str);

void						apply_modifier_signed(t_printf *data,
	t_type *specifier);
void						apply_modifier_unsigned(t_printf *data,
	t_type *specifier);
void						apply_specifier(t_printf *data,
	va_list vl);
int							apply_effective_value(t_printf *data, int len_arg);
void						apply_print_f(t_printf *data, char *str_arg);
void						apply_print_f_end(t_printf *data, char *str_arg);
void						percent_case(t_printf *data);
void						maj_specifiers(t_printf *data);

/*
** parcourt la str(chaine de format) passé en arguments de ft_printf,
** determine si on a un: (1)caractere simple, (2)caractere d'echappement '\',
** (3)caractere de specfication de format '%'
** (1): aucune modification, l'afficher sur la sortie standard
** (2): converti en caractere simple le char suivant,
** et l'afficher sur la sortie standard
** (3): traitement de l'argument a envoyer en fonction des attributs:
** flags, field with, precision, format(modifieur/specifieur)
**
** ARGUMENT EN ENTRE: structure printf, va_list
** TYPE DE RETOUR: void
*/

void						ft_printf_parser(t_printf *print, va_list vl);

/*
** parcourt la chaine format (apres le %) et store les valeurs adequates
** dans flag[0] flag[1] et flag[2], jusqu'a tomber sur un caractere non flag.
*/

int							get_flag(t_printf *print, int i);

/*
** creer/update la list chainee, et store le bon caractere dans le buffer.
** si flag == 0 alors on prend le caractere dans la chaine de format
** sinon on envoi le caractere manuellement
*/

void						add_to_result(t_printf *data, char c, int flag);
void						add_str_to_result(t_printf *data, char *str,
	int flag);
void						put_n_char_to_result(t_printf *data, char c,
	int flag);

/*
** fonction principale:
** creer la valist initialize les parametres et appel les autres sous fonctions.
*/

int							ft_printf(const char *format, ...);

/*
** fonction pour supprimer la liste chainee qui contient le buffer du resultat
*/

void						del_list(t_result *lst);

/*
** fonctions d'affichage pour le debug
*/

void						print_flag(t_printf *data);
void						print_lst(t_printf *data);
void						print_format(t_printf *data);

/*
** Toutes les declarations des specifiers en pointeurs de fonctions
*/

int							spec_s(t_printf *data, va_list vl,
	t_type specifier, char **str);
int							spec_s_end(t_printf *data, char **str,
	char *str_tmp, int len_arg);
int							spec_ls(t_printf *data, va_list vl,
	t_type specifier, char **str);
int							spec_ls_no_null(t_printf *data, t_type specifier,
	char **str, int uni_len);
int							spec_d(t_printf *data, va_list vl, t_type specifier,
	char **str);
void						spec_d_end(t_printf *data, char **str, int neg);
int							spec_u(t_printf *data, va_list vl, t_type specifier,
	char **str);
int							spec_p(t_printf *data, va_list vl, t_type specifier,
	char **str);
int							spec_o(t_printf *data, va_list vl, t_type specifier,
	char **str);
void						spec_o_end(t_printf *data, char **str);
int							spec_x(t_printf *data, va_list vl, t_type specifier,
	char **str);
void						spec_x_end(t_printf *data, t_type specifier,
	char **str, int i);
int							spec_c(t_printf *data, va_list vl,
	t_type specifier, char **str);
int							spec_lc(t_printf *data, va_list vl,
	t_type specifier, char **str);

#endif
