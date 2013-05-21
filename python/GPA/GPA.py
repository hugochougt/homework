# filename: GPA.py

from __future__ import division

f = open('GPA.txt')
while True:
    line = f.readline()
    if not line:
        break
    ch = tuple(line)
    a = int(ch[0])
    b = int(ch[2]) * 10 + int(ch[3])
    if b >= 95:
        b = 5.0
    else:
        b = 5.0 - (95 - b) / 10
    
    print b
f.close()
