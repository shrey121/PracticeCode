package Steganography;	

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 * This class asks user to embed message or get message from image.
 * @author Shreyansh, Afsha
 */

public class Start extends JFrame implements ActionListener
{
	private static final long serialVersionUID = 1L;
	JButton put = new JButton("Put Message"), get = new JButton("Get Message");
	
	public static void main(String[] args) 
	{
		new Start();
	}
	
	Start()
	{
		super("Select Option");
		JPanel p = new JPanel(new FlowLayout());
		p.add(put);
		p.add(get);
		this.getContentPane().add(p, BorderLayout.CENTER);
		put.addActionListener(this);
		get.addActionListener(this);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setBounds(200, 200, 400, 100);
		this.setVisible(true);
		this.validate();
	}
	
	public void actionPerformed(ActionEvent ae) 
	{
		Object obj = ae.getSource();
		if(obj == put)
		{	
			setVisible(false);
			dispose();
			new putGUI();
		}
		else if(obj == get)
		{
			setVisible(false);
			dispose();
			new getGUI();
		}
	}
}