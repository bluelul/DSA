class Node(object):
	def __init__(self, val = None, next = None):
		super(Node, self).__init__()
		self.val = val
		self.next = next
	
class LinkedList1(object):
	
	def __init__(self):
		super(LinkedList, self).__init__()
		self.last = Node(0,0)
		self.first = Node(0,self.last)
		
	def print(self):
		i = self.first.next
		while i != self.last:
			print(i.val)
			i = i.next

	def addFirst(self, val):
		x = Node(val, self.first.next)
		self.first.next = x
		if self.last.next == 0:
			self.last.next = x
	
	def addLast(self, val):
		x = Node(val, self.last)
		if self.last.next != 0:
			self.last.next.next = x
		else:
			self.first.next = x
		self.last.next = x

	def deleteFirst(self):
		if self.first.next != self.last:
			x = self.first.next
			self.first.next = self.first.next.next
			x.next = 0
		else:
			print("no node left to delete")

	def deleteLast(self):
		if self.first.next != self.last:
			pre = self.first.next
			while pre.next != self.last.next:
				pre = pre.next

			x = self.last.next
			self.last.next = pre
			pre.next = self.last
			x.next = 0	
		else:
			print("no node left to delete")
		

class LinkedList(object):
	
	def __init__(self):
		super(LinkedList, self).__init__()
		self.first = self.last = Node()
		
	def print(self):
		if self.first.val != None:
			i = self.first
			while i != self.last:
				print(i.val)
				i = i.next
			print(i.val)
	
	def addLast(self, val):
		x = Node(val)
		if self.first.val == None:
			self.first = self.last = x
		else:
			self.last.next = x
			self.last = x

	def addFirst(self, val):
		x = Node(val)
		if self.first.val == None:
			self.first = self.last = x
		else:
			x.next = self.first
			self.first = x

	def deleteFirst(self):
		if self.first.val == None:
			print("no node left to delete")
		elif self.first == self.last:
			self.first = self.last = Node()
		else:
			x = self.first.next
			self.first.next = None
			self.first = x
		
	def deleteLast(self):
		if self.first.val == None:
			print("no node left to delete")
		elif self.first == self.last:
			self.first = self.last = Node()
		else:
			pre = self.first
			while pre.next != self.last:
				pre = pre.next
			
			pre.next = None
			self.last = pre

if __name__ == '__main__':
	list = LinkedList()
 
	list.addLast(32)
	list.addLast(44)
	

	list.addFirst(10)
	list.addFirst(20)
	list.addFirst(30)

	list.deleteFirst()
	list.deleteFirst()

	list.deleteLast()
	list.deleteLast()
	# list.deleteLast()

	list.print()
