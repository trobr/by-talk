class test(object):
    num = 5

    def __init__(self, is_bool, *args, **kwargs):
        if is_bool:
            test.num += 1
        return super().__init__(*args, **kwargs)

    def count(self):
        self.num += 1

    def print_num(self):
        print(test.num)


t1 = test(True)
print(t1.count)
t1.print_num()
t2 = test(True)
print(t2.count)
t2.print_num()
t3 = test(False)
print(t3.count)
t3.print_num()
t4 = test(True)
print(t4.count)
t4.print_num()
