package main

import (
	"fmt"
	"os"
)

/*
	Type declarations: used like a typedef in c.

Even tho color and name are both string, they're considered different types thus cannot be
compared or combined in a trivial way. However, two types have the same underlying type
they can be converted to each other. In this example, color can be converted to name.

The types support the same operations the underlying type supports and supports user defined
operations for them.

The type declarations are helpful when it's used to simplify the declaration of variables that uses
complex types.
*/
type color string
type name string

func main() {

	/*
			Tuple assigment: allows several variables to be assigned at once.
		Look at the  gcd
	*/

	fmt.Println(gcd(10, 5))
	x, y := 9, 8
	// swapping the values by using the tuple assigment. The right side does not change, so there's no need
	// for having a dummy variable storing an old value

	x, y = y, x
	fmt.Printf("%d %d ", x, y)

	s, _ := os.Open("file.txt") // we can  discard unwanted values by using the blank identifier
	s.Close()

	const first name = "joel"
	const tshirt color = "blue"

}

func gcd(x, y int) int {
	for y != 0 {
		x, y = y, x%y
	}
	return x
}
