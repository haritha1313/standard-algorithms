class Node:
    def __init__(self):
        self.value = 0
        self.cildren = [None] * 26
        

class Trie:

    def __init__(self):
        self.root = Node()

    def add(self, word):
        bs = self.root
        for c in word:
            idx = ord(c) - ord('a')
            if not bs.cildren[idx]:
                bs.cildren[idx] = Node()
            bs = bs.cildren[idx]
        bs.value = 1;

    def find(self, word):
        bs = self.root
        for c in word:
            idx = ord(c) - ord('a')
            if not bs.cildren[idx]:
                return False
            bs = bs.cildren[idx]
        if bs.value != 0:
            return True
        else:
            return False
                

    def prefix(self, prefix):
        bs = self.root
        for c in prefix:
            idx = ord(c) - ord('a')
            if not bs.cildren[idx]:
                return False
            bs = bs.cildren[idx]
        return True

trie = Trie()
trie.add("somestring")
print (trie.prefix("som"))