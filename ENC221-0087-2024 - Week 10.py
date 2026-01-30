
class Employee:
    """Base class for all employees"""
    
    def __init__(self, first_name, initial, last_name):
        self.first_name = first_name
        self.initial = initial
        self.last_name = last_name
    
    def get_first_name(self):
        return self.first_name
    
    def get_initial(self):
        return self.initial
    
    def get_last_name(self):
        return self.last_name
    
    def get_full_name(self):
        return f"{self.first_name} {self.initial}. {self.last_name}"


class SalaryEmployee(Employee):
    """Salary employee receives fixed monthly salary"""
    
    def __init__(self, first_name, initial, last_name, monthly_salary):
        super().__init__(first_name, initial, last_name)
        self.monthly_salary = monthly_salary
    
    def get_annual_salary(self):
        return self.monthly_salary * 12
    
    def display_info(self):
        print(f"Salary Employee: {self.get_full_name()}")
        print(f"Monthly Salary: ${self.monthly_salary:,.2f}")
        print(f"Annual Salary: ${self.get_annual_salary():,.2f}")


class HourlyEmployee(Employee):
    """Hourly employee receives wages based on hours worked"""
    
    def __init__(self, first_name, initial, last_name, hourly_rate, hours_worked):
        super().__init__(first_name, initial, last_name)
        self.hourly_rate = hourly_rate
        self.hours_worked = hours_worked
    
    def get_wages(self):
        return self.hourly_rate * self.hours_worked
    
    def display_info(self):
        print(f"Hourly Employee: {self.get_full_name()}")
        print(f"Hourly Rate: ${self.hourly_rate:.2f}")
        print(f"Hours Worked: {self.hours_worked}")
        print(f"Total Wages: ${self.get_wages():,.2f}")


# Test application for polymorphism
if __name__ == "__main__":
    print("=== Employee Information ===\n")
    
    # Create salary employee
    salary_emp = SalaryEmployee("John", "A", "Smith", 5000.0)
    salary_emp.display_info()
    
    print()
    
    # Create hourly employee
    hourly_emp = HourlyEmployee("Jane", "B", "Doe", 25.0, 160)
    hourly_emp.display_info()
    
    # Demonstrate polymorphism
    print("\n=== Polymorphism Demo ===")
    employees = [salary_emp, hourly_emp]
    
    for emp in employees:
        print(f"Employee: {emp.get_full_name()}")
    
    print("\n=== Calling display_info polymorphically ===")
    for emp in employees:
        print()
        emp.display_info()