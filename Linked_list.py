'''node爲鏈表的基本節點，Linked_list爲類定義'''
class Node:
    def __init__(self, data):
        self.data = data  # 表示对应的元素值
        self.next = None  # 表示下一个链接的链点

class Linked_list:
    def __init__(self,head=None):
        self.head = head

    def append(self, new_element):
        """注意頭部節點的判斷是否爲空"""
        # 将头部结点指向临时变量 current
        current = self.head
        # 当头部结点存在时
        if self.head:
            # 循环遍历到链表的最后一个元素
            while current.next:
                current = current.next
            current.next = new_element
        # 当头部结点不存在时
        else:
            self.head = new_element

    def is_empty(self):
        if self.head:
            return False
        else:
            return True

    def insert(self,index,new_element):
        """
    先判断要插入的位置是否在链表的索引范围内。
    当插入的位置是头结点（即索引为 0）时，做特殊情况处理。
    当要插入结点的位置不在 0 时，找到要插入的位置，插入新结点
        :param index:
        :param new_element:
        :return:
        """
        if index < 0 or index > self.get_length():
            raise IndexError("index beyond range!")
        current = self.head
        if index == 0:
            self.head = new_element
            self.head.next = current
            return
        else:
            while index != 0:
                pre = current
                current = current.next
                index -= 1
            pre.next = new_element
            new_element.next = current

    def get_length(self):
        """
        求鏈表長度
        :return:
        """
        current = self.head
        lenth = 0
        # 当头部结点存在时
        if self.head:
            # 循环遍历到链表的最后一个元素
            while current.next:
                current = current.next
                lenth += 1
            lenth = lenth + 1
            return lenth
        else:
            return 0

    def remove(self,position):
        """
    先判断要删除的元素索引是否存在，如果不存在抛出错误
    接着判断当存在(不是none)链表元素时才能执行删除操作。
    当要删除的是头结点时（即索引为 0），做特殊情况处理。
    其他情况时，通过循环找到要删除的结点。
    最后要做的就是把这个结点删除掉。
        :param index:
        :return:
        """
        if position < 0 or position > self.get_length() - 1:
            # print("insert error")
            raise IndexError('删除元素的索引超出范围')

        i = 0
        temp = self.head
        # 当存在链表元素时才能执行删除操作
        while temp != None:
            # 将头结点的后一个结点赋值给新的头结点，再将之前的头结点指向 `None`
            if position == 0:
                self.head = temp.next
                temp.next = None
                return

            pre = temp
            # 以此来遍历链表
            temp = temp.next
            # pre, temp = temp, temp.next
            i += 1
            if i == position:
                # 将 pre 的 next 属性指向 temp 的下一个结点
                pre.next = temp.next
                temp.next = None
                # pre.next, temp.next = temp.next, None
                return

    def print_list(self):
        """
        遍历链表，并将元素依次打印出来
        """
        print("linked_list:")
        # 头部结点赋值给临时变量 temp
        temp = self.head
        while temp is not None:
            print(temp.data)
            temp = temp.next

    def reverse(self):
        """
        将链表反转
        """
        prev = None
        current = self.head
        while current:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        self.head = prev

    def initlist(self,data_list):
        """
        将列表转换为链表
        """
        # 创建头结点
        self.head = Node(data_list[0])
        temp = self.head
        # 逐个为 data 内的数据创建结点, 建立链表
        for i in data_list[1:]:
            node = Node(i)
            temp.next = node
            temp = temp.next