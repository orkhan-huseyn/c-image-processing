#include <stdio.h>

#include "constants.h"
#include "image_copy.h"

int main(int argc, char *argv[])
{
    unsigned char header[BMP_HEADER_SIZE];
    unsigned char color_table[BMP_COLOR_TABLE_SIZE];
    unsigned char buffer[CUSTOM_IMAGE_SIZE];
    int bit_depth;

    image_reader("cameraman.bmp", &bit_depth, header, color_table, buffer);
    image_writer("cameraman_copy.bmp", &bit_depth, header, color_table, buffer);

    printf("Success!\n");
    return 0;
}
