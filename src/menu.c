/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazan <yazan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:38:45 by aitorlope         #+#    #+#             */
/*   Updated: 2024/01/15 00:32:28 by yazan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/fdf.h"

#define CONTROL_BOX			650
#define DRAWINFO_BOX		40
#define MAPINFO_BOX			280
#define COLORSCHEME_BOX		480
#define LINE_SIZE			30
#define MENU_TAB			40

/* #define BUTTON_WIDTH 150
#define BUTTON_HEIGHT 50
#define LINE_HEIGHT 60 */

static void	draw_colorscheme(t_fdf *fdf)
{
	int		line;

	line = COLORSCHEME_BOX;
	print_str(fdf, MENU_TAB, line, " #### COLORSCHEME ####");
	line += LINE_SIZE;
	print_str(fdf, MENU_TAB, line, "0: WHITE & BLACK");
	line += LINE_SIZE;
}

static void	draw_mapinfo(t_fdf *fdf)
{
	int		line;

	line = MAPINFO_BOX;
	print_str(fdf, MENU_TAB, line, "#### CONTROLS ####");
	line += LINE_SIZE;
	print_str(fdf, MENU_TAB, line, "Scroll: Zom In/Out");
	line += LINE_SIZE;
	print_str(fdf, MENU_TAB, line, "Left Click: Rotate X/Y axis");
	line += LINE_SIZE;
	print_str(fdf, MENU_TAB, line, "Right Click: Move");
	line += LINE_SIZE;
	print_str(fdf, MENU_TAB, line, "Arrows: Rotate X/Y axis");
	line += LINE_SIZE;
	print_str(fdf, MENU_TAB, line, "Q/W: Rotate Z axis");
}


static void	draw_info(t_fdf *fdf)
{
	int		line;

	line = DRAWINFO_BOX;
	print_str(fdf, MENU_TAB, line, "####⚙️ general INFO ####");
	line += LINE_SIZE;
	print_str(fdf, MENU_TAB, line, "Reenders:");
	print_nbr(fdf, MENU_TAB + 100, line, fdf->map.renders);
	line += LINE_SIZE;
	print_str(fdf, MENU_TAB, line, "Performance(ms):");
	print_nbr(fdf, MENU_TAB + 170, line, fdf->map.performance * 1000);
	line += LINE_SIZE;
	print_str(fdf, MENU_TAB, line, "Zoom:");
	print_nbr(fdf, MENU_TAB + 80, line, fdf->map.scale);
	line += LINE_SIZE;
	print_str(fdf, MENU_TAB, line, "Z ratio:");
	print_nbr(fdf, MENU_TAB + 110, line, fdf->map.zdivisor);
	line += LINE_SIZE;
}

void	draw_menu(t_fdf *fdf)
{
	draw_info(fdf);
	draw_mapinfo(fdf);
	draw_colorscheme(fdf);
}
