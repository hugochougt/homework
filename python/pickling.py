# Filename: pickling.py

import pickle
shoplistFile = 'shoplist.data'
shoplist = ['apple', 'mango', 'carrot']

f = open(shoplistFile, 'wb')
pickle.dump(shoplist, f)
f.close()

del shoplist

f = open(shoplistFile, 'rb')
storedlist = pickle.load(f)
f.close()
print(storedlist)
