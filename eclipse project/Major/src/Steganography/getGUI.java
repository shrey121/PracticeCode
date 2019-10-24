package Steganography;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GraphicsEnvironment;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

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
import javax.swing.JTextArea;
import javax.swing.filechooser.FileFilter;

/**
 * This class creates GUI for the extracting message from the image.
 *
 * @author Shreyansh, Afsha, Noreen
 */

public class getGUI extends JFrame implements ActionListener {
    private static final long serialVersionUID = 1L;
    JButton open = new JButton("Open"), get = new JButton("Get"), showB$W = new JButton("Show B&W"),
            showEdge = new JButton("Show Edge"), reset = new JButton("Reset"),
            back = new JButton("Back");
    JTextArea message = new JTextArea(10, 3);
    BufferedImage sourceImage = null, edgeImage = null, black$whiteImage = null;
    JScrollPane imagePane = new JScrollPane();

    public getGUI() {
        super("Get stegonographic message from image");
        createInterface();
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setBounds(GraphicsEnvironment.getLocalGraphicsEnvironment().getMaximumWindowBounds());
        this.setVisible(true);
    }

    /**
     * used to create the interface
     */

    void createInterface() {
        JPanel p = new JPanel(new FlowLayout());
        p.add(open);
        p.add(get);
        p.add(showB$W);
        p.add(showEdge);
        p.add(reset);
        p.add(back);
        this.getContentPane().add(p, BorderLayout.NORTH);
        open.addActionListener(this);
        get.addActionListener(this);
        showB$W.addActionListener(this);
        showB$W.setEnabled(false);
        showEdge.addActionListener(this);
        showEdge.setEnabled(false);
        reset.addActionListener(this);
        back.addActionListener(this);
        p = new JPanel(new GridLayout(1, 1));
        p.add(new JScrollPane(message));
        message.setFont(new Font("Arial", Font.BOLD, 20));
        p.setBorder(BorderFactory.createTitledBorder("Get message"));
        message.setEditable(false);
        this.getContentPane().add(p, BorderLayout.SOUTH);
        imagePane.setBorder(BorderFactory.createTitledBorder("Steganographed Image"));
        this.getContentPane().add(imagePane, BorderLayout.CENTER);
    }

    public void actionPerformed(ActionEvent ae) {
        Object o = ae.getSource();
        if (o == open) {
            openImage();
        } else if (o == get) {
            getMessageLSB();
        } else if (o == showB$W) {
            JFrame frame = new JFrame("Black & White Image");
            frame.setSize(600, 600);
            ImageIcon ic = new ImageIcon(black$whiteImage);
            JLabel imageLabel = new JLabel(ic);
            frame.add(imageLabel);
            frame.setVisible(true);
        } else if (o == showEdge) {
            JFrame frame = new JFrame("Edges Detected");
            frame.setSize(600, 600);
            ImageIcon ic = new ImageIcon(edgeImage);
            JLabel imageLabel = new JLabel(ic);
            frame.add(imageLabel);
            frame.setVisible(true);
            //saveEdgeImage();
        } else if (o == reset) {
            resetInterface();
        } else if (o == back) {
            setVisible(false);
            dispose();
            new Start();
        }
    }

    /**
     * Used to open image selected by the user.
     */

    void openImage() {
        File f = showFileDialog(true);
        try {
            sourceImage = ImageIO.read(f);
            JLabel l = new JLabel(new ImageIcon(sourceImage));
            imagePane.getViewport().add(l);
            this.validate();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /**
     * Selects the image file from the device.
     *
     * @param open true for opening file
     * @return selected file
     */

    File showFileDialog(boolean open) {
        JFileChooser fc = new JFileChooser("Open an image");
        FileFilter ff = new FileFilter() {
            public boolean accept(File f) {
                String name = f.getName().toLowerCase();
                return f.isDirectory() || name.endsWith(".png") || name.endsWith(".bmp") ||
                        name.endsWith(".jpg");
            }

            public String getDescription() {
                return "Image (*.png, *.bmp, *.jpg)";
            }
        };
        fc.setAcceptAllFileFilterUsed(false);
        fc.addChoosableFileFilter(ff);

        File f = null;
        if (open && fc.showOpenDialog(this) == JFileChooser.APPROVE_OPTION) {
            f = fc.getSelectedFile();
        } else if (!open && fc.showSaveDialog(this) == JFileChooser.APPROVE_OPTION) {
            f = fc.getSelectedFile();
        }
        return f;
    }

    void getMessageLSB() {
        boolean edgeMatrix[][];
        if (sourceImage == null) {
            JOptionPane.showMessageDialog(this, "No photo has been selected!", "Nothing to get",
                    JOptionPane.ERROR_MESSAGE);
            return;
        }
        black$whiteImage = Utility.copyImage(sourceImage);
        Utility.convertToGray(black$whiteImage);
        showB$W.setEnabled(true);
        edgeImage = Utility.copyImage(black$whiteImage);
        edgeMatrix = AntColony.getEdges(edgeImage);
        showEdge.setEnabled(true);
        getMessageLSB gMsg = new getMessageLSB(sourceImage, edgeMatrix);
        char msg[] = gMsg.startGettingMessage();
        String str = HammingCode.decrypt(msg);
        System.out.println(str);
        message.setText(str);
    }

    void saveEdgeImage() {
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
            ImageIO.write(edgeImage, ext.toUpperCase(), f);
        } catch (Exception ex) {
            ex.printStackTrace();
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
                            name.endsWith(".png") ||
                            name.endsWith(".gif") || name.endsWith(".tiff") || name.endsWith(".bmp");
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
     * Clears everything from the frame.
     */

    void resetInterface() {
        message.setText("");
        imagePane.getViewport().removeAll();
        sourceImage = null;
        this.validate();
    }
}