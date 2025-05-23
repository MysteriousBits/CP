import random

n = 10

def gen(n):
    parent = [0] * (n + 1);
    tree = [1]
    rem = [i for i in range(2, n + 1)]

    for i in range(n - 1):
        p = random.randint(0, len(tree) - 1)
        parent[rem[-1]] = tree[p]
        tree.append(rem[-1])
        rem.pop()

    return parent


if __name__ == __main__:
    parent = gen(n)
    print(n)
    for i in range(2, n + 1):
        print(i, parent[i])
