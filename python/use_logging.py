# Filename: use_logging.py
import os, platform, logging

if platform.platform().startswith('Windows'):
    loggingFile = os.path.join(os.getenv('HOMEDRIVE'), \
                               os.getenv('HOMEPATH'), 'test.log')
else:
    loggingFile = os.path.join(os.getenv('HOME'), 'test.log')

logging.basicConfig(
    level = logging.DEBUG,
    format = '%(asctime)s : %(levelname)s : %(message)s',
    filename = loggingFile,
    filemode = 'w',
    )

logging.debug('Start of the program')
logging.info('Doing sth')
logging.warning('Dying now')
