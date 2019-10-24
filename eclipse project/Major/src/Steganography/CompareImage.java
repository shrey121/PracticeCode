package Steganography;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.GraphicsEnvironment;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.File;

import javax.imageio.ImageIO;
import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSplitPane;
import javax.swing.filechooser.FileFilter;

public class CompareImage extends JFrame implements ActionListener {
    private static final long serialVersionUID = 1L;
    JButton open1 = new JButton("Open 1st Image"), open2 = new JButton("Open 2nd Image"),
            compare = new JButton("Compare"), save = new JButton("Save"),
            reset = new JButton("Reset");
    BufferedImage sourceImage = null, differentPixelsImage = null, finalImage = null;
    JSplitPane splitPane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT);
    JScrollPane originalPane = new JScrollPane(), finalPane = new JScrollPane();
    boolean flag1 = false, flag2 = false;

    public static void main(String[] args) {
        new CompareImage();
    }

    CompareImage() {
        super("Compare images");
        createInterface();
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setBounds(GraphicsEnvironment.getLocalGraphicsEnvironment().getMaximumWindowBounds());
        this.setVisible(true);
        splitPane.setDividerLocation(0.5);
        this.validate();
    }


    /**
     * used to create the interface
     */

    void createInterface() {
        JPanel p = new JPanel(new FlowLayout());
        p.add(open1);
        p.add(open2);
        p.add(compare);
        p.add(save);
        p.add(reset);
        this.getContentPane().add(p, BorderLayout.SOUTH);
        open1.addActionListener(this);
        open2.addActionListener(this);
        compare.addActionListener(this);
        compare.setEnabled(false);
        save.addActionListener(this);
        reset.addActionListener(this);
        splitPane.setLeftComponent(originalPane);
        splitPane.setRightComponent(finalPane);
        originalPane.setBorder(BorderFactory.createTitledBorder("First Image"));
        finalPane.setBorder(BorderFactory.createTitledBorder("Second Image"));
        this.getContentPane().add(splitPane, BorderLayout.CENTER);
    }

    public void actionPerformed(ActionEvent ae) {
        Object obj = ae.getSource();
        if (obj == open1) {
            openFirstImage();
            flag1 = true;
            if (flag2 == true) {
                compare.setEnabled(true);
            }
        } else if (obj == open2) {
            openSecondImage();
            flag2 = true;
            if (flag1 == true) {
                compare.setEnabled(true);
            }
        } else if (obj == compare) {
            compareImages();
            JFrame frame = new JFrame("Difference Detected");
            frame.setSize(600, 600);
            ImageIcon ic = new ImageIcon(differentPixelsImage);
            JLabel imageLabel = new JLabel(ic);
            frame.add(imageLabel);
            frame.setVisible(true);
        } else if (obj == save) {
            saveImage();
        } else if (obj == reset) {
            resetInterface();
        }
    }

    /**
     * Used to open image selected by the user.
     */

    void openFirstImage() {
        File f = selectFile(true);
        try {
            sourceImage = ImageIO.read(f);
            JLabel l = new JLabel(new ImageIcon(sourceImage));
            originalPane.getViewport().add(l);
            this.validate();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * Used to open image selected by the user.
     */

    void openSecondImage() {
        File f = selectFile(true);
        try {
            finalImage = ImageIO.read(f);
            JLabel l = new JLabel(new ImageIcon(finalImage));
            finalPane.getViewport().add(l);
            this.validate();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * Selects the image file and also checks for its correctness.
     *
     * @param open true for opening file and false for saving file
     * @return selected file
     */

    File selectFile(final boolean open)    //open=true for opening file, open=false for saving file
    {
        JFileChooser chooseFile = new JFileChooser("Open an image");
        FileFilter filterFile = new FileFilter() {
            public boolean accept(File f) {
                String name = f.getName().toLowerCase();
                if (open) {
                    return f.isDirectory() || name.endsWith(".jpg") || name.endsWith(".jpeg") ||
                            name.endsWith(".png") || name.endsWith(".gif") ||
                            name.endsWith(".tiff") || name.endsWith(".bmp");
                }
                return f.isDirectory() || name.endsWith(".png") || name.endsWith(".jpg");
            }

            public String getDescription() {
                if (open) {
                    return "Image (*.jpg, *.jpeg, *.png, *.gif, *.tiff, *.bmp)";
                }
                return "Image (*.png, *.jpg)";
            }
        };
        chooseFile.setAcceptAllFileFilterUsed(false);
        chooseFile.addChoosableFileFilter(filterFile);

        File f = null;
        if (open && chooseFile.showOpenDialog(this) == JFileChooser.APPROVE_OPTION) {
            f = chooseFile.getSelectedFile();
        } else if (!open && chooseFile.showSaveDialog(this) == JFileChooser.APPROVE_OPTION) {
            f = chooseFile.getSelectedFile();
        }
        return f;
    }

    /**
     * Save the image in device.
     */

    void saveImage() {
        File f = selectFile(false);
        String name = f.getName();
        String ext = name.substring(name.lastIndexOf(".") + 1).toLowerCase();
        if (!ext.equals("png") && !ext.equals("jpg")) {
            ext = "png";
            f = new File(f.getAbsolutePath() + ".png");
        }
        try {
            if (f.exists()) {
                f.delete();
            }
            ImageIO.write(differentPixelsImage, ext.toUpperCase(), f);
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    /**
     * Clears everything from the frame.
     */

    void resetInterface() {
        originalPane.getViewport().removeAll();
        finalPane.getViewport().removeAll();
        sourceImage = null;
        finalImage = null;
        splitPane.setDividerLocation(0.5);
        this.validate();
    }

    void compareImages() {
        if ((sourceImage.getHeight() == finalImage.getHeight()) &&
                (sourceImage.getWidth() == finalImage.getWidth())) {
            int h = sourceImage.getHeight();
            int w = sourceImage.getWidth();
            differentPixelsImage = Utility.copyImage(sourceImage);
            int alpha, newPixel, counter = 0;

            for (int i = 0; i < w; i++) {
                for (int j = 0; j < h; j++) {
                    if (sourceImage.getRGB(i, j) != finalImage.getRGB(i, j)) {
                        alpha = Utility.getAlpha(sourceImage, i, j);
                        newPixel = Utility.calculateRGB(alpha, 0, 0, 0);
                        differentPixelsImage.setRGB(i, j, newPixel);
                        System.out.println("Pixel not matched at (" + i + "," + j + ")");
                        counter++;
                    } else {
                        alpha = Utility.getAlpha(sourceImage, i, j);
                        newPixel = Utility.calculateRGB(alpha, 255, 255, 255);
                        differentPixelsImage.setRGB(i, j, newPixel);
                    }
                }
            }
            System.out.println("Total " + counter + " differences detected !!");
        } else {
            JOptionPane.showMessageDialog(this, "Size doesn't match", "Can't compare!!",
                    JOptionPane.ERROR_MESSAGE);
        }
    }
}
