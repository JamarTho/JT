# Object-Oriented Programming (OOP) Primer

## Table of Contents

1. [Abstract Classes and Interfaces](#abstract-classes-and-interfaces)  
2. [Abstraction](#abstraction)  
3. [Access Modifiers (Public, Private, Protected)](#access-modifiers-public-private-protected)  
4. [Attributes / Properties](#attributes-properties)  
5. [Class Variable](#class-variable)  
6. [Classes and Objects](#classes-and-objects)  
7. [Collections and Iterators](#collections-and-iterators)  
8. [Composition](#composition)  
9. [Constructors and Destructors](#constructors-and-destructors)  
10. [Design Patterns](#design-patterns)  
11. [Encapsulation](#encapsulation)  
12. [Exception Handling](#exception-handling)  
13. [File I/O in OOP](#file-io-in-oop)  
14. [Friends](#friends)  
15. [Generics and Templates](#generics-and-templates)  
16. [Inheritance](#inheritance)  
17. [Instance Variable](#instance-variable)  
18. [Member Variable](#member-variable)  
19. [Memory Management](#memory-management)  
20. [Method Overloading](#method-overloading)  
21. [Methods](#methods)  
22. [Multiple Inheritance](#multiple-inheritance)  
23. [Multithreading in OOP](#multithreading-in-oop)  
24. [Object Relationships](#object-relationships)  
25. [Object-Oriented Design Principles](#object-oriented-design-principles)  
26. [Operator Overloading](#operator-overloading)  
27. [Polymorphism](#polymorphism)  
28. [SOLID Principles](#solid-principles)  
29. [Static (Methods and Variables)](#static-methods-and-variables)  
30. [Testing in OOP](#testing-in-oop)  
31. [UML Diagrams and Modeling](#uml-diagrams-and-modeling)  
32. [Virtual](#virtual)

---

## Abstract Classes and Interfaces

### Definition

- **Abstract Classes**: Classes that cannot be instantiated and are designed to be extended by subclasses. They can have both defined and abstract methods.  
- **Interfaces**: Purely abstract classes that define a set of methods without implementations.

### Example (C++):

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() = 0; // Pure virtual function
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Woof!" << endl;
    }
};

int main() {
    Dog myDog;
    myDog.speak(); // Output: Woof!
    return 0;
}
```

---

## Abstraction

### Definition

- The process of hiding implementation details and exposing only the necessary functionality.

### Example (C++):

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
};

int main() {
    Shape* shape = new Circle();
    shape->draw(); // Output: Drawing a circle
    delete shape;
    return 0;
}
```

---

## Access Modifiers (Public, Private, Protected)

### Definition

- **Public**: Accessible from anywhere.  
- **Private**: Accessible only within the class.  
- **Protected**: Accessible within the class and its subclasses.

### Example (C++):

```cpp
#include <iostream>
using namespace std;

class Example {
public:
    string publicVar = "I am public";
protected:
    string protectedVar = "I am protected";
private:
    string privateVar = "I am private";

public:
    void showPrivate() {
        cout << privateVar << endl;
    }
};

int main() {
    Example example;
    cout << example.publicVar << endl;       // Accessible
    // cout << example.protectedVar << endl; // Not accessible
    // cout << example.privateVar << endl;   // Not accessible
    example.showPrivate();                   // Output: I am private
    return 0;
}
```

---

## Attributes / Properties

### Definition

- **Attributes**: Variables that store object state.  
- **Properties**: Controlled access to attributes using getter and setter methods.

### Example (C++):

```cpp
#include <iostream>
using namespace std;

class Example {
private:
    int value;

public:
    int getValue() {
        return value;
    }

    void setValue(int val) {
        if (val >= 0) {
            value = val;
        } else {
            throw invalid_argument("Value must be non-negative");
        }
    }
};

int main() {
    Example example;
    example.setValue(42);
    cout << example.getValue() << endl; // Output: 42
    return 0;
}
```

---

## Class Variable

### Definition

- Shared variables across all instances of a class.

### Example (C++):

```cpp
#include <iostream>
using namespace std;

class Example {
public:
    static int sharedVar;
};

int Example::sharedVar = 42;

int main() {
    Example example1;
    Example example2;
    cout << Example::sharedVar << endl; // Output: 42
    Example::sharedVar = 100;
    cout << Example::sharedVar << endl; // Output: 100
    return 0;
}
```

---

## Classes and Objects

### Definition

- **Classes**: Blueprints for creating objects.  
- **Objects**: Instances of classes.

### Example (C++):

```cpp
#include <iostream>
using namespace std;

class Dog {
private:
    string name;

public:
    Dog(string n) : name(n) {}

    void bark() {
        cout << name << " says Woof!" << endl;
    }
};

int main() {
    Dog myDog("Rex");
    myDog.bark(); // Output: Rex says Woof!
    return 0;
}
```

---

## Collections and Iterators

### Definition

- **Collections**: Data structures like arrays, vectors, maps.  
- **Iterators**: Objects that allow sequential traversal of collections.

### Example (C++):

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> myVector = {1, 2, 3};
    for (auto it = myVector.begin(); it != myVector.end(); ++it) {
        cout << *it << " ";
    }
    // Output: 1 2 3
    return 0;
}
```

---

## Composition

### Definition

- A "has-a" relationship between objects.

### Example (C++):

```cpp
#include <iostream>
using namespace std;

class Engine {
public:
    string start() {
        return "Engine started";
    }
};

class Car {
private:
    Engine engine;

public:
    string drive() {
        return engine.start() + " and car is moving";
    }
};

int main() {
    Car myCar;
    cout << myCar.drive() << endl; // Output: Engine started and car is moving
    return 0;
}
```

---

## Constructors and Destructors

### Definition

- **Constructors**: Methods called when an object is created.  
- **Destructors**: Methods called when an object is destroyed.

### Example (C++):

```cpp
#include <iostream>
using namespace std;

class Example {
public:
    Example() {
        cout << "Constructor called" << endl;
    }

    ~Example() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    Example example; // Output: Constructor called
    // Destructor will be called automatically at the end of scope
    return 0;
}
```

---

## Design Patterns

### Definition

- Reusable solutions to common software design problems (e.g., Singleton, Factory).

---

## Encapsulation

### Definition

- Bundling data and methods to restrict direct access to some of an object’s components.

---

## Exception Handling

### Definition

- Mechanism to handle runtime errors gracefully.

---

## File I/O in OOP

### Definition

- Reading from and writing to files using object-oriented paradigms.

---

## Friends

### Definition

- Functions or classes declared with access to private members of another class.

---

## Generics and Templates

### Definition

- Constructs to write type-independent code.

---

## Inheritance

### Definition

- Mechanism where a class derives properties and behavior from another class.

---

## Instance Variable

### Definition

- A variable unique to each instance of a class.

---

## Member Variable

### Definition

- A variable that is a member of a class.

---

## Memory Management

### Definition

- Techniques to allocate and free memory (e.g., garbage collection, pointers).

---

## Method Overloading

### Definition

- Defining multiple methods with the same name but different parameter lists.

---

## Methods

### Definition

- Functions defined inside a class to perform operations on its attributes.

---

## Multiple Inheritance

### Definition

- A class inheriting from more than one base class.

---

## Multithreading in OOP

### Definition

- Running multiple threads within an object-oriented design.

---

## Object Relationships

### Definition

- Types of relationships between objects (association, aggregation, composition).

---

## Object-Oriented Design Principles

### Definition

- Guidelines like DRY, SOLID, and GRASP for creating effective OOP designs.

---

## Operator Overloading

### Definition

- Defining custom behavior for standard operators for user-defined types.

---

## Polymorphism

### Definition

- The ability to process objects differently based on their runtime type.

---

## SOLID Principles

### Definition

- Five principles (Single Responsibility, Open/Closed, Liskov Substitution, Interface Segregation, Dependency Inversion) for good object-oriented design.

---

## Static (Methods and Variables)

### Definition

- Members belonging to the class rather than any object instance.

---

## Testing in OOP

### Definition

- Techniques like unit testing and test-driven development to ensure code reliability.

---

## UML Diagrams and Modeling

### Definition

- Graphical representation of an object-oriented system’s structure and behavior.

---

## Virtual

### Definition

- A keyword indicating that a method can be overridden in a derived class.

