# Filename:valueSorted.py

class hist(dict):
    def add(self, item, increment = 1):
        ''' 为item的条目增加计数 '''
        self[item] = increment + self.get(item, 0)
    def counts(self, reverse = False):
        ''' 返回根据对应值排序的键的列表 '''
        aux = [ (self[k], k) for k in self ]
        aux.sort()
        if reverse:
            aux.reverse()
        return [k for v, k in aux]

sentence = ''' Hello there this is a test. Hello there this was a test,
                    but noe it is not. '''
words = sentence.split()
c = hist()

for word in words:
    c.add(word)

print "Ascending count:"
print c.counts()
print "Descending count:"
print c.counts(reverse = True)
