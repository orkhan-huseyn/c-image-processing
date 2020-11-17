void ImageReader(
    const char *image_name,
    int *_bit_depth,
    unsigned char *_header,
    unsigned char *_color_table,
    unsigned char *_buffer);

void ImageWriter(
    const char *image_name,
    int *bit_depth,
    unsigned char *header,
    unsigned char *color_table,
    unsigned char *buffer);
