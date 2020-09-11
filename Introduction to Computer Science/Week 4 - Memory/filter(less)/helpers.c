#include "helpers.h"
#include <math.h>
#include <string.h>
int makeLegit(int color);
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // loop for each pixel

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // get each pixel value
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            // find average for gray
            int gray = round((red + green + blue) / 3.00);

            // set average to each pixel value
            image[i][j].rgbtRed = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtBlue = gray;
        }
    }
    return;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // make sepia color
            int sepiaRed = makeLegit(round(0.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue));
            int sepiaGreen = makeLegit(round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue));
            int sepiaBlue = makeLegit(round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue));

            // set sepia color to each pixel
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;


        }
    }
    return;
}

// decide not to greater than 255
int makeLegit(int color)
{
    if (color > 255)
    {
        return 255;
    }
    return color;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // make temporary
    RGBTRIPLE temp;

    // loop for each pixel
    for (int i = 0; i < height; i++)
    {
        // loop for half width
        for (int j = 0; j < width / 2; j++)
        {
            // swap pixel
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // temporary
    RGBTRIPLE temp[height][width];

    // get old version copy
    memcpy(temp, image, sizeof(RGBTRIPLE) * height * width);

    // loop for each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // initialize rgb value
            float count = 0.0;
            int red = 0;
            int green = 0;
            int blue = 0;

            // loop for out of border
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // check for out of border
                    if (i + k != height && i + k != -1 && j + l != width && j + l != -1)
                    {
                        // set rgb value
                        red += temp[i + k][j + l].rgbtRed;
                        green += temp[i + k][j + l].rgbtGreen;
                        blue += temp[i + k][j + l].rgbtBlue;
                        count++;
                    }
                }
            }

            // set rgb value to current pixel
            image[i][j].rgbtRed = round(red / count);
            image[i][j].rgbtGreen = round(green / count);
            image[i][j].rgbtBlue = round(blue / count);
        }
    }
    return;
}
