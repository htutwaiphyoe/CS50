#include "helpers.h"
#include <math.h>
#include <string.h>

int bound(double n);
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // loop for each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculate average for to make gray
            int rgbGray = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.000);

            // set gray to each pixel
            image[i][j].rgbtBlue = rgbGray;
            image[i][j].rgbtGreen = rgbGray;
            image[i][j].rgbtRed = rgbGray;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // temporay for swap
    RGBTRIPLE rgb;

    // loop for each height
    for (int i = 0; i < height; i++)
    {
        // loop for each half width
        for (int j = 0; j < width / 2; j++)
        {
            // swap pixel
            rgb = image[i][j];

            image[i][j] = image[i][width - j - 1];

            image[i][width - j - 1] = rgb;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // temporay rgb
    RGBTRIPLE temp[height][width];

    // old version copy
    memcpy(temp, image, sizeof(RGBTRIPLE) * height * width);

    // loop for each pixel
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            float count = 0.0;
            int red = 0;
            int green = 0;
            int blue = 0;

            for (int k = -1; k <= 1; k++)
            {

                for (int l = -1; l <= 1; l++)
                {
                    // check for out of border
                    if (i + k != height && i + k != -1 && j + l != width && j + l != -1)
                    {
                        red += temp[i + k][j + l].rgbtRed;
                        green += temp[i + k][j + l].rgbtGreen;
                        blue += temp[i + k][j + l].rgbtBlue;
                        count++;
                    }
                }
            }

            image[i][j].rgbtRed = round(red / count);
            image[i][j].rgbtGreen = round(green / count);
            image[i][j].rgbtBlue = round(blue / count);
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float rGx, gGx, bGx, rGy, gGy, bGy;
            rGx = gGx = bGx = rGy = gGy = bGy = 0;


            if (i > 0)
            {
                rGy += -2 * copy[i-1][j].rgbtRed;
                gGy += -2 * copy[i-1][j].rgbtGreen;
                bGy += -2 * copy[i-1][j].rgbtBlue;
            }

            if (i < height - 1)
            {

                rGy += 2 * copy[i+1][j].rgbtRed;
                gGy += 2 * copy[i+1][j].rgbtGreen;
                bGy += 2 * copy[i+1][j].rgbtBlue;
            }

            if (j > 0)
            {
                rGx += -2 * copy[i][j-1].rgbtRed;
                gGx += -2 * copy[i][j-1].rgbtGreen;
                bGx += -2 * copy[i][j-1].rgbtBlue;

            }

             if (j < width - 1)
            {
                rGx += 2 * copy[i][j+1].rgbtRed;
                gGx += 2 * copy[i][j+1].rgbtGreen;
                bGx += 2 * copy[i][j+1].rgbtBlue;

            }

            if (i > 0 && j > 0)
            {
                // Note: change sign in Gx values here and the result changes side
                rGx += -1 * copy[i-1][j-1].rgbtRed;
                gGx += -1 * copy[i-1][j-1].rgbtGreen;
                bGx += -1 * copy[i-1][j-1].rgbtBlue;
                rGy += -1 * copy[i-1][j-1].rgbtRed;
                gGy += -1 * copy[i-1][j-1].rgbtGreen;
                bGy += -1 * copy[i-1][j-1].rgbtBlue;
            }

            if (i > 0 && j < width - 1)
            {
                rGx += 1 * copy[i-1][j+1].rgbtRed;
                gGx += 1 * copy[i-1][j+1].rgbtGreen;
                bGx += 1 * copy[i-1][j+1].rgbtBlue;
                rGy += -1 * copy[i-1][j+1].rgbtRed;
                gGy += -1 * copy[i-1][j+1].rgbtGreen;
                bGy += -1 * copy[i-1][j+1].rgbtBlue;
            }

            if (i < height - 1  && j < width - 1)
            {
                rGx += 1 * copy[i+1][j+1].rgbtRed;
                gGx += 1 * copy[i+1][j+1].rgbtGreen;
                bGx += 1 * copy[i+1][j+1].rgbtBlue;
                rGy += 1 * copy[i+1][j+1].rgbtRed;
                gGy += 1 * copy[i+1][j+1].rgbtGreen;
                bGy += 1 * copy[i+1][j+1].rgbtBlue;
            }


            if (i < height - 1  && j > 0)
            {
                rGx += -1 * copy[i+1][j-1].rgbtRed;
                gGx += -1 * copy[i+1][j-1].rgbtGreen;
                bGx += -1 * copy[i+1][j-1].rgbtBlue;
                rGy += 1 * copy[i+1][j-1].rgbtRed;
                gGy += 1 * copy[i+1][j-1].rgbtGreen;
                bGy += 1 * copy[i+1][j-1].rgbtBlue;
            }


            image[i][j].rgbtRed = (int) bound(sqrt((rGx*rGx)+(rGy*rGy)));
            image[i][j].rgbtGreen = (int) bound(sqrt((gGx*gGx)+(gGy*gGy)));
            image[i][j].rgbtBlue = (int) bound(sqrt((bGx*bGx)+(bGy*bGy)));
        }
    }


    return;
}



// Function for out of bound
int bound(double n)
{
    int result = 0;

    if (n >= 255)
    {
        result = 255;
    }
    else if(n < 0)
    {
        result = 0;
    }
    else
    {
        result = (int) round(n);
    }
    return (result);
}