#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");

    if (f == NULL)
    {
        printf("Can't open file\n");
        return 1;
    }

    unsigned char *buffer = malloc(512);
    char image_name[8];
    FILE *image_file;
    int image_count = 0;
    bool reading = false;
    while (fread(buffer, 512, 1, f))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (image_count > 0)
            {
                reading = false;
                fclose(image_file);
            }
            reading = true;
            sprintf(image_name, "%03i.jpg", image_count);
            image_file = fopen(image_name, "w");

            fwrite(buffer, 512, 1, image_file);
            image_count++;

        }
        else
        {
            if (reading)
            {
                fwrite(buffer, 512, 1, image_file);
            }
        }
    }

    fclose(f);
    fclose(image_file);

    free(buffer);
}
