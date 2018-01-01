LEFT = 0
RIGHT = 1

class Node:
	def __init__(self, x):
		self.data = x
		self.left = None
		self.right = None
	
	def __repr__(self):
		return `self.data`

def rotate_right(node):
	lnode = node.left
	node.left = lnode.right
	lnode.right = node
	return lnode

def rotate_left(node):
	rnode = node.right
	node.right = rnode.left
	rnode.left = node
	return rnode

def search(node, x):
	path = []
	if node is None: return node, False
	while node is not None:
		if node.data == x:
			return splay(node, path), True
		if x < node.data:
			path.append((node, LEFT))
			node = node.left
		else:
			path.append((node, RIGHT))
			node = node.right
	node, dirr = path.pop()
	if len(path) == 0: return node, False
	return splay(node, path), False

def splay(node, path):
	while len(path) > 1:
		node, dirr = path.pop()
		pnode, pdirr = path.pop()
		if dirr == pdirr:
			# zig-zig
			if dirr == LEFT:
				pnode = rotate_right(pnode)
				node = rotate_right(pnode)
			else:
				pnode = rotate_left(pnode)
				node = rotate_left(pnode)
		else:
			# zig-zag
			if dirr == LEFT:
				pnode.right = rotate_right(node)
				node = rotate_left(pnode)
			else:
				pnode.left = rotate_left(node)
				node = rotate_right(pnode)
		if len(path) == 0: return node
		gnode, gdirr = path[-1]
		if gdirr == LEFT:
			gnode.left = node
		else:
			gnode.right = node
	# zig
	if len(path) == 0: return node
	node, dirr = path.pop()
	if dirr == LEFT:
		node = rotate_right(node)
	else:
		node = rotate_left(node)
	return node

def insert(node, x):
	if node is None: return Node(x)
	node, result = search(node, x)
	if result: return node
	new_node = Node(x)
	if x < node.data:
		new_node.right = node
		new_node.left = node.left
		node.left = None
	else:
		new_node.left = node
		new_node.right = node.right
		node.right = None
	return new_node

def delete(node, x):
	if node is None: return node, False
	node, result = search(node, x)
	if not result: return node, False
	if node.left is None:
		return node.right, True
	elif node.right is None:
		return node.left, True
	else:
		node1, result = search(node.left, x)
		node1.right = node.right
		return node1, True
