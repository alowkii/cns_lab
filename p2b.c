import java.io.*;
import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;

public class p2b{
	private static char[][] lookupTable = new char[5][5];
	
	public static void fillTable(String key){
		Set<Character> charSet = new HashSet<Character>();
		int i=0, j=0;
		for(char chr:(key+"abcdefghiklmnopqrstuvwxyz").toCharArray()){
			if(charSet.add(chr)){
				lookupTable[i][j] = chr;
				j = ++j % 5;
				i += (j==0)?1:0;
			}
		}
	}
	
	public static String formatInput(String str){
		StringBuilder text = new StringBuilder(str.toLowerCase());
		for(int i=0; i<text.length(); i++){
			text.setCharAt(i,text.charAt(i)=='j'?'i':text.charAt(i));
		}
		return text.toString();
	}
	
	public static String changeChar(String text){
		return Character.toString(text.charAt(0)) + Character.toString((text.charAt(1)=='x'?'y':'x'));
	}
	
	public static int[] getPosition(char chr){
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				if(lookupTable[i][j] == chr)
					return new int[]{i,j};
			}
		}
		return null;
	}
	
	public static String lookup(String text, int x){
		int[] c0 = getPosition(text.charAt(0));
		int[] c1 = getPosition(text.charAt(1));
		
		int x0 = c0[0], y0 = c0[1];
		int x1 = c1[0], y1 = c1[1];
		
		if(c0 == c1)
			return text;
		if(y0 == y1){
			x0 = (x0+x)%5;
			x1 = (x1+x)%5;
		}else if(x0 == x1){
			y0 = (y0+x)%5;
			y1 = (y1+x)%5;
		}else{
			y0 = c1[1];
			y1 = c0[1];
		}
		return Character.toString(lookupTable[x0][y0]) + Character.toString(lookupTable[x1][y1]);
	}
	
	public static void encrypt(String text){
		StringBuilder ctext = new StringBuilder();
		String substr;
		int text_len = text.length(), i=0;
		while(i+2 < text_len){
			substr = text.substring(i,i+2);
			if(substr.charAt(0) == substr.charAt(1)){
				substr = changeChar(substr);
				i--;
				text_len++;
			}
			i+=2;
			ctext.append(lookup(substr,1));
		}
		if(text_len%2 != 0){
			text += "x";
			substr = Character.toString(text.charAt(text.length()-2))+Character.toString(text.charAt(text.length()-1));
			if(substr.charAt(0) == substr.charAt(1))
				substr = changeChar(substr);
			ctext.append(lookup(substr,1));
		}
		System.out.println("Encrypted: "+ctext.toString());
	}
	
	public static void decrypt(String text){
		if(text.length()%2 != 0){
			System.out.println("Invalid Input!");
			return;
		}
		
		StringBuilder ptext = new StringBuilder();
		for(int i=0; i<text.length();i+=2){
			String substr = text.substring(i,i+2);
			ptext.append(lookup(substr,4));
		}
		System.out.println("Decrypted: "+ptext.toString());
	}
	
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		
		System.out.print("Enter the key:");
		String key = input.nextLine();
		fillTable(formatInput(key));
		
		System.out.println("Table:");
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				System.out.print(lookupTable[i][j]+" ");
			}
			System.out.println();
		}
		
		input.nextLine();
		System.out.print("Enter the string:");
		String text = input.nextLine();
		
		System.out.println("Menu:\n1.Encrypt\n2.Decrypt");
		System.out.print("\nOption:");
		int op = input.nextInt();
		
		switch(op){
			case 1 -> encrypt(formatInput(text));
			case 2 -> decrypt(formatInput(text));
			default -> System.out.println("Invalid Option!");
		}
	}
}
