import java.net.*;
import java.io.*;

public class GreetingClient
{
   public static void main(String [] args)
   {
      	String str;
	//String serverName = args[0];
      //int port = Integer.parseInt(args[1]);
      try
      {
         //System.out.println("Connecting to " + serverName
                             //+ " on port " + port);
         Socket client = new Socket("192.168.0.49",6000);
        // System.out.println("Just connected to "
                     // + client.getRemoteSocketAddress());
         OutputStream outToServer = client.getOutputStream();
         DataOutputStream out =
                       new DataOutputStream(outToServer);

         out.writeUTF("Hello from "
                      + client.getLocalSocketAddress());
         InputStream inFromServer = client.getInputStream();
         DataInputStream in =
                        new DataInputStream(inFromServer);
         
	str=in.readUTF();
	System.out.println("Server says " + str);
         
	str="asdasd";
	out.writeUTF(str);


	//client.close();
      }catch(IOException e)
      {
         e.printStackTrace();
      }
   }
}
