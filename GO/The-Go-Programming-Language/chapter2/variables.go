package main

import (
	"fmt"
	"reflect"
)

func main() {
	/*
			Variables are declared by
		var name type = expression

		the type can be omitted, and it'll be determined by its initial value

		the initial value can be omitted, and it'll be the zero value for it's type. If
		the variable is an aggregate one, it'll initialize every component of it with the zero value

		you CANNOT omit the expression and the type
	*/
	var s string
	fmt.Print(s)

	var a = "testing"
	fmt.Print(reflect.TypeOf(a))

	// you can have multiple variables being declared in a single declaration
	var n1, n2, n3 int = 3, 4, 5
	fmt.Printf("\n %d %d %d \n", n1, n2, n3)

	var var1, var2, var3 = 134.34, "test", false
	fmt.Printf("%f is %T \n %s is %T \n %t is %T \n",
		var1, var1, var2, var2, var3, var3)

	/*
				However, when there's no need to explicitly show the type, the short initialization is more used.
			Var declaration are more when it needs an explicit type that are different from its initial one.

		remember that = is assignment, := is declaration
	*/
	short1, short2, short3 := "string", 10, 4
	fmt.Printf("\n %s is %T \n %d is %T \n %d is %T \n",
		short1, short1, short2, short2, short3, short3)

	/*
		Pointers
	*/
	fmt.Println("\n Pointer section \n")
	x := 1
	p := &x
	fmt.Printf("%d", *p)
	*p = 3
	fmt.Printf("\n %d %d \b \n", *p, x)

	fmt.Println("Returning address:")
	var n = f()
	fmt.Printf("%d ", *n)

}

/*
Each call of f changes the address,  once it creates a new variable
*/
func f() *int {
	v := 1
	return &v
}
