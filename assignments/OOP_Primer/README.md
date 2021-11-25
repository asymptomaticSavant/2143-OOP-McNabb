##A05-----------------------------------------------------------------------------------------------
    **Name:** Katherine C. McNabb
    **Date:** 11 Sep 2021
    **Class:** 2143 OOP
 
##Definitions--------------------------------------------------------------------------------------
   
    > **Abstraction**
        - One of the main concepts behind object-orientated programming. Refers to the design concept and ideology of hiding inner-workings of code and exposing only essential details; a matter of making a simplified exterior.
 
        - Often confuse-able with Encapsulation, and to be sure, the difference is blurry.
 
        - Examples:
            - An accessor/getter method in a class, used to access/modify private variables that are otherwise inaccessible.
           
            - Function definitions not explaining the process by which they go about achieving the ends of their operation, and
            just conveying what it requires to run (parameters), and what it returns/does.
 
            - U.I. in general! The mere concept of buttons.
 
    > **Attributes / Properties** 
        - ???
 
    > **Class**
        - A basic coding structure that can stand independently as its own block of code; can contain its own data members/variables and methods/functions.
 
        - Classes can be utilized in other code blocks by being established as objects, and calling upon their contents. An infinite amount of objects of a class can be made, and they are all independent; that is, unless the static keyword is used to label a variable or method, changing the contents of a variable of object 1 of a class would not affect the variable of object 2 of the same class.
 
        - By default, a class’s contents are set as private by default; public and protected keywords can be used to modify at will.

        <details><summary>CODE</summary>
        <p>


        ```r
            bool myClass(int parameter1, double parameter2)
            {
	            parameter1 = 0;  //can change
        	    parameter2 += 2; //or manipulate received parameters at will
	
	            return 1;        //one is a boolean value
            };
        ```

        </p>
        </details>

 
    > **Class Variable**
        - A variable/data member that's declared in a class, at a class level (aka, not in a smaller scope such as a for-loop).
 
        - Can be at a private, public, or protected level of access.
 
        - Can be labeled with the static keyword so that across all object declarations of a class, the contents of the class
        variable would remain the same.

        - Also known as class members or class instances.
                <details><summary>CODE</summary>
        <p>


        ```r
            bool myClass()
            {
                int classVariable = 1;

	            return 1;
            };
        ```

        </p>
        </details>
 
    > **Composition**
        - A way of structuring code, most easily defined in contrast to inheritance, another way to structure code.
        Objects and classes can be composed of other objects and classes; often described as a has-a relationship, where inheritance would be defined as a is-a relationship.
 
        - Composition is implemented by declaring objects in another class.
 
        - An example would be a deck of cards-- a deck **has** cards inside of it, aka is made of cards, instead of *being* a card, which would have made it more suited to an inheritance-based organization.
 
    > **Constructor**
        - A special method in a class that automatically runs when the class is called. Has the same name as the class.
 
        - There can be multiple overloaded constructors. The 'default' constructor with no parameters runs automatically, others will run upon being supplied with the proper parameters when the class is declared as an object.

        <p>


        ```r
            bool myClass()
            {
                myClass() //default constructor
                {
                    //...
                }

                myClass(int parameter1) //overloaded constructer
                {
                    //...
                }

	            return 1;
            };
        ```

        </p>
        </details>
 
    > **Encapsulation**
        - One of the main concepts behind object-orientated programming. Concerned with code on an implementation-based level, it's the ideology of rolling/compacting relevant code together, often so the innards(the tedious, complicated bits) are concealed.
 
        - Often confused with abstraction, and to be sure, the distinction is unclear.
 
        - The most immediate example would be classes; Relevant information packaged together, while packing away its innards.
 
    > **Friends**
        - A keyword used to label two classes or methods so that any private-level innards are accessible between the two.
       
        - There are arguments that this breaks OOP; ignore them.

        <p>


        ```r
        bool myClass()
        {
        	friend class mySecondClass;

        	return 1;  
        };

        bool mySecondClass()
        {
        	//...
        	return 1; 
        };
        ```

        </p>
        </details>

    > **Inheritance**
        - A way of structuring code; in which, one class 'inherits' another, giving it access to its innards.
 
        - Part of inheriting a class is declaring the level of access-- public, private, or protected, which alters what innards specifically it gets access to.
 
        - Inherited classes are referred to as base/parent classes, and inheritors are referred to as derived/children classes.
 
        - Inheritance is mainly done when one class is meant to be a more specific version of a base class (often defined as a is-a type relationship). For example, a base class of 'car', with a derived class of 'miata'; the parent class could have variables such as gas tank, mph, etc., which the child class could inherit, and modify to be more accurate to its specificity (a miata **is** a type of vehicle).
 
    > **Instance Variable**
        - A member variable that has a separate instance (copy) for every seperate object of the class it exists within.
 
    > **Member Variable**
        - A variable declared/instantiated and defined in a class.
 
    > **Method**
        - Also known as a function, an individual code block in a class that is meant to be called upon to execute a specific function (non-code/general definition) or return a specific value.
 
        - The first part of a function is labeling it's return value, which can be either 'void', or a variable type such as bool or int. This specifies what the function returns when called-- either nothing or the given variable type respectively.
 
        - The last part of a function is the parameters-- a list of variable types that is what is passed into the method when called.
 
        - See overloading; it's an important aspect. Also see constructor, a special type of method.
 
    > **Multiple Inheritance**
        - The act of inheriting from multiple classes in the same n^th class.
 
        - Can lead to priority issues, issues of calling the same class more than once, and general confusion (see the diamond problem for a notable example of multiple inheritance layout that leads to issues).
 
    > **Object**
        - A declaration of a class in a separate code block; the name of the game is object-orientated programming, and truly, so much revolves around the triviality of being able to manipulate classes in an one-by-one format.
 
        - Not wholly dissimilar to variables in some manners of usage, the difference being that they can contain so much more than a single value, seeing as they can contain an number of their own variables, in addition to methods.
 
    > **Overloading**
        - An act of, in the same scope, creating mutiple methods with the same name but with different parameter lists.
 
        - Used to compensate for handling multiple inputs that a code would want to handle.
 
        - Example: Overloading a square root method, so that one receives integers, and one receives doubles.
 
    > **Polymorphism**
        - One of the main concepts behind object-orientated programming. Refers to the concept of flexibility, and the ability for code to bend into different shapes and forms.
 
        - Deeply related with inheritance in particular, as inheritance is just taking one class and modifying and building on top of it for another class's more specific or differing purposes.
 
        - Examples such as overloading, overriding, and runtime polymorphism (the ability for the results of a program to be decided at runtime; overriding is a type of runtime polymorphism) abound.
 
    > **Public / Private / Protected**
        - Three keywords that determine the level of accessibility, used in a couple of different places, mainly to label
        different variables and methods inside classes.
       
        -   Using this as a example-- public sets the variable/method as accessible to anyone, private sets the variable/method
        as accessible only inside the class or to other classes using the friend keyword, and protected sets the variable/method as accessible only inside the class and to inheritors.
 
    > **Static**
        - A keyword that is used to label variables or methods, so that across all instances of themselves, their contents remain the same; if a variable is declared static in a class, and any object changes the value of that variable, printing the variable from any other object would print the changed value.
 
    > **Virtual**
        - A keyword used to label methods in classes, to tell the compiler that the methods labeled are meant to be overloaded(overwritten) in an inheriting(child/derived) class.
 
        - Virtual methods are often shells (a declaration without any implementation), or basic/generic versions of a method's action; often they serve a similar function as the base case in a switch case (a catch-all when a higher-priority, more specific/relevant option is not found).
 
        - In the case that virtual methods are the aforementioned shells without any implementation, they are coined 'pure virtual' methods, which makes the class that contains them a pure virtual class; such a class cannot be called as an object, and can only be inherited by other classes.