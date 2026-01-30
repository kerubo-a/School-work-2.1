
class Square:
    """Square class with side length"""
    
    def __init__(self, side):
        self.side = side
    
    def get_side(self):
        return self.side
    
    def get_area(self):
        return self.side * self.side
    
    def display_info(self):
        print(f"Square - Side: {self.side}")
        print(f"Area: {self.get_area()}")


class Cube(Square):
    """Cube class extends Square"""
    
    def __init__(self, side):
        super().__init__(side)
    
    def get_volume(self):
        return self.side ** 3
    
    def get_surface_area(self):
        return 6 * self.get_area()
    
    def display_info(self):
        print(f"Cube - Side: {self.get_side()}")
        print(f"Surface Area: {self.get_surface_area()}")
        print(f"Volume: {self.get_volume()}")


# Test the classes
if __name__ == "__main__":
    print("=== Shape Inheritance Test ===\n")
    
    # Create Square object
    square = Square(5.0)
    print("Square Test:")
    square.display_info()
    
    print("\n" + "=" * 40 + "\n")
    
    # Create Cube objects
    cube1 = Cube(4.0)
    print("Cube Test:")
    cube1.display_info()
    
    print("\n" + "=" * 40 + "\n")
    
    cube2 = Cube(10.0)
    print("Large Cube Test:")
    cube2.display_info()