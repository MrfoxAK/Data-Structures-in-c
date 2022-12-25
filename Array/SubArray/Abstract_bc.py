from abc import ABCMeta, abstractclassmethod

class Shape(metaclass = ABCMeta):
    @abstractclassmethod
    def p1(self):
        return 0



class Rectangle(Shape):
    type = "Rectangle"
    sides = 4
    def __init__(self) -> None:
        self.length = 6
        self.breadth = 7

    def p1(self):
        return self.length * self.breadth


r1 = Rectangle()



print(r1.p1())






















