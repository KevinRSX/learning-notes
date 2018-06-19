/*shallow copy:
only copy the non-static members of an instance,
pointers will point to the same piece of memory
problem: the destructor may delete the memory twice or more*/

/*copy constructor:
Class_name(const Class_name &); //shallow copy*/

/*assignment operator:
Class_name & Class_name::operator=(const Class_name &);	//also shallow copy*/

//when initializing an instance, the copy constructor will always be invoked
//when assigning an instance, the assignment constructor will always be invoked