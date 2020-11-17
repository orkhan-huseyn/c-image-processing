#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE *fin = fopen("lena_color.bmp", "rb");
  FILE *fout = fopen("lena_gray.bmp", "wb");

  if (fin == NULL)
  {
    printf("Unable to open image\n");
  }

  unsigned char img_header[54];
  unsigned char color_table[1024];

  for (int i = 0; i < 54; i++)
  {
    img_header[i] = getc(fin);
  }

  fwrite(img_header, sizeof(unsigned char), 54, fout);

  int width = *(int *)&img_header[18];
  int height = *(int *)&img_header[22];
  int bit_depth = *(int *)&img_header[28];

  if (bit_depth <= 8)
  {
    fread(color_table, sizeof(unsigned char), 1024, fin);
    fwrite(color_table, sizeof(unsigned char), 1024, fout);
  }

  int image_size = width * height;
  unsigned char buffer[image_size][3];

  for (int i = 0; i < image_size; i++)
  {
    buffer[i][0] = getc(fin); // red
    buffer[i][1] = getc(fin); // green
    buffer[i][2] = getc(fin); // blue

    // grayscale formula taken from here: https://rosettacode.org/wiki/Grayscale_image
    int temp = (buffer[i][0] * 0.2126) + (buffer[i][1] * 0.7152) + (buffer[i][2] * 0.0722);

    putc(temp, fout);
    putc(temp, fout);
    putc(temp, fout);
  }

  fclose(fin);
  fclose(fout);

  printf("Success!\n");

  return 0;
}