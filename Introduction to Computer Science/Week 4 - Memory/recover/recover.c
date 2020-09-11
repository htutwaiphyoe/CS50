#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // check the file is given
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }


    FILE *inputFile = fopen(argv[1], "r");

    // check file is null
    if (inputFile == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", argv[1]);
        return 1;
    }

    // declaring buffer
    unsigned char *buffer = malloc(512);

    // output file
    FILE *outputFile;

    // each image file name
    char filename[8];

    // image count
    int count = 0;


    // loop for reading file
    while (fread(buffer, 512, 1, inputFile))
    {

        // check if jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // check reading
            if (count > 0)
            {
                fclose(outputFile);
            }

            // make image file
            sprintf(filename, "%03d.jpg", count);

            // open output file
            outputFile = fopen(filename, "w");

            // write output file
            fwrite(buffer, 512, 1, outputFile);

            // increment image count
            count++;
        }

        else
        {
            // reading
            if (count > 0)
            {
                fwrite(buffer, 512, 1, outputFile);
            }
        }
    }

    // close files
    fclose(outputFile);
    fclose(inputFile);

    // clear memory
    free(buffer);
    return 0;

}
