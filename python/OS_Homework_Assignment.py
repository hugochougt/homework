#-*- coding:utf8 -*- 
#Filename:OS_Homework_Assignment.py

TeamMember = ['何唯', '俞盼盼', '邹沁芬', '范熊思', '项留洋',\
              '章磊', '杨子墨', '高雨', '章军财', '周昌权']

OS = ['Ubuntu', 'Fedora', 'OpenSUSE', 'Debian', 'PCLinuxOS', 'CentOS',\
      'FreeBSD', 'Windows8', 'Mac OS X Lion', 'Mac OS X Snow Leopard']

TMArr = []
OSArr = []

import random

n = 10
while n > 0:
    tmp = random.randint(0, 9)
    if tmp not in TMArr:
        TMArr.append(tmp)
        n -= 1

# print(TMArr)

n = 10
while n > 0:
    tmp = random.randint(0, 9)
    if tmp not in OSArr:
        OSArr.append(tmp)
        n -= 1

# print(OSArr)

print('每人对应负责的操作系统：')
for i in range(10):
    print(TeamMember[TMArr[i]], '\t', OS[OSArr[i]])
