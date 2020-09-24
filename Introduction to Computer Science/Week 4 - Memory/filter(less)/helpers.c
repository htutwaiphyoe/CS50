#include "helpers.h"
#include <math.h>
#include <string.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int gray = round((image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed) / 3.00);
            image[h][w].rgbtBlue = gray;
            image[h][w].rgbtGreen = gray;
            image[h][w].rgbtRed = gray;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int blue = image[h][w].rgbtBlue;
            int green = image[h][w].rgbtGreen;
            int red = image[h][w].rgbtRed;

            int sepiaRed = round(.393 * red + .769 * green + .189 * blue);
            int sepiaGreen = round(.349 * red + .686 * green + .168 * blue);
            int sepiaBlue = round(.272 * red + .534 * green + .131 * blue);

            if (sepiaRed >= 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen >= 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue >= 255)
            {
                sepiaBlue = 255;
            }

            image[h][w].rgbtRed = sepiaRed;
            image[h][w].rgbtGreen = sepiaGreen;
            image[h][w].rgbtBlue = sepiaBlue;

        }
    }


    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width / 2; w++)
        {

            int blue = image[h][w].rgbtBlue;
            int green = image[h][w].rgbtGreen;
            int red = image[h][w].rgbtRed;

            image[h][w].rgbtBlue = image[h][width - w - 1].rgbtBlue;
            image[h][w].rgbtGreen = image[h][width - w - 1].rgbtGreen;
            image[h][w].rgbtRed = image[h][width - w - 1].rgbtRed;

            image[h][width - w - 1].rgbtBlue = blue;
            image[h][width - w - 1].rgbtGreen = green;
            image[h][width - w - 1].rgbtRed = red;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    // get old version copy not to affect original image
    memcpy(temp, image, sizeof(RGBTRIPLE) * height * width);
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int blue = 0, red = 0, green = 0;
            float count = 0;

            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    if (i + h != height && i + h != -1 && j + w != -1 && j + w != width)
                    {
                        blue += temp[i + h][j + w].rgbtBlue;
                        red += temp[i + h][j + w].rgbtRed;
                        green += temp[i + h][j + w].rgbtGreen;
                        count++;
                    }
                }
            }

            image[h][w].rgbtBlue = round(blue / count);
            image[h][w].rgbtRed = round(red / count);
            image[h][w].rgbtGreen = round(green / count);

        }
    }
    return;
}
