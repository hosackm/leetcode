# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

    def __iter__(self):
        yield self.val
        n = self.next
        while n:
            yield n.val
            n = n.next

    def __repr__(self):
        return "".join([str(n) for n in self])[::-1]


class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        res = None
        if l1 is not None or l2 is not None:
            addend1 = l1.val if l1 is not None else 0
            addend2 = l2.val if l2 is not None else 0
            sum = addend1 + addend2
            carry = 1 if sum >= 10 else 0

            if carry:
                sum -= 10
                if l1.next:
                    l1.next.val += carry
                else:
                    l1.next = ListNode(carry)

            res = ListNode(sum)
            res.next = self.addTwoNumbers(l1.next if l1 else None, l2.next if l2 else None)

        return res


if __name__ == "__main__":
    s = Solution()
    l1 = ListNode(2)
    l1.next = ListNode(4)
    l1.next.next = ListNode(6)

    l2 = ListNode(5)
    l2.next = ListNode(3)
    l2.next.next = ListNode(4)

    res = s.addTwoNumbers(l1, l2)
    print("->".join(str(n) for n in res))
