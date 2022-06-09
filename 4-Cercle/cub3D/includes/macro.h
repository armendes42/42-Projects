/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:06:40 by armendes          #+#    #+#             */
/*   Updated: 2022/06/09 19:18:42 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# include <math.h>

# define ARGNB_ERR "You should input only a map with .cub extension"
# define MALLOC_ERR "Memory allocation error"
# define SPRITE_ERR "Error in sprite file"
# define IMG_ERR "An error occured with the image"

# define FOV_ANGLE (60 * (M_PI / 180))

# define ESC 0xff1b
# define K_W 119
# define K_A 97
# define K_S 115
# define K_D 100
# define ARR_UP 126
# define ARR_LT 65361
# define ARR_RT 65363
# define ARR_DN 125

#endif
