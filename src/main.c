#include "uart.h"
#include "mbox.h"
#include "framebf.h"
#include "printf.h"
#include "fish.h"
void main()
{
    // set up serial console
    uart_init();
    framebf_init();
    // say hello
    printf("\n\n");
    printf("                               #####  #        #####    ###    \n");
    printf("###### ###### ###### #####    #     # #    #  #     #  #   #   \n");
    printf("#      #      #        #            # #    #  #     # #     #  \n");
    printf("#####  #####  #####    #       #####  #    #   ###### #     #  \n");
    printf("#      #      #        #      #       #######       # #     #  \n");
    printf("#      #      #        #      #            #  #     #  #   #   \n");
    printf("###### ###### ######   #      #######      #   #####    ###    \n");
    printf("                                                               \n");
    printf("######     #    ######  #######    #######  #####              \n");
    printf("#     #   # #   #     # #          #     # #     #             \n");
    printf("#     #  #   #  #     # #          #     # #                   \n");
    printf("######  #     # ######  #####      #     #  #####              \n");
    printf("#     # ####### #   #   #          #     #       #             \n");
    printf("#     # #     # #    #  #          #     # #     #             \n");
    printf("######  #     # #     # #######    #######  #####              \n");
    printf("\n\n");
    printf("\n\n");
    printf("\n\n");
    printf("bareos ~ % ");

    char *buffer;
    int count = 0;
    // echo everything back
    while (1)
    {
        // read each char
        buffer++;
        *buffer = uart_getc();
        // send back twice
        // printf("%d", *buffer);
        uart_sendc(*buffer);

        if (*buffer == 10)
        {
            for (int i = count; i > 0; i--)
            {
                // printf("%c", *(buffer - i));
            }
            if (checkCommand(buffer - count, "help"))
            {
                listOfCommands();
            }
            if (checkCommand(buffer - count, "cl"))
            {
                cl();
            }
            if (checkCommand(buffer - count, "cls"))
            {
                cls();
            }
            if (checkCommand(buffer - count, "shape"))
            {
                shape();
            }
            if (checkCommand(buffer - count, "image"))
            {
                image();
            }
            printf("\n");
            printf("bareos ~ % ");
            char *new;
            buffer = new;
            count = -1;
        }
        count++;
    }
}

void cl()
{
    for (int i = 0; i < 100; i++)
    {
        printf("\n");
    }
}

void shape()
{
    // Draw something on the screen
    drawRectARGB32(100, 100, 400, 400, 0x00AA0000, 1); // RED
    drawRectARGB32(150, 150, 400, 400, 0x0000BB00, 1); // GREEN
    drawRectARGB32(200, 200, 400, 400, 0x000000CC, 1); // BLUE
    drawRectARGB32(250, 250, 400, 400, 0x00FFFF00, 1); // YELLOW
    drawPixelARGB32(300, 300, 0x00FF0000);             // RED
}
void cls()
{
    // Draw something on the screen
    drawRectARGB32(100, 100, 400, 400, 0x00000000, 1); // RED
    drawRectARGB32(150, 150, 400, 400, 0x00000000, 1); // GREEN
    drawRectARGB32(200, 200, 400, 400, 0x00000000, 1); // BLUE
    drawRectARGB32(250, 250, 400, 400, 0x00000000, 1); // YELLOW
    drawPixelARGB32(300, 300, 0x00000000);             // RED
}

void listOfCommands()
{
    printf("list of commands\n");
    printf("help    -     print list of commands\n");
    printf("image   -     print an image\n");
    printf("shape   -     print a shape\n");
    printf("cl      -     clear cli\n");
    printf("cls     -     clear display screen\n");
}

int checkCommand(char *string, char *command)
{
    // printf("checking\n");
    while (*(string) == *(command))
    {
        // printf("%c", *string);
        string++;
        command++;
    }
    if (*(command) == 0)
    {
        return 1;
    }

    return 0;
}

void image()
{
    int j = 0;
    for (int i = 0; i < 90000; i++)
    {
        if (i % 300 == 0)
        {
            j++;
            printf("\n");
        }
        drawPixelARGB32(i % 300, j, fish[i]);

        printf("%d", fish[i]);
    }
}
