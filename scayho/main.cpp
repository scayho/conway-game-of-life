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
int WIDTH = 200;
int HEITH = 200;
int mehdi_s_flag = 0;
int alive = 1;
unsigned long long speed_ = 1;


int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

class TCGA {

    protected :
         int color;
         int token;
    public :
        TCGA()
        {
            // token = rand() % 8;
            // if (token == 1)
            //     color = create_trgb(0, 255,0,0);
            // else if (token == 2)
            //     color = create_trgb(0, 0,255,0);
            // // else if (token == 3)
            // //     color = create_trgb(00,0,0,255);
            // // else if (!token)
            // //     color = create_trgb(0,255,255,0);
            // else
            token = 0;
            color = create_trgb(0,255,255,255);
        }
        ~TCGA()
        {
            token = 0;
            color = 0;
        }
         int get_color()
        {
            return (color);
        }
         int get_token()
        {
            return (token);
        }
        void set_color( int g)
        {
            color = g;
        }
        void set_token( int g)
        {
            if (g == 1)
                color = create_trgb(0, 255,0,255);
            if (g == 2)
                color = create_trgb(0, 0,255,255);
            token = g;
        }
        void operator=(TCGA &h)
        {
            color = h.get_color();
            token = h.get_token();
        }
} ;

std::vector<std::vector<TCGA> >  cells(HEITH, std::vector<TCGA>(WIDTH, TCGA()));
std::vector<std::vector<TCGA> >  clone_cells(HEITH, std::vector<TCGA>(WIDTH, TCGA()));
mlx_t *mlx;
mlx_image_t *mlx_img;



void draw_a_Glider(int x, int y, mlx_image_t *mlx_img)
{
    cells[x][y + 1].set_token(1);
    cells[x + 1][y + 2].set_token(1);
    cells[x + 2][y].set_token(1);
    cells[x + 2][y + 1].set_token(1);
    cells[x + 2][y + 2].set_token(1);
    // 0 1 0 
    // 0 0 1
    // 1 1 1
}

void draw_a_line(int x, int y, mlx_image_t *mlx_img)
{
    cells[x][y].set_token(1);
    cells[x][y+1].set_token(1);
    cells[x][y+2].set_token(1);

}
void draw_a_block(int x, int y, mlx_image_t *mlx_img)
{
    cells[x][y].set_token(1);
    cells[x + 1][y].set_token(1);
    cells[x][y + 1].set_token(1);
    cells[x+1][y+1].set_token(1);
}

void draw_a_beehive(int x, int y, mlx_image_t *mlx_img)
{
    cells[x  + 3 ][y + 1].set_token(1);
    cells[x][y + 1].set_token(1);
    cells[x + 1][y].set_token(1);
    cells[x + 1][y + 2].set_token(1);
    cells[x + 2][y].set_token(1);
    cells[x + 2][y + 2].set_token(1);

}
void draw_a_loaf(int x, int y, mlx_image_t *mlx_img)
{
    cells[x][y + 2].set_token(1);
    cells[x][y + 1].set_token(1);
    cells[x + 1][y].set_token(1);
    cells[x + 1][y + 3].set_token(1);
    cells[x + 2][ 1 +y].set_token(1);
    cells[x + 2][y + 3].set_token(1);
    cells[x + 3][y + 2].set_token(1);

}
void draw_a_boat(int x, int y, mlx_image_t *mlx_img)
{
    cells[x][y].set_token(1);
    cells[x][y + 1].set_token(1);
    cells[x + 1][y].set_token(1);
    cells[x + 1][y + 2].set_token(1);
    cells[x + 2][y + 1].set_token(1);
}
void draw_a_tub(int x, int y, mlx_image_t *mlx_img)
{
    cells[x][y + 1].set_token(1);
    cells[x + 1][y].set_token(1);
    cells[x + 1][y + 2].set_token(1);
    cells[x + 2][y + 1].set_token(1);
}

void    first_cells()
{  
    for(int i = 0; i < 5;i++)
        cells[rand() % WIDTH][rand() % HEITH].set_token(1);
}
void    immortal_cell()
{
    for(int i = 0; i < 50;i++)
        cells[rand() % (WIDTH - 5)][rand() % (HEITH - 5)].set_token(2);
}
void    generate_still_lifes()
{
    for(int i = 0; i < 70; i++)
    {
        draw_a_tub((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
        draw_a_beehive((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
        draw_a_loaf((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
        draw_a_boat((rand() % (WIDTH - 5)), (rand() % (HEITH - 5)), mlx_img);
        draw_a_Glider((rand() % ((WIDTH - 5) / 2)), (rand() % ((HEITH - 5) / 2)), mlx_img);
    }
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
    for(int i = 0; i < TILE;i++)
        for(int j = 0; j < TILE;j++)
            mlx_put_pixel(mlx_img, i + x, j + y, (int)color);
}

void    draw_cells(mlx_image_t *mlx_img)
{
    for(int i = 0; i < cells.size();i++)
        for(int j = 0; j < cells[i].size();j++)
        {
            if(cells[i][j].get_token() == 1)
                draw_a_cell(i * TILE, j * TILE , mlx_img, cells[i][j].get_color());
            if(cells[i][j].get_token() == 2)
                draw_a_cell(i * TILE, j * TILE , mlx_img, cells[i][j].get_color());
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
            cells[i][j].set_token(clone_cells[i][j].get_token());
            clone_cells[i][j].set_token(0);
        }
    }
}

void    next_generation()
{
    int flag = 0;

    for(int i =0; i < HEITH;i++)   
    {
        for(int j =0; j < WIDTH;j++)
        {
            if (i < HEITH - 1 && j && cells[i+1][j - 1].get_token())
                flag++;
            if (i && j < WIDTH - 1 && cells[i-1][j + 1].get_token())
                flag++;
            if (i && cells[i-1][j].get_token())
                flag++;
            if (i && j && cells[i-1][j-1].get_token())
                flag++;
            if (j && cells[i][j - 1].get_token())
                flag++;
            if (i < HEITH - 1 && cells[i + 1][j].get_token())
                flag++;
            if (i < HEITH - 1 && j < WIDTH && cells[i+1][j+1].get_token())
                flag++;
            if (j< WIDTH - 1 && cells[i][j + 1].get_token())
                flag++;
            if (cells[i][j].get_token() == 0 && flag == 3)
                {
                    clone_cells[i][j].set_token(1);
                    alive++;
                }
            else if (cells[i][j].get_token() == 1 && flag > 3)
                {
                    clone_cells[i][j].set_token(0);
                }
            else if (cells[i][j].get_token() == 1 && flag < 2)
                {
                    clone_cells[i][j].set_token(0);
                }
            else if (cells[i][j].get_token() == 1 && (flag == 3 || flag == 2))
                {
                    clone_cells[i][j].set_token(1);
                    alive++;
                }
            if (cells[i][j].get_token() == 2)
                    clone_cells[i][j].set_token(2);
            if (cells[i][j].get_token() == 5 && flag > 5)
                immortal_cell();
            flag = 0;
        }
    }
}

void frame(void *h)
{
    if (!mehdi_s_flag)
    {
        if (mlx_img)
            mlx_delete_image(mlx, mlx_img);

        mlx_img = mlx_new_image(mlx, mlx->width, mlx->height);
        // draw_map(mlx_img);
        draw_cells(mlx_img);
        next_generation();
        update_map();
        mlx_image_to_window(mlx, mlx_img, 0, 0);
    }
    usleep(speed_);
    std::cout << speed_ << std::endl;
}

void key_event(mlx_key_data_t key, void* param)
{
    std::cout << key.key << std::endl;
    if ((key.key == 75 || key.key == 334) && key.action == MLX_RELEASE)
    {
        if (speed_ > 5000)
            speed_ -= 5000;
    }
    if ((key.key == 74 || key.key == 333) && key.action == MLX_RELEASE)
    {
        if (speed_ + 5000 < INT_MAX)
            speed_ += 5000;
    }
    if (key.key == 32 && key.action == MLX_RELEASE)
    {
        mehdi_s_flag = !mehdi_s_flag;
    }
    if (key.key == 256)
        exit(256);
}

int main(int ac, char **av)
{
    mlx = mlx_init((WIDTH + 1) * TILE, (HEITH + 1) * TILE, "ss", 0);
    generate_still_lifes();
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