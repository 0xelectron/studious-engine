var pets = ['cat', 'dog', 'rat'];

// for (var i = 0; i < pets.length; ++i)
//     pets[i] += 's';

pets = pets.map((pet) => pet += 's');

console.log(pets);