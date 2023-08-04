// #include "mlx.h"
// #include <stdlib.h>
// #include <stdio.h>
// #include <math.h>

// #define WIDTH 800
// #define HEIGHT 600

// typedef struct s_data {
//     void *mlx;
//     void *win;
// } t_data;

// void draw_circle_filled(t_data *data, int centerX, int centerY, int radius, int color) {
//     for (int y = centerY - radius; y <= centerY + radius; y++) {
//         for (int x = centerX - radius; x <= centerX + radius; x++) {
//             int dx = x - centerX;
//             int dy = y - centerY;
//             if (dx * dx + dy * dy <= radius * radius) {
//                 mlx_pixel_put(data->mlx, data->win, x, y, color);
//             }
//         }
//     }
// }

// int main() {
//     t_data data;
//     data.mlx = mlx_init();
//     data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Filled Circle Drawing");

//     int centerX = WIDTH / 2;
//     int centerY = HEIGHT / 2;
//     int radius = 100;
//     int color = 0x00FF0000; // Red color (format: 0x00RRGGBB)

//     draw_circle_filled(&data, centerX, centerY, radius, color);

//     mlx_loop(data.mlx);

//     return 0;
// }
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct s_data {
    void *mlx;
    void *win;
} t_data;

void draw_line(t_data *data, int x0, int y0, int x1, int y1, int color) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (x0 != x1 || y0 != y1)
	{
        mlx_pixel_put(data->mlx, data->win, x0, y0, color);
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

int main() {
    t_data data;
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Line Drawing");

    int x0 = 100;
    int y0 = 100;
    int x1 = 500;
    int y1 = 400;
    int color = 0x00FF0000; // Red color (format: 0x00RRGGBB)

    draw_line(&data, x0, y0, x1, y1, color);

    mlx_loop(data.mlx);

    return 0;
}


// #include "mlx.h"
// #include <stdlib.h>
// #include <stdio.h>

// #define WIDTH 800
// #define HEIGHT 600

// typedef struct s_data {
//     void *mlx;
//     void *win;
// } t_data;

// void draw_circle(t_data *data, int centerX, int centerY, int radius, int color) {
//     int x = 0;
//     int y = radius;
//     int d = 3 - 2 * radius;

//     while (x <= y) {
//         mlx_pixel_put(data->mlx, data->win, centerX + x, centerY + y, color);
//         mlx_pixel_put(data->mlx, data->win, centerX + x, centerY - y, color);
//         mlx_pixel_put(data->mlx, data->win, centerX - x, centerY + y, color);
//         mlx_pixel_put(data->mlx, data->win, centerX - x, centerY - y, color);
//         mlx_pixel_put(data->mlx, data->win, centerX + y, centerY + x, color);
//         mlx_pixel_put(data->mlx, data->win, centerX + y, centerY - x, color);
//         mlx_pixel_put(data->mlx, data->win, centerX - y, centerY + x, color);
//         mlx_pixel_put(data->mlx, data->win, centerX - y, centerY - x, color);

//         if (d <= 0) {
//             d = d + 4 * x + 6;
//         } else {
//             d = d + 4 * (x - y) + 10;
//             y--;
//         }
//         x++;
//     }
// }

// void draw_line_from_center(t_data *data, int centerX, int centerY, int x1, int y1, int color) {
//     int x0 = centerX;
//     int y0 = centerY;
//     int dx = x1 - x0;
//     int dy = y1 - y0;
//     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
//     float xIncrement = (float)dx / steps;
//     float yIncrement = (float)dy / steps;

//     float x = x0;
//     float y = y0;

//     for (int i = 0; i <= steps; i++) {
//         mlx_pixel_put(data->mlx, data->win, round(x), round(y), color);
//         x += xIncrement;
//         y += yIncrement;
//     }
// }

// int main() {
//     t_data data;
//     data.mlx = mlx_init();
//     data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Circle and Line Drawing");

//     int centerX = WIDTH / 2;
//     int centerY = HEIGHT / 2;
//     int radius = 100;
//     int lineEndX = 500;
//     int lineEndY = 400;
//     int colorCircle = 0x00FF0000; // Red color for circle (format: 0x00RRGGBB)
//     int colorLine = 0x0000FF00;   // Green color for line (format: 0x00RRGGBB)

//     draw_circle(&data, centerX, centerY, radius, colorCircle);
//     draw_line_from_center(&data, centerX, centerY, lineEndX, lineEndY, colorLine);

//     mlx_loop(data.mlx);

//     return 0;
// }

