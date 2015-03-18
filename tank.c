/*
* Program Just For Fun
*
* by wzt       http://www.cloud-sec.org
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENTH           7
#define WIDTH           155

#define SLEEP_TIME      30000
#define ENTER_NUM       20

char fun_ascii[LENTH][WIDTH] = {
"                                                                                                                                                  |       ",
"                                                                                                                                            _\\--__|_     ",
"                                                                                                                           II=======OOOOO[/ *02 ___|      ",
"                                                                                                                                      ____\\______|/-----.",
"                                                                                                                                    /____________________|",
"                                                                                                                                   \\@@@@@@@@@@@@@@@@@@@/ ",
"                                                                                                                                     ~~~~~~~~~~~~~~~~~~~ "
};

int g_shoot_pos;
int g_shoot_pos_static;

void display_ascii(void);
void print_enter(void);

void move_ascii(void)
{
        int i, j;

        for (i = 0; i < LENTH; i++) {
                for (j = 0; j < WIDTH; j++) {
                        if (fun_ascii[i][j] != ' ') {
                                fun_ascii[i][j - 1] = fun_ascii[i][j];
                                fun_ascii[i][j] = ' ';
                        }
                }
        }
}

void shoot_init(void)
{
        int i, j;

        for (j = 0; j < WIDTH; j++) {
                if (fun_ascii[2][j] != ' ')
                        break;
        }
        --j;

        g_shoot_pos_static = g_shoot_pos = j;
}

void shoot_begin(void)
{
        fun_ascii[2][g_shoot_pos] = 'O';

        system("clear");
        print_enter();
        display_ascii();
        fun_ascii[2][g_shoot_pos] = ' ';
}

void shoot_ascii(void)
{
        int i;

        i = WIDTH / 2 - 1;

        while (i > 0 && g_shoot_pos > 0) {
                shoot_begin();
                g_shoot_pos--;
                usleep(SLEEP_TIME);
                i--;
        }
}

void do_shoot_ascii(void)
{
        int i = 3;

        shoot_init();

        while (i > 0) {
                shoot_ascii();
                g_shoot_pos = g_shoot_pos_static;
                i--;
        }
}

void display_ascii(void)
{
        int i, j;

        for (i = 0; i < LENTH; i++) {
                for (j = 0; j < WIDTH; j++)
                        printf("%c", fun_ascii[i][j]);
                printf("\n");
        }
}

void print_enter(void)
{
        int i;

        for (i = 0; i < ENTER_NUM; i++)
                printf("\n");
}

int main(void)
{
        int i = WIDTH;

        while (i > 0) {
                if (i == (WIDTH / 2)) {
                        do_shoot_ascii();
                        i--;
                        continue;
                }
                system("clear");
                print_enter();
                move_ascii();
                display_ascii();
                i--;
                usleep(SLEEP_TIME);
        }

        return 0;
}

