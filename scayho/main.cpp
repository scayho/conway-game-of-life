#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits.h>
#include <unistd.h>
#include <sys/time.h>
// #include "mlx.h"
#include "./MLX42/include/MLX42/MLX42.h"
#define TILE 5
int WIDTH = 500;
int HEITH = 500;
int mehdi_s_flag = 0;
int alive = 1;
class TCGA{
    protected :
    public :
} ;

std::vector<std::vector<int> >  cells(HEITH, std::vector<int>(WIDTH, 0));
std::vector<std::vector<int> >  clone_cells(HEITH, std::vector<int>(WIDTH, 0));
mlx_t *mlx;
mlx_image_t *mlx_img;



void draw_a_Glider(int x, int y, mlx_image_t *mlx_img)
{
    cells[x][y + 1] = 1;
    cells[x + 1][y + 2] = 1;
    cells[x + 2][y] = 1;
    cells[x + 2][y + 1] = 1;
    cells[x + 2][y + 2] = 1;
    // 0 1 0 
    // 0 0 1
    // 1 1 1
}

void draw_a_line(int x, int y, mlx_image_t *mlx_img)
{
    cells[x][y] = 1;
    cells[x][y+1] = 1;
    cells[x][y+2] = 1;

}
void draw_a_block(int x, int y, mlx_image_t *mlx_img)
{
    cells[x][y] = 1;
    cells[x + 1][y] = 1;
    cells[x][y + 1] = 1;
    cells[x+1][y+1] = 1;
}

void draw_a_beehive(int x, int y, mlx_image_t *mlx_img)
{
    cells[x  + 3 ][y + 1] = 1;
    cells[x][y + 1] = 1;
    cells[x + 1][y] = 1;
    cells[x + 1][y + 2] = 1;
    cells[x + 2][y] = 1;
    cells[x + 2][y + 2] = 1;

}
void draw_a_loaf(int x, int y, mlx_image_t *mlx_img)
{
    cells[x][y + 2] = 1;
    cells[x][y + 1] = 1;
    cells[x + 1][y] = 1;
    cells[x + 1][y + 3] = 1;
    cells[x + 2][ 1 +y] = 1;
    cells[x + 2][y + 3] = 1;
    cells[x + 3][y + 2] = 1;

}
void draw_a_boat(int x, int y, mlx_image_t *mlx_img)
{
    cells[x][y] = 1;
    cells[x][y + 1] = 1;
    cells[x + 1][y] = 1;
    cells[x + 1][y + 2] = 1;
    cells[x + 2][y + 1] = 1;
}
void draw_a_tub(int x, int y, mlx_image_t *mlx_img)
{
    cells[x][y + 1] = 1;
    cells[x + 1][y] = 1;
    cells[x + 1][y + 2] = 1;
    cells[x + 2][y + 1] = 1;
}

void    first_cells()
{  
    cells[rand() % WIDTH][rand() % HEITH] = 1;
    cells[rand() % WIDTH][rand() % HEITH] = 1;
    cells[rand() % WIDTH][rand() % HEITH] = 1;
    cells[rand() % WIDTH][rand() % HEITH] = 1;
    cells[rand() % WIDTH][rand() % HEITH] = 1;
}
void    immortal_cell()
{
    cells[rand() % (WIDTH - 5)][rand() % (HEITH - 5)] = 5;
    cells[rand() % (WIDTH - 5)][rand() % (HEITH - 5)] = 5;
    cells[rand() % (WIDTH - 5)][rand() % (HEITH - 5)] = 5;
    cells[rand() % (WIDTH - 5)][rand() % (HEITH - 5)] = 5;
    cells[rand() % (WIDTH - 5)][rand() % (HEITH - 5)] = 5;
    cells[rand() % (WIDTH - 5)][rand() % (HEITH - 5)] = 5;
    cells[rand() % (WIDTH - 5)][rand() % (HEITH - 5)] = 5;
    cells[rand() % (WIDTH - 5)][rand() % (HEITH - 5)] = 5;
    cells[rand() % (WIDTH - 5)][rand() % (HEITH - 5)] = 5;
    cells[rand() % (WIDTH - 5)][rand() % (HEITH - 5)] = 5;
    cells[rand() % (WIDTH - 5)][rand() % (HEITH - 5)] = 5;
    cells[rand() % (WIDTH - 5)][rand() % (HEITH - 5)] = 5;
}
void    generate_still_lifes()
{
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void draw_map(mlx_image_t *mlx_img)
{
    for(int i = 0 ; i < mlx->height; i += TILE)
    {
        for(int j = 0 ; j < mlx->width; j++)
        {
            mlx_put_pixel(mlx_img, i, j, create_trgb(255, 255, 255, 255));
            // mlx_put_pixel(mlx_img, i, j, i);
        }
    }
    for(int j = 0 ; j < mlx->width; j += TILE)
    {
        for(int i = 0 ; i < mlx->height; i++)
        {
            mlx_put_pixel(mlx_img, i, j, create_trgb(255, 255, 255, 255));
        }
    }
}

void    draw_a_cell(int x, int y, mlx_image_t *mlx_img, int color)
{
    // std::cout << x << " | " << y << std::endl;
    // unsigned int color = create_trgb(rand(),rand(),rand(),rand());
    for(int i = 0; i < TILE;i++)
        for(int j = 0; j < TILE;j++)
            mlx_put_pixel(mlx_img, i + x, j + y, (int)color);
            // mlx_put_pixel(mlx_img, i + x, j + y, create_trgb(0,255,0,255));
            // mlx_put_pixel(mlx_img, i, j, create_trgb(0,255,0,255));
            // mlx_put_pixel(mlx_img, i, j, create_trgb(255, 255, 255, 255));
}

void    draw_cells(mlx_image_t *mlx_img)
{
    // for ( int i = 100 ; i < mlx->width && i < mlx->height; i += 100)
    //     draw_a_cell(i, i, mlx_img);
    // draw_a_cell(mlx->width - 200, mlx->height - 200);
    // draw_a_cell(mlx->width - 150, mlx->height - 150);
    // draw_a_cell(mlx->width - 100, mlx->height - 100);
    // draw_a_cell(9 * 5, 11 * 5 , mlx_img);
    // draw_a_cell(10 * 5, 11 * 5 , mlx_img);
    // draw_a_cell(10 * 5, 12 * 5 , mlx_img);
    // draw_a_cell(11 * 5, 13 * 5 , mlx_img);
    // draw_a_cell(mlx->width - 25, mlx->height - 25);
    for(int i = 0; i < cells.size();i++)
        for(int j = 0; j < cells[i].size();j++)
        {
            if(cells[i][j] == 1)
                draw_a_cell(i * TILE, j * TILE , mlx_img, create_trgb(0,255,0,255));
            if(cells[i][j] == 5)
            {
                draw_a_cell(i * TILE, j * TILE , mlx_img, 89462);
                std::cout << "d" << std::endl;
            }
        }
}

void    update_map()
{
    if (alive < 1000)
    {
        immortal_cell();
        generate_still_lifes();
    }
    for(int i =0; i < cells.size();i++)
    {
        for(int j =0; j < cells[i].size();j++)
        {
            cells[i][j] = clone_cells[i][j];
            // std::cout << clone_cells[i][j];
            clone_cells[i][j] = 0;
        }
        // std::cout << std::endl;
    }
    // std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;
}

void    next_generation()
{
    int flag = 0;

    for(int i =0; i < HEITH;i++)   
    {
        for(int j =0; j < WIDTH;j++)
        {
            if (i < HEITH - 1 && j&& cells[i+1][j - 1])
                flag++;
            if (i && j < WIDTH - 1&& cells[i-1][j + 1])
                flag++;
            if (i && cells[i-1][j])
                flag++;
            if (i && j && cells[i-1][j-1])
                flag++;
            if (j && cells[i][j - 1])
                flag++;
            if (i < HEITH - 1 && cells[i + 1][j])
                flag++;
            if (i < HEITH - 1 && j < WIDTH && cells[i+1][j+1])
                flag++;
            if (j< WIDTH - 1 && cells[i][j + 1])
                flag++;
            if (cells[i][j] == 0 && flag == 3)
                {
                    clone_cells[i][j] = 1;
                    alive++;
                }
            else if (cells[i][j] == 1 && flag > 3)
                {
                    clone_cells[i][j] = 0;
                }
            else if (cells[i][j] == 1 && flag < 2)
                {
                    clone_cells[i][j] = 0;
                }
            else if (cells[i][j] == 1 && (flag == 3 || flag == 2))
                {
                    clone_cells[i][j] = 1;
                    alive++;
                }
            if (cells[i][j] == 5 && flag > 5)
                immortal_cell();
            // if (flag < 2)
            //     clone_cells[i][j] = 0;
            // else if (flag > 2)
            //     clone_cells[i][j] = 1;
            // else
            //     clone_cells[i][j] = cells[i][j];

            // std::cout << flag;
            flag = 0;
        }
        // std::cout << std::endl;
    }
    // std::cout << "###############################################\n";
}

void frame(void *h)
{
    // first_cells();
    if (!mehdi_s_flag)
    {
        if (mlx_img)
            mlx_delete_image(mlx, mlx_img);

        mlx_img = mlx_new_image(mlx, mlx->width, mlx->height);
        // std::cout << mlx_img << std::endl;
        draw_map(mlx_img);
        draw_cells(mlx_img);
        next_generation();
        update_map();
        mlx_image_to_window(mlx, mlx_img, 0, 0);
    }
    // exit(0);
    // usleep(50000);
    // usleep(5000);
    // usleep(500000);
}

void key_event(mlx_key_data_t key, void* param)
{
    // if (mehdi_s_flag == 0 && key.key == 32) 
    //     mehdi_s_flag = 1;
    // goto mehdi;
    // while(mehdi_s_flag == 1)
    // {
    //     // usleep(1000);
    //     if (key.key == 32)
    //     {
    //         mehdi_s_flag = 0;
    //         break;
    //     }
    // }
    // if (key.key == 32 && key.action == MLX_RELEASE && mehdi_s_flag == 0)
    // {
    //     // mehdi_s_flag = 1;
    //     std::cout << key.action << " ass\n";
    //     sleep(5);
    // }
    if (key.key == 32 && key.action == MLX_RELEASE)
    {
        mehdi_s_flag = !mehdi_s_flag;
    }
    if (key.key == 256)
        exit(256);
    // mehdi:
    // if (key.action == MLX_RELEASE)
    //     std::cout << key.key << std::endl;
}

int main(int ac, char **av)
{
    // kk(NULL);
    mlx = mlx_init((WIDTH + 1) * TILE, (HEITH + 1) * TILE, "ss", 0);
    // mlx = mlx_init();
    // mlx_win = mlx_new_window(mlx, 500, 500, "game of life");
    generate_still_lifes();
    // generate_still_lifes();
    // generate_still_lifes();
    // generate_still_lifes();
    // generate_still_lifes();
    // generate_still_lifes();
    immortal_cell();
    mlx_loop_hook(mlx, frame,  NULL);
    mlx_key_hook(mlx, &key_event, NULL);
    mlx_loop(mlx);
    return (0);
}

// {
// typedef struct mlx_image
// 	const uint32_t	width;
// 	const uint32_t	height;
// 	uint8_t*		pixels;
// 	mlx_instance_t*	instances;
// 	int32_t			count;
// 	bool			enabled;
// 	void*			context;
// }	mlx_image_t;

// c++  -lglfw -L"/Users/abelahce/.brew/opt/glfw/lib" main.cpp /Users/abelahce/Desktop/game-of-life/scayho/MLX42/build/libmlx42.a -o game_of_life && ./game_of_life