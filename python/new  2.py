# for语句的伪代码：
for item in container:
	// do something
[else:]
	// do something

# 遍历并输出1到10
for i in range(1, 11):
	print(i, end = ' ')
else:
	print("Finished.")

# 输出：
# 1 2 3 4 5 6 7 8 9 10 
# Finished.
	
# 计算1+2+...+10的和
numbers = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
sum = 0
for num in numbers:
	sum += num
else:
	print(sum)
	
# 输出：
# 55


# 对两个同长度的bitstring进行按位于操作
def AND(strA, strB):
    result = ''
    n = len(strA)
    for i in range(0, n):
        if(strA[i] == '1' and strB[i] == '1'):
            result += '1'
        else:
            result += '0'
    return result


# Test data
a = '0101101'
b = '1111111'
c = AND(a, b)
print(c)

# 输出：
# 0101101


# 遍历并输出list元素及其类型
mylist = [1, 1.0, 1.0j, '1', (1,), [1]]
for item in mylist:
    print (item, "\t", type(item))

# 输出：
# 1       <type 'int'>
# 1.0     <type 'float'>
# 1j      <type 'complex'>
# 1       <type 'str'>
# (1,)    <type 'tuple'>
# [1]     <type 'list'>

# 打印九九乘法表
for row in range(1, 10):
    for col in range(1, 10):
        print((row * col),'\t', end='')
    print()
# 同时遍历下标和元素
string = 'python'
print(string)
for index, item in enumerate(string):
    print('No.{0} item is {1}'.format(index, item))
	
# 输出：
# python
# No.0 item is p
# No.1 item is y
# No.2 item is t
# No.3 item is h
# No.4 item is o
# No.5 item is n


names = ['Python', 'Perl', 'Java', 'Lisp']
ages = [3, 6, 1, 8]

for name, age in zip(names, ages):
    print("{0} is {1} years old.".format(name, age))
	
# 输出
# Python is 3 years old.
# Perl is 6 years old.
# Java is 1 years old.
# Lisp is 8 years old.

dic = {'Python':3, 'Perl':6, 'Java':1, 'Lisp':8}
for name in dic:
    print("{0} is {1} years old.".format(name, dic[name]))
	
# 输出
# Python is 3 years old.
# Perl is 6 years old.
# Java is 1 years old.
# Lisp is 8 years old.

