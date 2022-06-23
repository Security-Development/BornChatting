

import java.io.*;
import java.net.*;

class BonCalClientAPI  {

    private int MaxBuffer = 512;
    private Socket client;

    public BonCalClientAPI(String host = "127.0.0.1", int port = 9999) {
        this.SetSocket(host, port);
    }
    
    public String GetReciveMessage() {  
        byte recv[] = new byte[this.MaxBuffer];
        InputStream input = this.client.getInputStream();
        int size = input.read(recv);

        if( size < 0)
            return "The message could not be found.";

        return new String(recv, false, size);
    }

    public void SocketClose(){
        this.client.close();
        System.out.println("[-] The socket has been closed.");
    }

    public Socket GetSocket() {
        return this.client;
    }

    public int GetMaxBufferSize() {
        return this.MaxBuffer;
    }

    public void SetSocket(String host, int port) {
        this.client = new Socket();
        SocketAddress address = new SocketAddress(host, port);

        this.client.connect(address);

        System.out.println("[+] Successful socket connection!!");
    }

    public void SetMaxBuffSize(int size) {
        this.MaxBuffer = size;
    }

    public static void main(String args[]) {

    }

}
