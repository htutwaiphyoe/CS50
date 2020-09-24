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
            int gray = round((image[h][w].rgbtBlue + image[h][w].rgbtRed + image[h][w].rgbtGreen) / 3.00);

            image[h][w].rgbtBlue = gray;
            image[h][w].rgbtRed = gray;
            image[h][w].rgbtGreen = gray;

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
            int red = image[h][w].rgbtRed;
            int green = image[h][w].rgbtGreen;

            image[h][w].rgbtBlue = image[h][width - w - 1].rgbtBlue;
            image[h][w].rgbtRed = image[h][width - w - 1].rgbtRed;
            image[h][w].rgbtGreen = image[h][width - w - 1].rgbtGreen;

            image[h][width - w - 1].rgbtBlue = blue;
            image[h][width - w - 1].rgbtRed = red;
            image[h][width - w - 1].rgbtGreen = green;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    memcpy(copy, image, sizeof(RGBTRIPLE) * height * width);
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int red = 0, green = 0, blue = 0;
            float count = 0.0;

            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    if (i + h != height && i + h != -1 && w + j != width && w + j != -1)
                    {
                        red += copy[i + h][w + j].rgbtRed;
                        blue += copy[i + h][w + j].rgbtBlue;
                        green += copy[i + h][w + j].rgbtGreen;
                        count++;
                    }

                }
            }

            image[h][w].rgbtRed = round(red / count);
            image[h][w].rgbtBlue = round(blue / count);
            image[h][w].rgbtGreen = round(green / count);


        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    memcpy(copy, image, sizeof(RGBTRIPLE) * height * width);

    int Gx[3][3] = { {-1, 0, 1}, {-2, 0, 2}, { -1, 0, 1}};
    int Gy[3][3] = { {-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int Gxred = 0, Gxgreen = 0, Gxblue = 0, Gyred = 0, Gyblue = 0, Gygreen = 0;


            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    if (i + h != height && i + h != -1 && w + j != width && w + j != -1)
                    {

                        Gxred += Gx[i + 1][j + 1] * copy[i + h][w + j].rgbtRed;
                        Gxblue += Gx[i + 1][j + 1] * copy[i + h][w + j].rgbtBlue;
                        Gxgreen += Gx[i + 1][j + 1] * copy[i + h][w + j].rgbtGreen;
                        Gyred += Gy[i + 1][j + 1] * copy[i + h][w + j].rgbtRed;
                        Gyblue += Gy[i + 1][j + 1] * copy[i + h][w + j].rgbtBlue;
                        Gygreen += Gy[i + 1][j + 1] * copy[i + h][w + j].rgbtGreen;

                    }

                }
            }

            int red = round(sqrt((pow(Gxred, 2) + pow(Gyred, 2))));
            int blue = round(sqrt((pow(Gxblue, 2) + pow(Gyblue, 2))));
            int green = round(sqrt((pow(Gxgreen, 2) + pow(Gygreen, 2))));

            if (red >= 255)
            {
                red = 255;
            }
            if (blue >= 255)
            {
                blue = 255;
            }
            if (green >= 255)
            {
                green = 255;
            }

            image[h][w].rgbtRed = red;
            image[h][w].rgbtBlue = blue;
            image[h][w].rgbtGreen = green;


        }
    }
    return;
}
