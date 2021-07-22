class stackInt:
    stackTop = 0
    arr = []

class stackOpr:
    stackTop = 0
    arr = []
    
    def stackPush(self, x):
        self.arr[stackTop] = x
        self.stackTop += 1
    
    def stackPop(self, x):
        self.stackTop -= 1
        return self.arr[stackTop]

def calculate(stackInt, stackOpr, opr):
    if(opr == '+'):
        stackInt.arr[stackInt.stackTop - 1] += stackInt.arr[stackInt.stackTop]
    elif(opr == '-'):
        stackInt.arr[stackInt.stackTop - 1] -= stackInt.arr[stackInt.stackTop]