
from queue import Queue


class Node(object):
    def __init__(self, data, left=None, right=None):
        self.left = left
        self.right = right
        self.data = data


class Traversal(object):
    def __init__(self, tree: Node):
        self.tree = tree

    def bfs(self):
        """Breadth frist or level order traversal"""
        # the q
        q = Queue()
        q.put(self.tree)
        while not q.empty():
            # take the root of tree
            current = q.get()
            print(current.data)
            if current.left:
                q.put(current.left)
            if current.right:
                q.put(current.right)

    def dfs_inorder(self):
        """Depth first in order traversal (left, root, right)"""
        def traversal(node):
            if not node:
                return
            traversal(node.left)
            print(node.data)
            traversal(node.right)
        traversal(self.tree)

    def dfs_postorder(self):
        """Depth frist post order traversal (left, right, root)"""
        def traversal(node):
            if not node:
                return
            traversal(node.left)
            traversal(node.right)
            print(node.data)

        traversal(self.tree)


def main():
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)

    traversal = Traversal(root)
    print("Breadth first traversal")
    traversal.bfs()
    print("Inorder depth first order")
    traversal.dfs_inorder()
    print("Post deptth first travereal")
    traversal.dfs_postorder()

if __name__ == '__main__':
    main()
