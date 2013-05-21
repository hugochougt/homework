# Filename: twentyfour.py

operations = [(lambda a, b: a + b, lambda a, b: "( " + str(a) + " + " + str(b) + " )"),  
                      (lambda a, b: a - b, lambda a, b: "( " + str(a) + " - " + str(b) + " )"),  
                      (lambda a, b: b - a, lambda a, b: "( " + str(b) + " - " + str(a) + " )"),  
                      (lambda a, b: a * b, lambda a, b: "( " + str(a) + " * " + str(b) + " )"),  
                      (lambda a, b: a // b, lambda a, b: "( " + str(a) + " / " + str(b) + " )"),  
                      (lambda a, b: b // a, lambda a, b: "( " + str(b) + " / " + str(a) + " )")]  
  
targetNumber = 24  
resultMap = dict()  
  
def search(numSet):  
    if len(numSet) <= 1:  
        return numSet[0] == targetNumber and " " + str(targetNumber) + " " or None  
    numSet.sort();  
    if tuple(numSet) in resultMap:  
        return resultMap[tuple(numSet)];  
      
    for a in range(0, len(numSet) - 1):  
        for b in range(a + 1, len(numSet)):  
            for op in operations:  
                try:  
                    newList = [n for n in numSet if n != numSet[a] and n != numSet[b]]  
                    newList.append(op[0](numSet[a], numSet[b]))  
                    res = search(newList)  
                    if res:  
                        res = res.replace(" " + str(op[0](numSet[a], numSet[b])) + " ", op[1](numSet[a], numSet[b]), 1)  
                        resultMap[tuple(numSet)] = res  
                        return res  
                    newList.pop()  
                except ZeroDivisionError:  
                    pass  
    resultMap[tuple(numSet)] = None  
    return None  
  
if __name__ == "__main__":
    print(search([3, 8, 3, 8]))
    print(search([3, 3, 8, 8]))
    print(search([3, 3, 7, 7]))  
    print(search([3, 6, 1, 9]))  
