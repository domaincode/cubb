
#include "./execution/game.h"
#include "parsing/parsing.h"

void ft_print_map(char **map)
{
    int i , j;
    i = 0;
    j = 0;

    while (map[i])
    {
        j = 0;
        // while (map[i][j])
        // {
        //     printf("%c",map[i][j]);
        //     j++;
        // }
        printf(".%s.\n", map[i]);
        i++;
        printf("\n");
    }
}



/*
 map[][] -----> cub->data->map;
 SO      ------> cub->texture->so

 c  -----------> cub->texture->f
 f 

*/

int	main(int ac, char **av)
{
    // (void)av;
    // char *str;
    // int fd = open("file1.txt", O_RDWR);
    // if(fd < 0)
    // {
    //     printf("error\n");
    //     exit(1);
    // }
    // str = get_next_line(fd);
    // while(str)
    // {
    //     printf(".%s.\n", str);
    //     str = get_next_line(fd);
    // }

    t_my_game  game;
    t_data            data;
    t_cub            *cub;
    t_wall_textures    *texture;

    if (ac != 2 || HEIGHT <= 0 || WIDTH <= 0)
        return (perror("Error: Invalid arguments\n"), 1);
    cub = malloc(sizeof(t_cub));
    texture = malloc(sizeof(t_wall_textures));
    if (!texture || !cub)
        return (free(cub), 1);
    ft_memset(cub, 0, sizeof(t_cub));
    ft_memset(&data, 0, sizeof(t_data));
    if (proccess_input(&data, cub, av[1], texture))
        return (free_heap(cub), 1);
    ft_execution(&game, cub);
    printf("\n=================== MAP =====================\n\n");
    ft_print_map(cub->data->map);
    
    printf("\n=================== TEXTURES ================\n\n");
    printf("NO :%s \n", cub->texture->no);
    printf("EA :%s \n", cub->texture->ea);
    printf("WE :%s \n", cub->texture->we);
    printf("SO :%s \n", cub->texture->so);
    //destroy_all(cub);


	//print_debug_info(&map);
	//free_parsing(&map);
    //free_map(map);
    return 0;
}
