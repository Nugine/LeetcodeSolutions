# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        return self.atn_ra(l1, l2)

    @staticmethod
    def atn_wa(l1, l2):
        # may overflow when using other language
        def l2num(ln):
            num = ln.val
            digit = 0
            while ln.next is not None:
                ln = ln.next
                digit += 1
                num += ln.val * (10 ** digit)
            return num

        def num2l(num):
            head = ln = ListNode(num % 10)
            while True:
                num //= 10
                if num:
                    ln.next = ln = ListNode(num % 10)
                else:
                    break
            return head

        n1, n2 = l2num(l1), l2num(l2)
        return num2l(n1 + n2)

    @staticmethod
    def atn_ra(l1, l2):
        en = ListNode(0)
        head = ln = ListNode(0)
        carry = 0
        while not (l1 is l2 is en):
            v = l1.val + l2.val + carry
            carry = v // 10
            ln.next = ln = ListNode(v % 10)
            l1 = en if l1.next is None else l1.next
            l2 = en if l2.next is None else l2.next
        if carry:
            ln.next = ListNode(carry)
        return head.next
