
'''用類來描述棧:
1.其限制是仅允许在表的一端进行插入和删除运算。
栈允许进行插入和删除操作的一端称为栈顶(top)，另一端为栈底(bottom)；栈底固定，而栈顶浮动；栈中元素个数为零时称为空栈。插入一般称为进栈（PUSH），删除则称为退栈（POP）。
由于堆叠数据结构只允许在一端进行操作，因而按照后进先出（LIFO, Last In First Out）的原理运作。栈也称为后进先出表。
'''
class Stack(object):
    def __init__(self,limit=10):
        self.stack = [] # 棧存放元素
        self.limit = limit # 棧容量

    def push(self,data):
        '''壓棧前需要判斷棧滿沒滿'''
        if len(self.stack) >= self.limit:
            raise IndexError('超出棧容量！')
        self.stack.append(data)

    def pop(self):
        """1.判斷棧是否爲空2.彈出棧頂。"""
        if len(self.stack)!=0:
            return self.stack.pop()
        else:
            raise IndexError("空棧！")

    def size(self):
        """返回棧長度"""
        return len(self.stack)

    def is_empty(self):
        """判斷是否爲空"""
        return not bool(self.stack)

    def peek(self):
        """返回棧頂元素"""
        if self.stack:#首先判斷是不是空棧
            return self.stack[-1]
        else:
            raise IndexError("空棧！")



"""應用：利用棧實現括號字符串對的匹配
有效括号字符串需满足：

    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。
    注意空字符串可被认为是有效字符串。

举例：

((())): True

((()): False

(())): False

目标：

    使用一个堆栈作为数据结构
    来检查括号字符串是否完全匹配

"""

def balanced_parentheses(parentheses):
    """"""
    stack = Stack(len(parentheses))
    for parenthesis in parentheses:
        if parenthesis == "(":
            stack.push(parenthesis)
        elif parenthesis == ")":
            if stack.is_empty():
                return False
            stack.pop()

    return stack.is_empty()

if __name__ =='__main__':
    examples = ['(()))','((())','((()))']
    print('Balanced parentheses demonstration:\n')
    for example in examples:
        print(example + ': ' + str(balanced_parentheses(example)))



