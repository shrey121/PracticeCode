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
 * @author Shreyansh, Afsha
 */

public class getGUI extends JFrame implements ActionListener
{
	private static final long serialVersionUID = 1L;
	JButton open = new JButton("Open"), get = new JButton("Get"), reset = new JButton("Reset"), back = new JButton("Back");
	JTextArea message = new JTextArea(10,3);
	BufferedImage image = null;
	JScrollPane imagePane = new JScrollPane();
	 
	public getGUI() 
	{
		super("Get stegonographic message from image");
	    createInterface();
	    this.setDefaultCloseOperation(EXIT_ON_CLOSE);   
	    this.setBounds(GraphicsEnvironment.getLocalGraphicsEnvironment().getMaximumWindowBounds());
	    this.setVisible(true);
	}
	
	/**
	 * used to create the interface
	 */
	 	
	void createInterface() 
	{
		JPanel p = new JPanel(new FlowLayout());
		p.add(open);
	    p.add(get);
	    p.add(reset);
	    p.add(back);
	    this.getContentPane().add(p, BorderLayout.NORTH);
	    open.addActionListener(this);
	    get.addActionListener(this);
	    reset.addActionListener(this);
	    back.addActionListener(this);
	    p = new JPanel(new GridLayout(1,1));
	    p.add(new JScrollPane(message));
	    message.setFont(new Font("Arial",Font.BOLD,20));
	    p.setBorder(BorderFactory.createTitledBorder("Get message"));
	    message.setEditable(false);
	    this.getContentPane().add(p, BorderLayout.SOUTH);
	    imagePane.setBorder(BorderFactory.createTitledBorder("Steganographed Image"));
	    this.getContentPane().add(imagePane, BorderLayout.CENTER);
	}
	 
	public void actionPerformed(ActionEvent ae) 
	{
	    Object o = ae.getSource();
	    if(o == open)
	    {
	    	openImage();
	    }
	    else if(o == get)
	    {
	    	getMessage();
	    }
	    else if(o == reset) 
	    {
	    	resetInterface();
	    }
		else if(o == back) 
		{
			setVisible(false);
			dispose();
			new Start();
		}
	}
	
	/**
	 * Used to open image selected by the user.
	 */
	 
	void openImage() 
	{
	    File f = showFileDialog(true);
	    try 
	    {
			image = ImageIO.read(f);
	    	JLabel l = new JLabel(new ImageIcon(image));
	    	imagePane.getViewport().add(l);
	    	this.validate();
		} 
	    catch (IOException e) 
	    {
			e.printStackTrace();
		}	    
	}
	
	/**
	 * Selects the image file from the device. 
	 * @param open true for opening file
	 * @return selected file
	 */
	 
	File showFileDialog(boolean open) 
	{
		JFileChooser fc = new JFileChooser("Open an image");
	    FileFilter ff = new FileFilter() 
	    {
	    	public boolean accept(File f) 
	    	{
	    		String name = f.getName().toLowerCase();
	    		return f.isDirectory() ||   name.endsWith(".png") || name.endsWith(".bmp") || name.endsWith(".jpg");
	        }
	    	public String getDescription() 
	    	{
	          return "Image (*.png, *.bmp, *.jpg)";
	        }
	    };
	    fc.setAcceptAllFileFilterUsed(false);
	    fc.addChoosableFileFilter(ff);
	    
	    File f = null;
	    if(open && fc.showOpenDialog(this) == JFileChooser.APPROVE_OPTION)
	    {
	    	f = fc.getSelectedFile();
	    }
	    else if(!open && fc.showSaveDialog(this) == JFileChooser.APPROVE_OPTION)
	    {
	    	f = fc.getSelectedFile();
	    }
	    return f;
	}
	 
	/**
	 * Extracts the written message from the image.
	 */
	
	void getMessage() 
	{
		if(image == null) 
		{
			JOptionPane.showMessageDialog(this, "No photo has been selected!", "Nothing to get", JOptionPane.ERROR_MESSAGE);
			return;
		}
		BufferedImage img = image.getSubimage(0,0,image.getWidth(),image.getHeight());
		getMessage gMsg = new getMessage(img);
		char msg[] = gMsg.startGettingZigZag();
		String str = HammingCode.decrypt(msg);
		System.out.println(str);
		message.setText(str); 
	}
	
	/**
	 * Clears everything from the frame.
	 */
	
	void resetInterface() 
	{
	    message.setText("");
	    imagePane.getViewport().removeAll();
	    image = null;
	    this.validate();
	}
}