## 📁 Exercises

### Ex00: Bureaucrat Class
This exercise introduces the `Bureaucrat` class with basic functionality, including attributes and member functions related to the bureaucrat's grade and actions. It demonstrates basic class creation and encapsulation principles.

```
Files:
├── ex00/Bureaucrat.cpp
├── ex00/Bureaucrat.hpp
├── ex00/Makefile
├── ex00/main.cpp
```

### Ex01: Form and Bureaucrat Interaction
This exercise builds on Ex00 by introducing the `Form` class, which interacts with the `Bureaucrat`. The bureaucrat can sign or execute forms based on his grade. This extends the concept of validation and error handling.

```
Files:
├── ex01/Bureaucrat.cpp
├── ex01/Bureaucrat.hpp
├── ex01/Form.cpp
├── ex01/Form.hpp
├── ex01/Makefile
├── ex01/main.cpp
```

### Ex02: Handling Forms: Robotomy, Shrubbery, and Presidential Pardon
In Ex02, we expand the functionality with multiple types of forms (`RobotomyRequestForm`, `ShrubberyCreationForm`, and `PresidentialPardonForm`). Each form implements specific actions, and the `Bureaucrat` can sign them based on grade requirements.

```
Files:
├── ex02/AForm.cpp
├── ex02/AForm.hpp
├── ex02/Bureaucrat.cpp
├── ex02/Bureaucrat.hpp
├── ex02/Makefile
├── ex02/PresidentialPardonForm.cpp
├── ex02/PresidentialPardonForm.hpp
├── ex02/RobotomyRequestForm.cpp
├── ex02/RobotomyRequestForm.hpp
├── ex02/ShrubberyCreationForm.cpp
├── ex02/ShrubberyCreationForm.hpp
├── ex02/main.cpp
```

### Ex03: Intern and Form Creation
Ex03 introduces an `Intern` class that can create different forms based on the requested type. This further extends the system by automating form creation, making the system more flexible and dynamic.

```
Files:
├── ex03/AForm.cpp
├── ex03/AForm.hpp
├── ex03/Bureaucrat.cpp
├── ex03/Bureaucrat.hpp
├── ex03/Intern.cpp
├── ex03/Intern.hpp
├── ex03/PresidentialPardonForm.cpp
├── ex03/PresidentialPardonForm.hpp
├── ex03/RobotomyRequestForm.cpp
├── ex03/RobotomyRequestForm.hpp
├── ex03/ShrubberyCreationForm.cpp
├── ex03/ShrubberyCreationForm.hpp
├── ex03/Makefile
├── ex03/main.cpp
```

## 🤖 Class Features

### Bureaucrat
```cpp
class Bureaucrat {
private:
    std::string name;
    int grade;

public:
    Bureaucrat(std::string const &name, int grade);
    void incrementGrade();
    void decrementGrade();
    std::string getName() const;
    int getGrade() const;
    void signForm(Form &form);
    void executeForm(Form const &form);
    ~Bureaucrat();
};
```

### Form
```cpp
class Form {
private:
    std::string name;
    bool isSigned;
    int signGrade;
    int executeGrade;

public:
    Form(std::string const &name, int signGrade, int executeGrade);
    bool isSigned() const;
    void beSigned(Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;
    virtual ~Form();
};
```

### RobotomyRequestForm
```cpp
class RobotomyRequestForm : public AForm {
public:
    void execute(Bureaucrat const &executor) const override;
    // RobotomyRequestForm-specific features
};
```

### ShrubberyCreationForm
```cpp
class ShrubberyCreationForm : public AForm {
public:
    void execute(Bureaucrat const &executor) const override;
    // ShrubberyCreationForm-specific features
};
```

### PresidentialPardonForm
```cpp
class PresidentialPardonForm : public AForm {
public:
    void execute(Bureaucrat const &executor) const override;
    // PresidentialPardonForm-specific features
};
```

### Intern
```cpp
class Intern {
public:
    AForm* makeForm(std::string const &formName, std::string const &target);
};
```

## 🎯 Learning Objectives

1. **Class Hierarchy and Inheritance**
   - Proper use of inheritance with classes like `Form`, `Bureaucrat`, and their interactions.

2. **Encapsulation**
   - Managing access to class members using private and public access specifiers.

3. **Polymorphism**
   - Abstracting form classes (`AForm`) and implementing dynamic behavior via method overriding.

4. **Error Handling and Validation**
   - Implementing grade validation for forms and error handling when attempting to sign or execute forms.

5. **Creating and Managing Objects**
   - Use of constructors and destructors for proper object creation and cleanup, especially with dynamic memory.

## 🛠️ Implementation Requirements

- **Orthodox Canonical Form**: Ensure proper constructors, destructors, and copy constructors/assignment operators are defined.
- **Virtual Destructors**: Ensure base classes have virtual destructors for proper memory management.
- **Memory Leak Prevention**: Proper management of resources and objects.
- **Access Control**: Use appropriate access specifiers to protect internal states.
- **Naming Conventions**: Follow clear and consistent naming conventions across all files.

## 🧪 Testing Guidelines

### Ex00: Bureaucrat
```cpp
Bureaucrat john("John", 50);
std::cout << john.getName() << " has grade " << john.getGrade() << std::endl;
```

### Ex01: Bureaucrat and Form Interaction
```cpp
Bureaucrat bob("Bob", 25);
Form form("Important Form", 30, 20);
bob.signForm(form);  // Bob signs the form
```

### Ex02: Working with Forms
```cpp
RobotomyRequestForm robotomyForm("Robot");
Bureaucrat mike("Mike", 30);
mike.executeForm(robotomyForm);  // Test execution of Robotomy request form
```

### Ex03: Intern Creates Forms
```cpp
Intern intern;
AForm *form1 = intern.makeForm("ShrubberyCreationForm", "Garden");
form1->execute(bureaucrat);  // Test form creation and execution by intern
```

## ⚠️ Common Issues to Watch

1. **Memory Management**:
   - Ensure objects are properly cleaned up.
   - Avoid memory leaks and dangling pointers.

2. **Virtual Methods**:
   - Ensure the correct method is invoked when polymorphism is used.

3. **Grade Validation**:
   - Ensure grade validation is correctly handled for signing and executing forms.

## 📝 Style Requirements

- Consistent and descriptive class names
- Proper indentation and comments
- Well-structured header and source files
- Clear, readable, and self-documenting code

## 🔍 Debugging Tips

1. **Check Inheritance**:
   - Ensure that virtual methods are correctly overridden.

2. **Memory Leaks**:
   - Use tools like Valgrind to detect memory issues.

3. **Debugging Forms**:
   - Print or log messages when forms are signed or executed to verify proper function.

## 📜 License

This project is part of the 42 curriculum and is provided as-is.
