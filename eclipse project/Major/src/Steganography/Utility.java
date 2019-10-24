package Steganography;

import java.awt.Graphics;
import java.awt.image.BufferedImage;

/**
 * This class have basic functions which are used across classes.
 *
 * @author Shreyansh, Afsha, Noreen
 */

public class Utility {

    /**
     * this method calculates the maximum of 3 values
     *
     * @param a
     * @param b
     * @param c
     * @return maximum value
     */

    static int max(int a, int b, int c) {
        int max = Integer.MIN_VALUE;
        if (a > max) {
            max = a;
        }
        if (b > max) {
            max = b;
        }
        if (c > max) {
            max = c;
        }
        return max;
    }

    /**
     * this method calculated the minimum of 3 values
     *
     * @param a
     * @param b
     * @param c
     * @return minimum value
     */

    static int min(int a, int b, int c) {
        int min = Integer.MAX_VALUE;
        if (a < min) {
            min = a;
        }
        if (b < min) {
            min = b;
        }
        if (c < min) {
            min = c;
        }
        return min;
    }

    /**
     * this method converts the data in binary array
     *
     * @param data
     * @return binary frame
     */

    static char[] convertBinary(int data) {
        int i, j;    //using even parity
        char temp;
        char binary[] = new char[16];

        System.out.println("From convertBinary: " + data);

        for (i = 0; i < 16; i++)    //filling array with 0's
        {
            binary[i] = '0';
        }

        for (i = 0; data != 1 && i < 15; i++)    //calculating binary
        {
            j = (data % 2) + 48;
            binary[i] = (char) j;
            data = data / 2;
        }

        binary[i] = '1';

        for (i = 0, j = 15; i < 8; i++, j--)    //swapping array
        {
            temp = binary[j];
            binary[j] = binary[i];
            binary[i] = temp;
        }

        String str = new String(binary);
        System.out.println("binary: " + str);
        return binary;
    }

    /**
     * This method converts color image to grayscale.
     *
     * @param color image
     * @return gray image
     */

    static BufferedImage convertToGray(BufferedImage img) {
        int red, green, blue, gray, newPixel, height, width;

        height = img.getHeight();
        width = img.getWidth();

        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                red = getRed7Bit(img, i, j);
                green = getGreen7Bit(img, i, j);
                blue = getBlue7Bit(img, i, j);
                gray = (int) (0.299 * red + 0.587 * green + 0.114 * blue);
                newPixel = calculateRGB(getAlpha(img, i, j), gray, gray, gray);
                img.setRGB(i, j, newPixel);
            }
        }
        return img;
    }

    /**
     * This method calculates the value of RGB
     *
     * @param alpha
     * @param red
     * @param green
     * @param blue
     * @return RGB value
     */

    static int calculateRGB(int alpha, int red, int green, int blue) {
        int RGB = 0;
        RGB += alpha;
        RGB <<= 8;
        RGB += red;
        RGB <<= 8;
        RGB += green;
        RGB <<= 8;
        RGB += blue;
        return RGB;
    }

    static int getAlpha(BufferedImage img, int x, int y) {
        int rgb = img.getRGB(x, y);
        int color = (rgb >> 24) & 0x000000FF;
        return color;
    }

    static int getRed(BufferedImage img, int x, int y) {
        int rgb = img.getRGB(x, y);
        int color = (rgb >> 16) & 0x000000FF;
        return color;
    }

    static int getGreen(BufferedImage img, int x, int y) {
        int rgb = img.getRGB(x, y);
        int color = (rgb >> 8) & 0x000000FF;
        return color;
    }

    static int getBlue(BufferedImage img, int x, int y) {
        int rgb = img.getRGB(x, y);
        int color = rgb & 0x000000FF;
        return color;
    }

    static int getRed7Bit(BufferedImage img, int x, int y) {
        int rgb = img.getRGB(x, y);
        int color = (rgb >> 16) & 0x000000FF;
        color = color & 0b11111111_11111111_11111111_11111110;
        return color;
    }

    static int getGreen7Bit(BufferedImage img, int x, int y) {
        int rgb = img.getRGB(x, y);
        int color = (rgb >> 8) & 0x000000FF;
        color = color & 0b11111111_11111111_11111111_11111110;
        return color;
    }

    static int getBlue7Bit(BufferedImage img, int x, int y) {
        int rgb = img.getRGB(x, y);
        int color = rgb & 0x000000FF;
        color = color & 0b11111111_11111111_11111111_11111110;
        return color;
    }

    static BufferedImage copyImage(BufferedImage sourceImage) {
        BufferedImage newImage = new BufferedImage(sourceImage.getWidth(), sourceImage.getHeight(), sourceImage.getType());
        Graphics g = newImage.getGraphics();
        g.drawImage(sourceImage, 0, 0, null);
        g.dispose();
        return newImage;
    }
}
