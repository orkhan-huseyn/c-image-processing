#include <stdio.h>

#include "constants.h"

void image_reader(
    const char *image_name,
    int *_bit_depth,
    unsigned char *_header,
    unsigned char *_color_table,
    unsigned char *_buffer)
{
    FILE *fin = fopen(image_name, "rb");

    if (fin == (FILE *)0)
    {
        printf("Unable to open file.\n");
    }

    for (int i = 0; i < BMP_HEADER_SIZE; i++)
    {
        _header[i] = getc(fin);
    }

    *_bit_depth = *(int *)&_header[28];

    if (*_bit_depth <= 8)
    {
        fread(_color_table, sizeof(unsigned char), BMP_COLOR_TABLE_SIZE, fin);
    }

    fread(_buffer, sizeof(unsigned char), CUSTOM_IMAGE_SIZE, fin);

    fclose(fin);
}

void image_writer(
    const char *image_name,
    int *bit_depth,
    unsigned char *header,
    unsigned char *color_table,
    unsigned char *buffer)
{
    FILE *fout = fopen(image_name, "wb");
    fwrite(header, sizeof(unsigned char), BMP_HEADER_SIZE, fout);

    if (*bit_depth <= 8)
    {
        fwrite(color_table, sizeof(unsigned char), BMP_COLOR_TABLE_SIZE, fout);
    }

    fwrite(buffer, sizeof(unsigned char), CUSTOM_IMAGE_SIZE, fout);
    fclose(fout);
}
