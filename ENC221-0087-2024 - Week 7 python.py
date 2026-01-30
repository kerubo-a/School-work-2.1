
class Employee:
    """Base Employee class"""
    
    def __init__(self, name, service_year, salary):
        self.name = name
        self.service_year = service_year
        self.salary = salary
    
    def get_name(self):
        return self.name
    
    def get_age(self):
        return self.service_year
    
    def get_service_year(self):
        return self.service_year
    
    def get_salary(self):
        return self.salary
class Manager(Employee):
    """Manager class extends Employee"""
    
    def __init__(self, name, service_year, salary, department):
        super().__init__(name, service_year, salary)
        self.department = department
    
    def get_department(self):
        return self.department
    
    def display_info(self):
        print(f"Manager Name: {self.get_name()}")
        print(f"Service Years: {self.get_service_year()}")
        print(f"Salary: ${self.get_salary():,.2f}")
        print(f"Department: {self.department}")
class Developer(Employee):
    """Developer class extends Employee"""
    
    def __init__(self, name, service_year, salary, programming_language):
        super().__init__(name, service_year, salary)
        self.programming_language = programming_language
    
    def get_programming_language(self):
        return self.programming_language
    
    def display_info(self):
        print(f"Developer Name: {self.get_name()}")
        print(f"Service Years: {self.get_service_year()}")
        print(f"Salary: ${self.get_salary():,.2f}")
        print(f"Programming Language: {self.programming_language}")
# Test the classes
if __name__ == "__main__":
    print("=== Employee Management System Test ===\n")
    
    # Create Manager object
    manager = Manager("Robert Smith", 8, 95000.0, "Engineering")
    print("Manager Information:")
    manager.display_info()
    
    print("\n" + "=" * 40 + "\n")
    
    # Create Developer objects
    developer1 = Developer("Emily Chen", 5, 80000.0, "Python")
    print("Developer Information:")
    developer1.display_info()
    
    print("\n" + "=" * 40 + "\n")
    
    developer2 = Developer("Michael Brown", 3, 70000.0, "Java")
    print("Another Developer:")
    developer2.display_info()