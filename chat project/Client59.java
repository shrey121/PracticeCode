import java.io.*;
import java.net.*;
import java.util.Timer;
import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Client59 extends TimerTask
{
	BufferedReader in;
    	PrintWriter out;
    	JFrame frame = new JFrame("Chat");
    	JTextField textField = new JTextField(50);
    	JTextArea messageArea = new JTextArea(12, 50);
    	int i=0;
    	Socket socket;
    	Date d;

    	public Client59()
	{
        	textField.setEditable(false);
        	messageArea.setEditable(false);
        	frame.getContentPane().add(textField, "South");
        	frame.getContentPane().add(new JScrollPane(messageArea), "Center");
		messageArea.setBackground(Color.green);
		textField.setBackground(Color.white);
        	frame.pack();

        	textField.addActionListener(new ActionListener() {
            		public void actionPerformed(ActionEvent e)
			{
				d=new Date();
				System.out.println(d.toString());
                		out.println(textField.getText());
                		textField.setText("");
            		}
        	});
    	}

       	public void run()
	{
		long i=0;
		Date d2=new Date();
		i=(long)(d2.getTime()-d.getTime());
		if((i/1000)>=60)
		{
			try
			{
				System.out.println("User is not doing any activity");
				System.out.println("Closing socket!!");
				socket.close();
			}
			catch(IOException e)
			{
				System.out.println("Client will now be closed");
			}
			System.exit(0);
		}
	}
    
	private String getServerAddress()
	{
	    	return JOptionPane.showInputDialog(frame,"Enter IP Address:","Welcome",JOptionPane.PLAIN_MESSAGE);
    	}

	private void attempt(int i)
	{
	    	JOptionPane.showMessageDialog(frame,"Wrong IP Re-enter ");
    	}

	private String getName()
	{
        	String s= JOptionPane.showInputDialog(frame,"Enter username:","Username",JOptionPane.PLAIN_MESSAGE);
		frame.setTitle(s);
		return s;
	}

	private void running(Client59 a) throws IOException
	{
		// Make connection and initialize streams
		try
		{
        		String serverAddress = getServerAddress();
        		socket = new Socket(serverAddress, 9001);
		}
		catch(Exception h)
		{
			i++;
			System.out.println("Wrong IP");
			System.out.println("Attempt Number: "+i);
			if(i>3)
			{
				System.out.println("User has made several attempts....");
				System.exit(0);
			}
			attempt(i);
			a.running(a);
		}			
        	in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        	out = new PrintWriter(socket.getOutputStream(), true);

		while(true)
		{
			try
			{
           			String line = in.readLine();	
            			if (line.startsWith("SUBMITNAME"))
				{
                			out.println(getName());
            			}
				else if (line.startsWith("NAMEACCEPTED"))
				{
					textField.setEditable(true);
            			} 
				else if (line.startsWith("MESSAGE"))
				{
                			messageArea.append(line.substring(8) + "\n");
            			}
			}
			catch(Exception e)
			{
				System.out.println("");
			}
    		}

	} 

    	public static void main(String[] args) throws Exception
	{
        	Timer timer = new Timer("Printer");
        	Client59 client = new Client59();
		client.d=new Date();
        	client.frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        	client.frame.setVisible(true);
		timer.schedule(client, 0, 20000);
        	client.running(client);
    	}
}