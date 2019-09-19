class myclass:
    num = 5
    def clfunc():
        return myclass.num

    def __init__(self):
        self.num = 2
        self.str = 'hello'

    def __str__(self):
        return self.str

    def func(self, n):
        print(n)

