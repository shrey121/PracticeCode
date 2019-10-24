package Steganography;

import java.awt.image.BufferedImage;
import java.util.Random;

/**
 * This class embeds the given message in the given image.
 *
 * @author Shreyansh, Afsha, Noreen
 */

public class putMessageLSB {
    /**
     * This method embeds message
     *
     * @return image with embeded message
     */

    static int startPuttingMessage(BufferedImage img, char[] msg, boolean edgeMatrix[][], long seed) {
        int maxX = img.getWidth(), maxY = img.getHeight(), y = 0, x = 0, index = 0;
        int rgb, red, green, blue, totalPixels = 0, edgePixel = 0;

        Random key = new Random(seed);

        for (y = 0; y < maxY; y++)
            for (x = 0; x < maxX; x++)
                if (edgeMatrix[y][x]) edgePixel++;

        totalPixels = edgePixel;

        System.out.println("TOTAL EDGEPIXELS : " + edgePixel);

        y = 0;
        x = -1;
        while (index < msg.length && edgePixel > 0) {
            if (index >= 21) {
                x = Math.abs(key.nextInt() % maxX);
                y = Math.abs(key.nextInt() % maxY);
            } else {
                System.out.println("index : " + index);
                if (++x == maxX) {
                    x = 0;
                    if (++y == maxY) break;
                }
            }
            System.out.println("x : " + x + "  y : " + y);
            if (edgeMatrix[y][x]) {
                //System.out.println("EDGEPIXELS  !!"+edgePixel);
                if (index < msg.length) {
                    System.out.println("Embedding value " + msg[index] + " in pixel(" + y + "," + x
                            + ")");
                    red = Utility.getRed7Bit(img, x, y);
                    if (msg[index] == '1') red = red | 0b00000000_00000000_00000000_00000001;
                    index++;
                    rgb = Utility.calculateRGB(Utility.getAlpha(img, x, y), red,
                            Utility.getGreen(img, x, y), Utility.getBlue(img, x, y));
                    img.setRGB(x, y, rgb);
                }
                if (index < msg.length) {
                    System.out.println("Embedding value " + msg[index] + " in pixel(" + y + "," + x
                            + ")");
                    green = Utility.getGreen7Bit(img, x, y);
                    if (msg[index] == '1') green = green | 0b00000000_00000000_00000000_00000001;
                    index++;
                    rgb = Utility.calculateRGB(Utility.getAlpha(img, x, y), Utility.getRed(img, x,
                            y), green, Utility.getBlue(img, x, y));
                    img.setRGB(x, y, rgb);
                }
                if (index < msg.length) {
                    System.out.println("Embedding value " + msg[index] + " in pixel(" + y + "," + x
                            + ")");
                    blue = Utility.getBlue7Bit(img, x, y);
                    if (msg[index] == '1') blue = blue | 0b00000000_00000000_00000000_00000001;
                    index++;
                    rgb = Utility.calculateRGB(Utility.getAlpha(img, x, y), Utility.getRed(img, x,
                            y), Utility.getGreen(img, x, y), blue);
                    img.setRGB(x, y, rgb);
                }
                edgePixel--;
                edgeMatrix[y][x] = false;
            }
        }

        if ((edgePixel == 0 && index < msg.length))

        {
            System.out.println("ERROR !! \nMessage is too big for the image.");
            totalPixels = -1;
        } else {
            totalPixels -= edgePixel;
            System.out.println("Message embedded Successfully, edgepixels used : " + totalPixels);
        }

        //System.out.println("BYE  !!");
        return totalPixels;
    }
}