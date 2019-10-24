package CodingCompetitionAnswers.JanuaryEasyChallenge;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class MachineGun 
{
	public static void main(String[] args) throws IOException 
	{
		FastReader scan = new FastReader(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int N = scan.readInt();
		int[] arr = scan.readIntArray(N);

		Arrays.sort(arr);

		for (int i = 0; i < N; i++) 
		{
			out.print((arr[i] - i) + " ");
		}
		out.println();
		out.close();
	}

	static class FastReader 
	{
		private InputStream in = null;
		private int pos, count;
		private byte[] buf = new byte[1 << 16];

		public FastReader(InputStream in) 
		{
			this.in = in;
			pos = 0;
			count = 0;
		}

		private int read() 
		{
			if (pos == count)
				fillBuffer();

			return buf[pos++];
		}

		private void fillBuffer() 
		{
			try {
				count = in.read(buf, pos = 0, buf.length);
				if (count == -1)
					buf[0] = -1;
			} catch (Exception e) {

			}
		}

		public int readInt() {
			int c = read(), sign = 1;
			while (c <= ' ')
				c = read();
			if (c == '-') {
				sign = -1;
				c = read();
			}
			int n = (c - '0');
			while ((c = read() - '0') >= 0)
				n = n * 10 + c;
			return n * sign;
		}

		public long readLong() {
			int c = read(), sign = 1;
			while (c <= ' ')
				c = read();
			if (c == '-') {
				sign = -1;
				c = read();
			}
			long n = 1L * (c - '0');
			while ((c = read() - '0') >= 0)
				n = n * 10 + c;
			return n * sign;
		}

		public char readChar() {
			int c = read();
			while (c <= ' ')
				c = read();
			return (char) c;
		}

		public double readDouble() {
			return Double.parseDouble(readString());
		}

		public String readString() {
			StringBuilder sb = new StringBuilder();
			int c = read();
			while (c <= ' ')
				c = read();
			while (c > ' ') {
				sb.append((char) c);
				c = read();
			}
			return sb.toString();
		}

		public String readLine() {
			StringBuilder sb = new StringBuilder();
			int c = read();
			while (c < ' ')
				c = read();
			while (c >= ' ') {
				sb.append((char) c);
				c = read();
			}
			return sb.toString();
		}

		public int[] readIntArray(int N) {
			int[] arr = new int[N];
			for (int i = 0; i < N; i++) {
				arr[i] = readInt();
			}
			return arr;
		}

		public long[] readLongArray(int N) {
			long[] arr = new long[N];
			for (int i = 0; i < N; i++) {
				arr[i] = readLong();
			}
			return arr;
		}

		public double[] readDoubleArray(int N) {
			double[] arr = new double[N];
			for (int i = 0; i < N; i++) {
				arr[i] = readDouble();
			}
			return arr;
		}

		public String[] readStringArray(int N) {
			String[] arr = new String[N];
			for (int i = 0; i < N; i++) {
				arr[i] = readString();
			}
			return arr;
		}

		public char[] readCharArray(int N) {
			char[] arr = new char[N];
			for (int i = 0; i < N; i++) {
				arr[i] = readChar();
			}
			return arr;
		}
	}
}