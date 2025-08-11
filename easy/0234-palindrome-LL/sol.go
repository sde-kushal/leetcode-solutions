package palindromell

type ListNode struct {
	Val  int
	Next *ListNode
}

func isPalindrome(head *ListNode) bool {
	recorded := []int{}
	slow, fast := head, head
	count, ptr := 0, 0

	// track first half values
	for fast != nil {
		recorded = append(recorded, slow.Val)
		slow = slow.Next
		fast = fast.Next
		count += 1

		if fast != nil {
			fast = fast.Next
			count += 1
		}
	}

	ptr = count/2 - 1

	// check palindrome for half the list
	for slow != nil {
		if slow.Val != recorded[ptr] {
			return false
		}
		slow = slow.Next
		ptr -= 1
	}

	return true
}
