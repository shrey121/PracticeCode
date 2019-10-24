import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GraphicsEnvironment;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSplitPane;
import javax.swing.JTextArea;


@SuppressWarnings("serial")
public class gui extends JFrame implements ActionListener 
{
	JButton open=new JButton("open");
	JButton embed=new JButton("embed");
	JButton save = new JButton("Save into new file");
	JButton reset = new JButton("Reset");
	
	JTextArea message = new JTextArea(10,3);
	BufferedImage sourceImage = null, embeddedImage = null;
	JSplitPane sp = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT);
	JScrollPane originalPane = new JScrollPane();
	JScrollPane embeddedPane = new JScrollPane();
	   	
	public gui() 
	{
	    super("Embed stegonographic message in image");
		    assembleInterface();
		 
		    this.setDefaultCloseOperation(EXIT_ON_CLOSE);   
		    this.setBounds(GraphicsEnvironment.getLocalGraphicsEnvironment().getMaximumWindowBounds());
		    this.setVisible(true);
		    sp.setDividerLocation(0.5);
		    this.validate();
		    }
	



	private void assembleInterface() {
	    JPanel p = new JPanel(new FlowLayout());
	    p.add(open);
	    p.add(embed);
	    p.add(save);   
	    p.add(reset);
	    this.getContentPane().add(p, BorderLayout.SOUTH);
	    open.addActionListener(this);
	    embed.addActionListener(this);
	    save.addActionListener(this);   
	    reset.addActionListener(this);
	    open.setMnemonic('O');
	    embed.setMnemonic('E');
	    save.setMnemonic('S');
	    reset.setMnemonic('R');
	    
	    p = new JPanel(new GridLayout(1,1));
	    p.add(new JScrollPane(message));
	    message.setFont(new Font("Arial",Font.BOLD,20));
	    p.setBorder(BorderFactory.createTitledBorder("Message to be embedded"));
	    this.getContentPane().add(p, BorderLayout.NORTH);
	    
	    sp.setLeftComponent(originalPane);
	    sp.setRightComponent(embeddedPane);
	    originalPane.setBorder(BorderFactory.createTitledBorder("Original Image"));
	    embeddedPane.setBorder(BorderFactory.createTitledBorder("Steganographed Image"));
	    this.getContentPane().add(sp, BorderLayout.CENTER);
	    }

public static void main(String arg[]) {
	    new gui();
	    }




@Override
public void actionPerformed(ActionEvent e) 
{
	// TODO Auto-generated method stub
	
}
}