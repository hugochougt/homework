# user_input.py

def reverse(text):
    return text[::-1]

def isPalindrome(text):
    return text == reverse(text)

something = input("Enter text: ")
if isPalindrome(something):
    print('Yes')
else:
    print("No")
