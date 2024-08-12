import java.io.*;
import java.util.Scanner;

public class p2a{
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		
		System.out.println("Enter text:");
		String text = input.nextLine();
		
		System.out.println("Enter key:");
		int key = input.nextInt();
		
		System.out.println("Enter option:\n1.Encrypt\n2.Decrypt\n");
		int op = input.nextInt();
		
		switch(op){
			case 1:
				encrypt(text,key);
				break;
			case 2:
				decrypt(text,key);
				break;
			default:
				System.out.println("Invalid!");
				break;
		}
	}
	
	public static void encrypt(String text, int key){
		String message = "";
		for(int i=0; i<text.length(); i++){
			message += (char)(((int)text.charAt(i)+key)%((int)'a'+26));
		}
		System.out.println("Encrypted text:"+message);
	}
	
	public static void decrypt(String text, int key){
		String message = "";
		for(int i=0; i<text.length(); i++){
			message += (char)(((int)text.charAt(i)-key+(int)'a'+26)%((int)'a'+26));
		}
		System.out.println("Decrypted text:"+message);
	}
}
