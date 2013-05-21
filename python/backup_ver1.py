# Filename: backup_ver1.py

import os
import time

# 1. The files and directories to be backed up are specified in a list.
source = ['C:\\Users\\Hugo\\Pictures', 'G:\\kankan']

# 2. The backup must be stored in a main backup directory
targetDir = 'E:\\Backup'

# 3. The files are backed up into a zip file.
# 4. The name of the zip archive is the current date and time
target = targetDir + os.sep + time.strftime('%Y%m%d%H%M%S') + '.zip'

# 5. We use the zip command to put the files in a zip archive
zipCommand = "zip - qr {0} {1}".format(target, ' '.join(source))

# Testing phase
print(zipCommand)

# Run the backup
if os.system(zipCommand) == 0:
    print('Successful backup to', target)
else:
    print('Backup FAILED')
    
