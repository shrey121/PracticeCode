package Steganography;

import java.awt.image.BufferedImage;
import java.util.Random;

/**
 * this class is used to extract the message embedded in the image
 *
 * @author Shreyansh, Afsha, Noreen
 */

public class getMessageLSB {
    BufferedImage img;
    boolean edgeMatrix[][];
    char[] binary = new char[16];
    Random key;

    public getMessageLSB(BufferedImage tempimg, boolean Matrix[][]) {
        edgeMatrix = Matrix;
        img = tempimg;
    }

    /**
     * extracts the message bits which were embedded in zig zag pattern
     *
     * @return extracted message bits
     */

    char[] startGettingMessage() {
        char[] tempBinary = new char[16];
        char[] frame = new char[21];
        int maxX = img.getWidth(), maxY = img.getHeight(), y = 0, x = 0, length = 0, i, j, mi = 0,
                fi = 0, bi = 0;
        int numberOfBitsExtracted, plane = 1;

        while (fi < 21) {
            //System.out.println("pheromone = "+pheromoneMatrix[y][x]+"at "+x+","+y);

            if (edgeMatrix[y][x]) {
                numberOfBitsExtracted = getvalue(x, y, plane);
                for (bi = 0; bi < (16 - numberOfBitsExtracted); bi++) ;
                for (; bi < 16 && fi < 21; bi++, fi++) {
                    frame[fi] = binary[bi];
                }
                plane++;

                if (plane == 4 && bi == 16) {
                    plane = 1;
                    x++;
                    if (x == maxX) {
                        x = 1;
                        y++;
                    }
                    if (y == maxY) {
                        break;
                    }
                }
            }

            while (edgeMatrix[y][x] == false) {
                x++;
                if (x == maxX) {
                    x = 1;
                    y++;
                }
                if (y == maxY) {
                    break;
                }
            }
        }

        frame = HammingCode.check(frame);
        String str = new String(frame);
        System.out.println("Length frame: " + str);

        //performing shift operation
        for (i = 0, j = -1; i < 21; i++) {
            if (i == 0 || i == 1 || i == 3 || i == 7 || i == 15) {
                continue;
            } else {
                tempBinary[++j] = frame[i];
            }
        }

        //calculating the decimal value of each character
        for (i = 15, j = 0; i >= 0; i--, j++) {
            if (tempBinary[i] == '1') {
                length += (int) Math.pow(2, j);
            }
        }

        System.out.println("Length: " + length);

        key = new Random(length);

        char[] msg = new char[length * 21];

        if (bi != 16) {
            for (; bi < 16 && mi < msg.length; bi++, mi++) {
                msg[mi] = binary[bi];
            }
        }

        x = Math.abs(key.nextInt() % maxX);
        y = Math.abs(key.nextInt() % maxY);

        while (mi < msg.length) {
            //System.out.println("pheromone = "+pheromoneMatrix[y][x]+"at "+x+","+y);

            if (edgeMatrix[y][x]) {
                numberOfBitsExtracted = getvalue(x, y, plane);
                for (bi = 0; bi < (16 - numberOfBitsExtracted); bi++) ;
                for (; bi < 16 && mi < msg.length; bi++, mi++) {
                    msg[mi] = binary[bi];
                }
                plane++;

                if (plane == 4 && bi == 16) {
                    plane = 1;
                    edgeMatrix[y][x] = false;
                    x = Math.abs(key.nextInt() % maxX);
                    y = Math.abs(key.nextInt() % maxY);
                }
            } else {
                x = Math.abs(key.nextInt() % maxX);
                y = Math.abs(key.nextInt() % maxY);
            }
        }
        return msg;
    }

    /**
     * extracts message bits from the given pixel.
     *
     * @param x x coordinate of pixel
     * @param y y coordinate of pixel
     * @return number of bits extracted
     */

    private int getvalue(int x, int y, int plane) {
        int nBitDecimalValue = 0;
        if (plane == 1) nBitDecimalValue = Utility.getRed(img, x, y);
        if (plane == 2) nBitDecimalValue = Utility.getGreen(img, x, y);
        if (plane == 3) nBitDecimalValue = Utility.getBlue(img, x, y);

        nBitDecimalValue = nBitDecimalValue & 0b00000000_00000000_00000000_00000001;
        System.out.println(nBitDecimalValue + " value extracted from pixel(" + y + "," + x + ")");
        binary = Utility.convertBinary(nBitDecimalValue);
        return 1;
    }
}
