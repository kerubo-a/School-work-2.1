class Roommate:
    def __init__(self, name, age, hobby):
        self.name = name
        self.age = age
        self.hobby = hobby

    def introduce(self):
        print(f"Hi, I'm {self.name}, {self.age} years old and I enjoy {self.hobby}!")

    def do_activity(self):
        print(f"{self.name} is currently {self.hobby}.")


# Example
r1 = Roommate("John", 22, "playing football")
r1.introduce()
r1.do_activity()
