
Currently I have been writing the methods for the individual classes and trying to figure out the relationship among the different classes. I will list the concerns that came up throughout the night. These concerns will have a tag that to indicate where/what file i meant within the code. just [ctrl + f] for the comment tag.

Concerns:

| Tag | Comment/Concern |
| ------ |:------------------------------------------------------------------ |
| [a] | **city.h/sim.h** : Should the adjMatrix be shared (the same) among all the cities? Should the simulator update/maintain the matrix completely? I wrote down a method of updating the distance between two cities within **city.h**, but I think it would easiest if the simulator knows what the adjacent matrix and set the matrix upon the construction of the city instances. |
| [b] | **city.h** : I dont know if we should worry about appending a new city to the adjMatrix. I was thinking it would involve going through each vector of vector and appending the new city from an array of calculated distances. But i think we shouldnt worry about increasing the cities/users during runtime. Maybe later?
| [c] | **user.cpp/user.h** : lol forward declaration. Struggling how to return the ping for a user. The forward declarations with pointers is tripping me out and havent really gotten a change to really mess around with
| [d] | **sim.h** I placed the main function in sim.cpp to have some output.
| [e]| **user.h** I dont know how we're going to handle the user list that is within each user instance. How will we parse the "distanceTo" vector? What will happen as users are being removed from the list, people may be removed from the middle of the list. Would user class also have a sorting alroithm that makes sure that the first # people within the vector are the people with the least ping to? We would pop people off from the list? Dont really have anything in mind. 
