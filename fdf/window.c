#include "minilibx/mlx.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int running = 1;

int update_window(void *param)
{
    int x = 550;
    int y = 550;
    void *mlx_ptr = param;
    void *win_ptr = param;
    mlx_clear_window(mlx_ptr, win_ptr);
    while(y > 50)
    {
        x = 550;
        while (x > 50)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
            x--;
        }
        y--;
        sleep(1);
    }
    return (EXIT_SUCCESS);
}

void handle_signal(int signum) {
    if (signum == SIGINT || signum == SIGTERM) {
        running = 0;
        exit(EXIT_SUCCESS);
    }
}

int main(void)
{
    void *mlx_ptr;
    void *win_ptr;

//this initializes minilibx and the window pointer
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 600, 600, "CARALHO");
    //this one makes a window with the name and size we want

    // loop to update the window
    mlx_loop_hook(mlx_ptr, update_window, win_ptr);

//signal experiments to try and shut down the program
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    while (running)
    {
        mlx_loop(mlx_ptr);
    }
    if(!running)
    {
        mlx_destroy_window(mlx_ptr, win_ptr);
        exit(EXIT_SUCCESS);
    }
    exit(SIGTERM);
}

//solve the terminate process
//solve the grafics
