
import java.math.BigDecimal;


/**
 * 计算业务类
 */
public class CalService {
	// 存储器,默认为0，用于保存需要暂时保存的计算结果
	private double store = 0;
	// 第一个操作数
	private String firstNum = null;
	// 上次操作
	private String lastOp = null;
	// 第二个操作数
	private String secondNum = null;
	// 是否第二个操作数，如果是，点击数字键时，则在文本框中重新输入
	private boolean isSecondNum = false;

	// 数字
	private String numString = "0123456789.";
	// 四则运算
	private String opString = "+-×÷";

	/**
	 * 默认构造器
	 */
	public CalService() {
		super();
	}

	/**
	 * 调用方法并返回计算结果
	 * 
	 * @return String
	 */
	public String callMethod(String cmd, String text) throws Exception {
		if(cmd.equals("C")) 
			return clearAll();
		else if(cmd.equals("CE")) 
			return clear(text);
		else if(cmd.equals("←"))
			return backSpace(text);
		else if(numString.indexOf(cmd) != -1)
			return catNum(cmd, text);
		else if(opString.indexOf(cmd) != -1)
			return setOp(cmd, text);
		else if(cmd.equals("="))
			return cal(text, false);
		else if(cmd.equals("±"))
			return setNegative(text);
		else if(cmd.equals("1/x"))
			return setReciprocal(text);
		else if(cmd.equals("√"))
			return sqrt(text);
		else if(cmd.equals("%"))
			return cal(text, true);
		else
			return mCmd(cmd, text);
	}
	
	/**
	 * 计算四则运算结果
	 * 
	 * @param text
	 *            String 输入框中的值
	 * @param isPercent
	 *            boolean 是否有"%"运算
	 * @return String 封闭成字符串的计算结果
	 */
	public String cal(String text, boolean isPercent) throws Exception {
		double secondResult = secondNum == null ?
				Double.valueOf(text).doubleValue() :
				Double.valueOf(secondNum).doubleValue();
		
		if (secondResult == 0 && this.lastOp.equals("÷")) {
			return "0";
		}
		
		if (isPercent) {
			secondResult = MyMath.multiply(Double.valueOf(firstNum), 
					MyMath.divide(secondResult, 100));
		}
		
		if (this.lastOp.equals("+")) {
			firstNum = String.valueOf(MyMath.add(
					Double.valueOf(firstNum), secondResult));
		}
		else if (this.lastOp.equals("-")) {
			firstNum = String.valueOf(MyMath.subtract(
					Double.valueOf(firstNum), secondResult));
		}
		else if (this.lastOp.equals("×")) {
			firstNum = String.valueOf(MyMath.multiply(
					Double.valueOf(firstNum), secondResult));
		}
		else if (this.lastOp.equals("÷")) {
			firstNum = String.valueOf(MyMath.divide(
					Double.valueOf(firstNum), secondResult));
		}
		
		secondNum = secondNum == null ? text : secondNum;
		
		this.isSecondNum = true;
		return firstNum;
	}

	/**
	 * 计算倒数
	 * 
	 * @param text
	 *            String 输入框中的值
	 * @return String 封闭成字符串的结果
	 */
	public String setReciprocal(String text) {
		if(text.equals("0")) {
			return text;
		}
		else {
			this.isSecondNum = true;
			return String.valueOf(MyMath.divide(1, Double.valueOf(text)));
		}
	}

	/**
	 * 计算开方
	 * 
	 * @param text
	 *            String 输入框中的值
	 * @return String 封闭成字符串的结果
	 */
	public String sqrt(String text) {
		this.isSecondNum = true;
		return String.valueOf(Math.sqrt(Double.valueOf(text)));
	}

	/**
	 * 设置操作符号
	 * 
	 * @param cmd
	 *            String 操作符号
	 * @param text
	 *            String 输入框中的值
	 * @return String 封闭成字符串的结果
	 */
	public String setOp(String cmd, String text) {
		this.lastOp = cmd;
		this.firstNum = text;
		this.secondNum = null;
		this.isSecondNum = true;
		return null;
	}

	/**
	 * 设置正负数
	 * 
	 * @param text
	 *            String 输入框中的值
	 * @return String 封闭成字符串的结果
	 */
	public String setNegative(String text) {
		if(text.indexOf("-") == 0) {
			return text.substring(1, text.length());
		}
		
		return text.equals("0") ? text : "-" + text;
	}

	/**
	 * 连接输入的数字，每次点击数字 把新加的数字追加到后面
	 * 
	 * @param cmd
	 *            String 操作符号
	 * @param text
	 *            String 输入框中的值
	 * @return String 封闭成字符串的结果
	 */
	public String catNum(String cmd, String text) {
		String result = cmd;
		
		if(!text.equals("0")) {
			if(isSecondNum) {
				isSecondNum = false;
			}
			else {
				result = text + cmd;
			}
		}
		
		if(result.indexOf(".") == 0) {
			result = "0" + result;
		}
		
		return result;
	}

	/**
	 * 实现backspace功能
	 * 
	 * @param text
	 *            String 现在文体框的结果
	 * @return String
	 */
	public String backSpace(String text) {
		return text.equals("0") || 
				text.equals("") ? "0" : text.substring(0, text.length() - 1);
	}
	
	/**
	 * 实现存储操作命令
	 * 
	 * @param cmd
	 *            String 操作符号
	 * @param text
	 *            String 现在文体框的结果
	 * @return String
	 */
	public String mCmd(String cmd, String text) {
		if(cmd.equals("M+")) {
			store = MyMath.add(store, Double.valueOf(text));
		}
		else if(cmd.equals("MC")) {
			store = 0;
		}
		else if(cmd.equals("MR")) {
			isSecondNum = true;
			return String.valueOf(store);
		}
		else if(cmd.equals("MS")) {
			store = Double.valueOf(text).doubleValue();
		}
		return null;
	}

	/**
	 * 清除所有计算结果
	 * 
	 * @return String
	 */
	public String clearAll() {
		this.firstNum = "0";
		this.secondNum = null;
		return this.firstNum;
	}

	/**
	 * 清除上次计算结果
	 * 
	 * @param text
	 *            String 现在文体框的结果
	 * @return String
	 */
	public String clear(String text) {
		return "0";
	}

	/**
	 * 返回存储器中的结果
	 * 
	 * @return double
	 */
	public double getStore() {
		return this.store;
	}

}