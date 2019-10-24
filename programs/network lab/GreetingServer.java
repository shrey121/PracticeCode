import java.net.*;
import java.io.*;
//import java.system.*;

public class GreetingServer extends Thread
{
   private ServerSocket serverSocket;
   
   public GreetingServer(int port) throws IOException
   {
      serverSocket = new ServerSocket(port);
      serverSocket.setSoTimeout(100000000);
   }

   public void run()
   {
      while(true)
      {
         try
         {
               Socket server = serverSocket.accept();
             DataInputStream in = new DataInputStream(server.getInputStream());
   //         String s=in.readUTF();
//		System.out.println(s);
            DataOutputStream out = new DataOutputStream(server.getOutputStream());
      //      out.writeUTF("Thank you for connecting to " + server.getLocalSocketAddress() + "\nGoodbye ");
  //       String st=in.readUTF();
    //            System.out.println(st);
int i,j,offset;
        String temp,tempcode;
	String decrypt="";
        
      	tempcode=in.readUTF();
	char[] code=tempcode.toCharArray();  
	temp=in.readUTF();
	offset=Integer.parseInt(temp);

       // if(offset!=de_offset)
       // {
       //         printf("Provided key is wrong");
       //         flag=1;
       // }

       // if(flag!=1);
       // {
                for(i=0;i<tempcode.length();i++)
                {
                        if(code[i]<65+offset)
                        {
                                decrypt=decrypt+(code[i]-offset+26);
                        }

                        else
                        {
                                decrypt=decrypt+(code[i]-offset);
                        }
                }

                System.out.println("Decrypted text: "+decrypt);
       // }    
	server.close();
         }catch(SocketTimeoutException s)
         {
           System.out.println("Socket timed out!");
            break;
         }catch(IOException e)
         {
            e.printStackTrace();
            break;
         }
      }
   }
   public static void main(String [] args)
   {
      //int port = Integer.parseInt(args[0]);
      	int port = 6000;
	try
      {
         Thread t = new GreetingServer(port);
         t.start();
      }catch(IOException e)
      {
         e.printStackTrace();
      }
   }
}
