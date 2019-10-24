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
import javax.swing.JTextArea;
import javax.swing.filechooser.FileFilter;

/**
 * This class creates GUI for the embedding message in the image.
 * @author Shreyansh, Afsha
 */
 
public class putGUI extends JFrame implements ActionListener
{
	private static final long serialVersionUID = 1L;
	JButton open = new JButton("Open"), put = new JButton("Put"), save = new JButton("Save"), reset = new JButton("Reset"), back = new JButton("Back");
	JTextArea message = new JTextArea(10,3);
	BufferedImage sourceImage = null, finalImage = null;
	JSplitPane splitPane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT);
	JScrollPane originalPane = new JScrollPane(), finalPane = new JScrollPane();

	public putGUI() 
	{	
		super("Put message in image");
		createInterface();
		message.setText("");
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);   
		this.setBounds(GraphicsEnvironment.getLocalGraphicsEnvironment().getMaximumWindowBounds());
		this.setVisible(true);
		splitPane.setDividerLocation(0.5);
		this.validate();
    }
	
	/**
	 * used to create the interface
	 */
 
	void createInterface() 
	{
		JPanel p = new JPanel(new FlowLayout());
		p.add(open);
		p.add(put);
		p.add(save);   
		p.add(reset);   
		p.add(back);
		this.getContentPane().add(p, BorderLayout.SOUTH);
		open.addActionListener(this);
		put.addActionListener(this);
		save.addActionListener(this);   
		reset.addActionListener(this);
		back.addActionListener(this);
		p = new JPanel(new GridLayout(1,1));
		p.add(new JScrollPane(message));
		message.setFont(new Font("Arial", Font.BOLD, 20));
		p.setBorder(BorderFactory.createTitledBorder("Write your message here"));
		this.getContentPane().add(p, BorderLayout.NORTH);
		splitPane.setLeftComponent(originalPane);
		splitPane.setRightComponent(finalPane);
		originalPane.setBorder(BorderFactory.createTitledBorder("Original Image"));
		finalPane.setBorder(BorderFactory.createTitledBorder("Steganographed Image"));
		this.getContentPane().add(splitPane, BorderLayout.CENTER);
    }
 
	public void actionPerformed(ActionEvent ae) 
	{
		Object obj = ae.getSource();
		if(obj == open)
		{
			openImage();
		}
		else if(obj == put)
		{
			putMessage();
		}
		else if(obj == save) 
		{
			saveImage();
		}
		else if(obj == reset) 
		{
			resetInterface();
		}
		else if(obj == back) 
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
		File f = selectFile(true);
		try 
		{   
			sourceImage = ImageIO.read(f);
			JLabel l = new JLabel(new ImageIcon(sourceImage));
			originalPane.getViewport().add(l);
			this.validate();
		} 
		catch(Exception e) 
		{ 
			e.printStackTrace(); 
		}
    }
	
	/**
	 * Selects the image file and also checks for its correctness. 
	 * @param open true for opening file and false for saving file
	 * @return selected file
	 */
	
	File selectFile(final boolean open) 	//open=true for opening file, open=false for saving file
	{
		JFileChooser chooseFile = new JFileChooser("Open an image");
		FileFilter filterFile = new FileFilter() 
		{
			public boolean accept(File f) 
			{
				String name = f.getName().toLowerCase();
				if(open)
				{
					return f.isDirectory() || name.endsWith(".jpg") || name.endsWith(".jpeg") || name.endsWith(".png") || 
							name.endsWith(".gif") || name.endsWith(".tiff") || name.endsWith(".bmp");
				}
				return f.isDirectory() || name.endsWith(".png") ||    name.endsWith(".jpg");
			}
			public String getDescription() 
			{
				if(open)
				{
					return "Image (*.jpg, *.jpeg, *.png, *.gif, *.tiff, *.bmp)";
				}
				return "Image (*.png, *.jpg)";
			}
		};
		chooseFile.setAcceptAllFileFilterUsed(false);
		chooseFile.addChoosableFileFilter(filterFile);
 
		File f = null;
		if(open && chooseFile.showOpenDialog(this) == JFileChooser.APPROVE_OPTION)
		{
			f = chooseFile.getSelectedFile();
		}
		else if(!open && chooseFile.showSaveDialog(this) == JFileChooser.APPROVE_OPTION)
		{
			f = chooseFile.getSelectedFile();
		}
		return f;
    }
	
	/**
	 * Embeds the written message in the image.
	 */
 
	void putMessage() 
	{
		String msg = message.getText();
		
		if(msg.equals("")) 
		{
			JOptionPane.showMessageDialog(this, "No message has been written!\nWrite a message!!", "Nothing to put", JOptionPane.ERROR_MESSAGE);
			return;
		}
		
		if(sourceImage == null) 
		{
			JOptionPane.showMessageDialog(this, "No photo has been selected!\nSelect a photo!!", "Nothing to save", JOptionPane.ERROR_MESSAGE);
			return;
		}
		
		finalImage = sourceImage.getSubimage(0,0,sourceImage.getWidth(),sourceImage.getHeight());
		
		double bytes = msg.length();
		bytes = bytes*21+21;
		bytes = bytes/8;
		
		JOptionPane.showMessageDialog(this, "Number of bytes to be inserted in picture is "+bytes, "Number of bytes", JOptionPane.INFORMATION_MESSAGE);
		
		long key = msg.length();
		char messageBits[] = HammingCode.encrypt(msg);
		/*
		if(messageBits.length > (finalImage.getWidth() * finalImage.getHeight())) 
        {
        	JOptionPane.showMessageDialog(this, "Message is too long for the chosen image", "Message too long!", JOptionPane.ERROR_MESSAGE);
        	return;
        }
        this error will be generated while inserting message
		*/
		putMessage pMsg = new putMessage(finalImage, messageBits, key);
		finalImage = pMsg.startPuttingZigZag();
		JLabel l = new JLabel(new ImageIcon(finalImage));
		finalPane.getViewport().add(l);
		this.validate();
    }
	
	/**
	 * Save the image in device.
	 */
	
	void saveImage() 
	{
		if(finalImage == null) 
		{
			JOptionPane.showMessageDialog(this, "No message has been secretly hidden!", "Nothing to save", JOptionPane.ERROR_MESSAGE);
			return;
		}
		
		String msg = message.getText();
		if(msg.equals("")) 
		{
			JOptionPane.showMessageDialog(this, "No message has been written!\nWrite a message!!", "Nothing to save", JOptionPane.ERROR_MESSAGE);
			return;
		}
		
		File f = selectFile(false);
		String name = f.getName();
		String ext = name.substring(name.lastIndexOf(".")+1).toLowerCase();
		if(!ext.equals("png") && !ext.equals("jpg")) 
		{
			ext = "png";
			f = new File(f.getAbsolutePath()+".png");
        }
		try 
		{
			if(f.exists()) 
			{
				f.delete();
			}
			ImageIO.write(finalImage, ext.toUpperCase(), f);
		} 
		catch(Exception ex) 
		{ 
			ex.printStackTrace(); 
		}
	}
	
	/**
	 * Clears everything from the frame.
	 */
 
	void resetInterface() 
	{
		message.setText("");
		originalPane.getViewport().removeAll();
		finalPane.getViewport().removeAll();
		sourceImage = null;
		finalImage = null;
		splitPane.setDividerLocation(0.5);
		this.validate();
    }
}