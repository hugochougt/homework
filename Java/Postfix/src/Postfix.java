// 简单表达式的翻译器
import java.io.*;

public class Postfix {
	public static void main(String[] args) throws IOException {
		Parser parser = new Parser();
		parser.expr();
		System.out.write('\n');
	}
}
